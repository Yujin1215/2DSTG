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

	//弾発射
	if(m_upFlg==0)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet0>bullet0;
				bullet0 = std::make_shared<Bullet0>();

				bullet0->Init();				//初期化
				bullet0->SetPos(m_pos);		//発射位置＝自動座標
				bullet0->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 10;

				m_owner->AddObject(bullet0);//リストを追加
			}
		}
	}
	else if (m_upFlg == 1)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet1>bullet1;
				bullet1 = std::make_shared<Bullet1>();

				bullet1->Init();				//初期化
				bullet1->SetPos(m_pos);		//発射位置＝自動座標
				bullet1->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 10;

				m_owner->AddObject(bullet1);//リストを追加
			}
		}
	}
	else if (m_upFlg == 2)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet1>bullet1;
				bullet1 = std::make_shared<Bullet1>();

				bullet1->Init();				//初期化
				bullet1->SetPos(m_pos);		//発射位置＝自動座標
				bullet1->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 5;

				m_owner->AddObject(bullet1);//リストを追加
			}
		}
	}
	else if (m_upFlg == 3)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet2A>bullet2A;
				bullet2A = std::make_shared<Bullet2A>();

				bullet2A->Init();				//初期化
				bullet2A->SetPos(m_pos.x,m_pos.y+4);		//発射位置＝自動座標
				bullet2A->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 10;

				m_owner->AddObject(bullet2A);//リストを追加


				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet2B>bullet2B;
				bullet2B = std::make_shared<Bullet2B>();

				bullet2B->Init();				//初期化
				bullet2B->SetPos(m_pos.x,m_pos.y-4);		//発射位置＝自動座標
				bullet2B->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 10;

				m_owner->AddObject(bullet2B);//リストを追加
			}
		}
	}
	else if (m_upFlg == 4)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet2A>bullet2A;
				bullet2A = std::make_shared<Bullet2A>();

				bullet2A->Init();				//初期化
				bullet2A->SetPos(m_pos.x, m_pos.y + 4);		//発射位置＝自動座標
				bullet2A->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 5;

				m_owner->AddObject(bullet2A);//リストを追加


				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet2B>bullet2B;
				bullet2B = std::make_shared<Bullet2B>();

				bullet2B->Init();				//初期化
				bullet2B->SetPos(m_pos.x, m_pos.y - 4);		//発射位置＝自動座標
				bullet2B->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 5;

				m_owner->AddObject(bullet2B);//リストを追加
			}
		}
	}
	else if (m_upFlg==5)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet3>bullet3;
				bullet3 = std::make_shared<Bullet3>();

				bullet3->Init();				//初期化
				bullet3->SetPos(m_pos);		//発射位置＝自動座標
				bullet3->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 20;

				m_owner->AddObject(bullet3);//リストを追加
			}
		}
	}
	else if (m_upFlg == 6)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet3>bullet3;
				bullet3 = std::make_shared<Bullet3>();

				bullet3->Init();				//初期化
				bullet3->SetPos(m_pos);		//発射位置＝自動座標
				bullet3->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 10;

				m_owner->AddObject(bullet3);//リストを追加
			}
		}
	}
	else if (m_upFlg >= 7)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			if (shotWait < 0)
			{
				//弾1個分のインスタンスの生成＆初期化してリストに追加
				std::shared_ptr<Bullet3>bullet3;
				bullet3 = std::make_shared<Bullet3>();

				bullet3->Init();				//初期化
				bullet3->SetPos(m_pos);		//発射位置＝自動座標
				bullet3->SetOwner(m_owner);	//オーナーを渡しておく
				shotWait = 5;

				m_owner->AddObject(bullet3);//リストを追加
			}
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
		if (obj->GetObjType() == ObjectType::Enemy|| obj->GetObjType() == ObjectType::Enemy1 || obj->GetObjType() == ObjectType::Enemy2)
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

void Player::Release(){}
