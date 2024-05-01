#include "Player.h"
#include"../../Scene.h"
#include"../Bullet/Bullet.h"
void Player::Update()
{
	if (GetAsyncKeyState('W') & 0x8000)m_pos.y += 5;
	if (GetAsyncKeyState('S') & 0x8000)m_pos.y -= 5;
	if (GetAsyncKeyState('A') & 0x8000)m_pos.x -= 5;
	if (GetAsyncKeyState('D') & 0x8000)m_pos.x += 5;

	//弾発射
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{	
		if (shotWait < 0)
		{
			//弾1個分のインスタンスの生成＆初期化してリストに追加
			std::shared_ptr<Bullet>bullet;
			bullet = std::make_shared<Bullet>();

			bullet->Init();				//初期化
			bullet->SetPos(m_pos);		//発射位置＝自動座標
			bullet->SetOwner(m_owner);	//オーナーを渡しておく
			shotWait = 10;

			m_owner->AddObject(bullet);//リストを追加
		}
	}

	shotWait--;


	//============================================================
	//プレイヤーと敵の当たり判定・・・敵の情報が必要
	//オブジェクトリストをすべて見ていく
	for (auto& obj : m_owner->GetObjList())
	{
		//自分自身とは当たり判定しない
		if (obj->GetObjType() == ObjectType::Player)continue;

		//敵だったら当たり判定を行う
		if (obj->GetObjType() == ObjectType::Enemy|| obj->GetObjType() == ObjectType::Enemy1)
		{
			//対象座標-自分座標＝対象のベクトル
			Math::Vector3 v;
			v = obj->GetPos() - m_pos;

			//球判定・・・ベクトルの長さで判定
			if (v.Length() < 64.0f)
			{
				//Hit時の処理を行う
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
	m_pos = {};						//0,0で初期化
	m_mat = Math::Matrix::Identity;	//単位行列で初期化   Identity=単位行列
	m_objType = ObjectType::Player;
}

void Player::Release()
{
}
