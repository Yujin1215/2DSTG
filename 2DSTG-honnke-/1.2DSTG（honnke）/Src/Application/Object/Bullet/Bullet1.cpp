#include"../../Scene.h"
#include "Bullet1.h"
#include "../Item/Item.h"

void Bullet1::Update()
{
	g += 0.1;
	m_pos.y += 5;
	m_pos.y -= g;
	m_pos += m_move;

	if (m_pos.x > 640)m_aliveFlg = false;

	//�G�ƒe�̓����蔻��
	for (auto& obj : m_owner->GetObjList())
	{
		if (obj->GetObjType() == ObjectType::Bullet)continue;
		if (obj->GetObjType() == ObjectType::Player)continue;

		if (obj->GetObjType() == ObjectType::Enemy || obj->GetObjType() == ObjectType::Enemy1 || obj->GetObjType() == ObjectType::Enemy2)
		{
			Math::Vector3 v;
			v = obj->GetPos() - m_pos;

			if (v.Length() < 32.0f)
			{
				obj->Hit();
				Hit();

				if (rand() % 100 < 10.0)
				{
					std::shared_ptr<Item>item = std::make_shared<Item>();

					int moveY = 0;
					moveY = rand() % 5 + 1;
					moveY *= -1;

					int moveX = 0;
					moveX = rand() % 5 + 1;
					moveX *= -1;

					item->Init();
					item->SetPos(600, rand() % 720 - 360);
					item->SetMove({ -5.0f, 0.0f,  0.0f });
					item->SetOwner(m_owner);

					m_owner->AddObject(item);//���X�g��ǉ�
				}
				break;
			}
		}
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Bullet1::Draw()
{
	Math::Rectangle rc;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	rc = { 0,0,16,16 };
	SHADER.m_spriteShader.DrawTex(&m_tex, 0, 0, 16, 16, &rc);
}

void Bullet1::Init()
{
	m_tex.Load("Texture/bullet.png");
	m_pos = {};						//0,0�ŏ�����
	m_mat = Math::Matrix::Identity;	//�P�ʍs��ŏ�����   Identity=�P�ʍs��
	m_objType = ObjectType::Bullet;	//��ނ͒e
	m_move= { 10.0f,0.0f,0.0f };//�ړ��ʏ�����
}

void Bullet1::Release(){}

void Bullet1::Hit()
{
	m_aliveFlg = false;
}
