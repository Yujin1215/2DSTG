#include "main.h"
#include "Scene.h"
#include"Object/Player/Player.h"
#include"Object/Enemy/Enemy.h"
#include"Object/Enemy/Enemy1.h"
#include"Object/Enemy/Enemy2.h"
#include"Object/Bullet/Bullet.h"



void Scene::Draw2D()
{
	for (int i = 0; i < m_objList.size(); i++)m_objList[i]->Draw();
}

void Scene::Update()
{
	//イテレータ作成　auto版
	auto it = m_objList.begin();
	while (it != m_objList.end())//end\89は最後の要素の１つうしろを返す
	{
		//オブジェクトの有効チェック
		if ((*it)->GetAliveFlg() == false)
		{
			it = m_objList.erase(it);
			//無効なオブジェクトをリストから削除
		}
		else
		{
			it++;//次の要素へイテレータを進める
		}
	}

	//============================================================================

	//enemy
	if (rand() % 100 < 0.0)
	{
		//1体分インスタンスを生成＆初期化してリストへ追加
		std::shared_ptr<Enemy>enemy;
		enemy = std::make_shared<Enemy>();

		int moveY = 0;
		moveY = rand() % 5 + 1;
		moveY *= -1;

		int moveX = 0;
		moveX = rand() % 5 + 1;
		moveX *= -1;

		enemy->Init();
		enemy->SetPos(rand() % 1280-640, 360.0f);
		enemy->SetMove({ 0.0f, (float)moveY, 0.0f });

		m_objList.push_back(enemy);
	}
	//enemy1
	if (rand() % 100 < 0.0)
	{
		std::shared_ptr<Enemy1>enemy1;
		enemy1 = std::make_shared<Enemy1>();

		int moveY = 0;
		moveY = rand() % 5+1 ;
		moveY *= -1;

		int moveX = 0;
		moveX = rand() % 5 + 1;
		moveX *= -1;

		enemy1->Init();
		enemy1->SetPos(640.0f, 600.0f);
		enemy1->SetMove({ (float)moveX,(float)moveY, 0.0f});

		m_objList.push_back(enemy1);
	}
	//enemy2
	if (rand() % 100 < 0.0)
	{
		std::shared_ptr<Enemy2>enemy2;
		enemy2 = std::make_shared<Enemy2>();

		int moveY = 0;
		moveY = rand() % 5 + 1;
		moveY *= -1;

		int moveX = 0;
		moveX = rand() % 5 + 1;
		if (rand() % 100 < 50)	moveX *= -1;

		enemy2->Init();
		enemy2->SetPos(rand() % 1280 - 640, 360.0f);
		enemy2->SetMove({ (float)moveX,(float)moveY, 0.0f });

		m_objList.push_back(enemy2);
	}




	//============================================================================

	//全オブジェクトの更新関数を一括で呼ぶ
	for (int i = 0; i < m_objList.size(); i++)//size()はMAX値
	{
		m_objList[i]->Update();
	}
}

void Scene::Init()
{
	//Player
	std::shared_ptr<Player>player;			//インスタンス生成
	player = std::make_shared<Player>();	//実体の確保
	player->Init();							//初期化
	player->SetOwner(this);
	m_objList.push_back(player);

}

void Scene::Release()
{
}

void Scene::ImGuiUpdate()
{
	//return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
