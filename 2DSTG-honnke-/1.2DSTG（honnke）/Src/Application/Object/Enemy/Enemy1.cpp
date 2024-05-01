#include"../../Scene.h"
#include "Enemy1.h"
#include "../Bullet/EnemyBullet.h"


void Enemy1::Update()
{
	m_pos += m_move;

	angle += 1.0f;
	if (angle >= 360)
	{
		angle -= 360;
	}
	m_pos.x = sin(DirectX::XMConvertToRadians(angle)) * 300;

	if (m_pos.y < -400)m_aliveFlg = false;
	
	//�e����
	//if (m_aliveFlg)
	//{
	//	if (shotWait < 0)
	//	{
	//		//�e1���̃C���X�^���X�̐��������������ă��X�g�ɒǉ�
	//		std::shared_ptr<EnemyBullet>enemybullet;
	//		enemybullet = std::make_shared<EnemyBullet>();

	//		enemybullet->Init();			//������
	//		enemybullet->SetPos(m_pos);		//���ˈʒu���������W
	//		enemybullet->SetOwner(m_owner);	//�I�[�i�[��n���Ă���
	//		shotWait = 20;

	//		m_owner->AddObject(enemybullet);//���X�g��ǉ�
	//	}
	//}
	//shotWait--;

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos.x,m_pos.y,0);
	m_mat = transMat;
}

void Enemy1::Draw()
{
	Math::Rectangle rc;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	rc = { 0,0,64,64 };
	SHADER.m_spriteShader.DrawTex(&m_tex, 0, 0, 64, 64, &rc);
}

void Enemy1::Init()
{
	m_tex.Load("Texture/enemy.png");
	m_pos = {};						//0,0�ŏ�����
	m_mat = Math::Matrix::Identity;	//�P�ʍs��ŏ�����   Identity=�P�ʍs��
	m_objType = ObjectType::Enemy1;
	m_move = { 0.0f,-2.0f,0.0f };
	shotWait = 20;
}

void Enemy1::Release()
{
}

void Enemy1::Hit()
{
	m_aliveFlg = false;
}
