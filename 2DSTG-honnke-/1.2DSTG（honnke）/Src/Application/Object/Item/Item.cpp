#include"../../Scene.h"
#include "Item.h"

void Item::Update()
{
	m_pos += m_move;

	if (m_pos.x < -640)m_aliveFlg = false;

	//“G‚Æ’e‚Ì“–‚½‚è”»’è
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
	m_pos = {};						//0,0‚Å‰Šú‰»
	m_mat = Math::Matrix::Identity;	//’PˆÊs—ñ‚Å‰Šú‰»   Identity=’PˆÊs—ñ
	
	m_objType = ObjectType::Item;	//í—Ş‚Í’e
	m_move = { -5.0f,0.0f,0.0f };//ˆÚ“®—Ê‰Šú‰»
}

void Item::Release()
{
}

void Item::Hit()
{
	m_aliveFlg = false;
}

