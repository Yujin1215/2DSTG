#include"../../Scene.h"
#include "Enemybullet.h"

void EnemyBullet::Update()
{
	m_pos += m_movePow;

	if (m_pos.y > 360)
	{
		m_aliveFlg = false;
	}
	//�G�ƒe�̓����蔻��
	for (auto& obj : m_owner->GetObjList())
	{
		//�e�ƃv���C���[�Ƃ͓����蔻�肵�Ȃ�
		if (obj->GetObjType() == ObjectType::Bullet)continue;
		if (obj->GetObjType() == ObjectType::Player)continue;

		//�G�������瓖���蔻����s��
		if (obj->GetObjType() == ObjectType::Enemy || obj->GetObjType() == ObjectType::Enemy1)
		{
			//�Ώۍ��W-�e���W���Ώۂ̃x�N�g��
			Math::Vector3 v;
			v = obj->GetPos() - m_pos;

			//������E�E�E�x�N�g���̒����Ŕ���
			if (v.Length() < 32.0f)
			{
				//Hit���̏������s��
				obj->Hit();

				//�e��Hit�����Ƃ��̏������s��
				Hit();
				break;
			}
		}
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void EnemyBullet::Draw()
{
	Math::Rectangle rc;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	rc = { 0,0,16,16 };
	SHADER.m_spriteShader.DrawTex(&m_tex, 0, 0, 16, 16, &rc);
}

void EnemyBullet::Init()
{
	m_tex.Load("Texture/bullet.png");
	m_pos = {};						//0,0�ŏ�����
	m_mat = Math::Matrix::Identity;	//�P�ʍs��ŏ�����   Identity=�P�ʍs��
	m_objType = ObjectType::Bullet;	//��ނ͒e
	m_movePow = { 0.0f,-10.0f,0.0f };//�ړ��ʏ�����
}

void EnemyBullet::Release()
{
}

void EnemyBullet::Hit()
{
	m_aliveFlg = false;
}
