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
	
	//弾発射
	//if (m_aliveFlg)
	//{
	//	if (shotWait < 0)
	//	{
	//		//弾1個分のインスタンスの生成＆初期化してリストに追加
	//		std::shared_ptr<EnemyBullet>enemybullet;
	//		enemybullet = std::make_shared<EnemyBullet>();

	//		enemybullet->Init();			//初期化
	//		enemybullet->SetPos(m_pos);		//発射位置＝自動座標
	//		enemybullet->SetOwner(m_owner);	//オーナーを渡しておく
	//		shotWait = 20;

	//		m_owner->AddObject(enemybullet);//リストを追加
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
	m_pos = {};						//0,0で初期化
	m_mat = Math::Matrix::Identity;	//単位行列で初期化   Identity=単位行列
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
