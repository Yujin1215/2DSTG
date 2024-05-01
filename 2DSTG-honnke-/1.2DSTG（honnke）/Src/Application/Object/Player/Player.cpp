#include "Player.h"
#include"../../Scene.h"
#include"../Bullet/Bullet.h"
void Player::Update()
{
	if (GetAsyncKeyState('W') & 0x8000)m_pos.y += 5;
	if (GetAsyncKeyState('S') & 0x8000)m_pos.y -= 5;
	if (GetAsyncKeyState('A') & 0x8000)m_pos.x -= 5;
	if (GetAsyncKeyState('D') & 0x8000)m_pos.x += 5;

	//�e����
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{	
		if (shotWait < 0)
		{
			//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
			std::shared_ptr<Bullet>bullet;
			bullet = std::make_shared<Bullet>();

			bullet->Init();				//������
			bullet->SetPos(m_pos);		//���ˈʒu���������W
			bullet->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
			shotWait = 10;

			m_owner->AddObject(bullet);//���X�g��ǉ�
		}
	}

	shotWait--;


	//============================================================
	//�v���C���[�ƓG�̓����蔻��E�E�E�G�̏�񂪕K�v
	//�I�u�W�F�N�g���X�g�����ׂČ��Ă���
	for (auto& obj : m_owner->GetObjList())
	{
		//�������g�Ƃ͓����蔻�肵�Ȃ�
		if (obj->GetObjType() == ObjectType::Player)continue;

		//�G�������瓖���蔻����s��
		if (obj->GetObjType() == ObjectType::Enemy|| obj->GetObjType() == ObjectType::Enemy1)
		{
			//�Ώۍ��W-�������W���Ώۂ̃x�N�g��
			Math::Vector3 v;
			v = obj->GetPos() - m_pos;

			//������E�E�E�x�N�g���̒����Ŕ���
			if (v.Length() < 64.0f)
			{
				//Hit���̏������s��
				obj->Hit();
				Hit();
				break;
			}
		}
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Player::Draw()
{
	Math::Rectangle rc;
	SHADER.m_spriteShader.SetMatrix(m_mat);

	rc = { 0,0,64,64 };
	SHADER.m_spriteShader.DrawTex(&m_tex, 0, 0, 64, 64, &rc);
}

void Player::Init()
{
	m_tex.Load("Texture/player.png");
	m_pos = {};						//0,0�ŏ�����
	m_mat = Math::Matrix::Identity;	//�P�ʍs��ŏ�����   Identity=�P�ʍs��
	m_objType = ObjectType::Player;
}

void Player::Release()
{
}
