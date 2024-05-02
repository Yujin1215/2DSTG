#include"../../Scene.h"
#include "Item.h"

void Item::Update()
{
	m_pos += m_move;

	if (m_pos.x < -640)m_aliveFlg = false;

	//�G�ƒe�̓����蔻��
	for (auto& obj : m_owner->GetObjList())
	{

		if (obj->GetObjType() == ObjectType::Player)
		{
			Math::Vector3 v;
			v = obj->GetPos() - m_pos;

			if (v.Length() < 32.0f)
			{
				obj->Up();

				Hit();
				break;
			}
		}
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Item::Draw()
{
	Math::Rectangle rc;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	rc = { 16,16,32,16 };
	SHADER.m_spriteShader.DrawTex(&m_tex, 16, 16, 32, 16, &rc);
}

void Item::Init()
{
	m_tex.Load("Texture/bullet.png");
	m_pos = {};						//0,0�ŏ�����
	m_mat = Math::Matrix::Identity;	//�P�ʍs��ŏ�����   Identity=�P�ʍs��
	
	m_objType = ObjectType::Item;	//��ނ͒e
	m_move = { -5.0f,0.0f,0.0f };//�ړ��ʏ�����
}

void Item::Release()
{
}

void Item::Hit()
{
	m_aliveFlg = false;
}

