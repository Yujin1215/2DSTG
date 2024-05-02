#include "Player.h"
#include"../../Scene.h"
#include"../Bullet/Bullet0.h"
#include"../Bullet/Bullet1.h"
#include"../Bullet/Bullet2A.h"
#include"../Bullet/Bullet2B.h"
#include"../Bullet/Bullet3.h"
#include "../Item/Item.h"

void Player::Update()
{
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_pos.y += m_move.y;
		if (m_pos.y > (360))m_pos.y = (360);
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_pos.y -= m_move.y;
		if (m_pos.y < -(360))m_pos.y = -(360);
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_pos.x -= m_move.x;
		if (m_pos.x < -(640))m_pos.x = -(640);
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pos.x += m_move.x;
		if (m_pos.x > (640))m_pos.x = (640);
	}

	//�e����
	if(m_upFlg==0)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet0>bullet0;
				bullet0 = std::make_shared<Bullet0>();

				bullet0->Init();				//������
				bullet0->SetPos(m_pos);		//���ˈʒu���������W
				bullet0->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 10;

				m_owner->AddObject(bullet0);//���X�g��ǉ�
			}
		}
	}
	else if (m_upFlg == 1)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet1>bullet1;
				bullet1 = std::make_shared<Bullet1>();

				bullet1->Init();				//������
				bullet1->SetPos(m_pos);		//���ˈʒu���������W
				bullet1->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 10;

				m_owner->AddObject(bullet1);//���X�g��ǉ�
			}
		}
	}
	else if (m_upFlg == 2)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet1>bullet1;
				bullet1 = std::make_shared<Bullet1>();

				bullet1->Init();				//������
				bullet1->SetPos(m_pos);		//���ˈʒu���������W
				bullet1->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 5;

				m_owner->AddObject(bullet1);//���X�g��ǉ�
			}
		}
	}
	else if (m_upFlg == 3)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet2A>bullet2A;
				bullet2A = std::make_shared<Bullet2A>();

				bullet2A->Init();				//������
				bullet2A->SetPos(m_pos.x,m_pos.y+4);		//���ˈʒu���������W
				bullet2A->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 10;

				m_owner->AddObject(bullet2A);//���X�g��ǉ�


				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet2B>bullet2B;
				bullet2B = std::make_shared<Bullet2B>();

				bullet2B->Init();				//������
				bullet2B->SetPos(m_pos.x,m_pos.y-4);		//���ˈʒu���������W
				bullet2B->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 10;

				m_owner->AddObject(bullet2B);//���X�g��ǉ�
			}
		}
	}
	else if (m_upFlg == 4)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet2A>bullet2A;
				bullet2A = std::make_shared<Bullet2A>();

				bullet2A->Init();				//������
				bullet2A->SetPos(m_pos.x, m_pos.y + 4);		//���ˈʒu���������W
				bullet2A->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 5;

				m_owner->AddObject(bullet2A);//���X�g��ǉ�


				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet2B>bullet2B;
				bullet2B = std::make_shared<Bullet2B>();

				bullet2B->Init();				//������
				bullet2B->SetPos(m_pos.x, m_pos.y - 4);		//���ˈʒu���������W
				bullet2B->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 5;

				m_owner->AddObject(bullet2B);//���X�g��ǉ�
			}
		}
	}
	else if (m_upFlg==5)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet3>bullet3;
				bullet3 = std::make_shared<Bullet3>();

				bullet3->Init();				//������
				bullet3->SetPos(m_pos);		//���ˈʒu���������W
				bullet3->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 20;

				m_owner->AddObject(bullet3);//���X�g��ǉ�
			}
		}
	}
	else if (m_upFlg == 6)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet3>bullet3;
				bullet3 = std::make_shared<Bullet3>();

				bullet3->Init();				//������
				bullet3->SetPos(m_pos);		//���ˈʒu���������W
				bullet3->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 10;

				m_owner->AddObject(bullet3);//���X�g��ǉ�
			}
		}
	}
	else if (m_upFlg >= 7)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
				std::shared_ptr<Bullet3>bullet3;
				bullet3 = std::make_shared<Bullet3>();

				bullet3->Init();				//������
				bullet3->SetPos(m_pos);		//���ˈʒu���������W
				bullet3->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
				shotWait = 5;

				m_owner->AddObject(bullet3);//���X�g��ǉ�
			}
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
		if (obj->GetObjType() == ObjectType::Enemy|| obj->GetObjType() == ObjectType::Enemy1 || obj->GetObjType() == ObjectType::Enemy2)
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

void Player::Release(){}
