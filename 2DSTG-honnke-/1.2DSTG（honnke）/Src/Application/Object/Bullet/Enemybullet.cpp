#include"../../Scene.h"
#include "Enemybullet.h"

void EnemyBullet::Update()
{
	m_pos += m_movePow;

	if (m_pos.y > 360)
	{
		m_aliveFlg = false;
	}
	//敵と弾の当たり判定
	for (auto& obj : m_owner->GetObjList())
	{
		//弾とプレイヤーとは当たり判定しない
		if (obj->GetObjType() == ObjectType::Bullet)continue;
		if (obj->GetObjType() == ObjectType::Player)continue;

		//敵だったら当たり判定を行う
		if (obj->GetObjType() == ObjectType::Enemy || obj->GetObjType() == ObjectType::Enemy1)
		{
			//対象座標-弾座標＝対象のベクトル
			Math::Vector3 v;
			v = obj->GetPos() - m_pos;

			//球判定・・・ベクトルの長さで判定
			if (v.Length() < 32.0f)
			{
				//Hit時の処理を行う
				obj->Hit();

				//弾もHitしたときの処理を行う
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
	m_pos = {};						//0,0で初期化
	m_mat = Math::Matrix::Identity;	//単位行列で初期化   Identity=単位行列
	m_objType = ObjectType::Bullet;	//種類は弾
	m_movePow = { 0.0f,-10.0f,0.0f };//移動量初期化
}

void EnemyBullet::Release()
{
}

void EnemyBullet::Hit()
{
	m_aliveFlg = false;
}
