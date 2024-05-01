#include "main.h"
#include "Scene.h"
#include"Object/Player/Player.h"
#include"Object/Enemy/Enemy.h"
#include"Object/Enemy/Enemy1.h"
#include"Object/Bullet/Bullet.h"

void Scene::Draw2D()
{
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Draw();
	}

}

void Scene::Update()
{

	//�C�e���[�^�쐬�@auto��
	auto it = m_objList.begin();

	while (it != m_objList.end())//end\89�͍Ō�̗v�f�̂P�������Ԃ�
	{
		//�I�u�W�F�N�g�̗L���`�F�b�N
		if ((*it)->GetAliveFlg() == false)
		{
			it = m_objList.erase(it);
			//�����ȃI�u�W�F�N�g�����X�g����폜
		}
		else
		{
			it++;//���̗v�f�փC�e���[�^��i�߂�
		}
	}

	//3%�̊m���œG���o��������
	if (rand() % 100 < 0.5)
	{
		//1�̕��C���X�^���X�𐶐������������ă��X�g�֒ǉ�
		std::shared_ptr<Enemy>enemy;
		enemy = std::make_shared<Enemy>();

		enemy->Init();
		enemy->SetPos(640.0f, 0.0f);
		enemy->SetMovePow({ -2.0f, -2.0f, 0.0f });

		m_objList.push_back(enemy);
	}
	if (rand() % 100 < 0.5)
	{
		std::shared_ptr<Enemy1>enemy1;
		enemy1 = std::make_shared<Enemy1>();

		enemy1->Init();
		enemy1->SetPos(640.0f, 360.0f);
		enemy1->SetMove({ 0.0f, -1.0f, 0.0f });

		m_objList.push_back(enemy1);
	}
	//�S�I�u�W�F�N�g�̍X�V�֐����ꊇ�ŌĂ�
	for (int i = 0; i < m_objList.size(); i++)//size()��MAX�l
	{
		m_objList[i]->Update();
	}
}

void Scene::Init()
{
	//Player
	std::shared_ptr<Player>player;			//�C���X�^���X����
	player = std::make_shared<Player>();	//���̂̊m��
	player->Init();							//������
	player->SetOwner(this);
	m_objList.push_back(player);


	//Enemy
	for (int i = 0; i < 10; i++)
	{
		std::shared_ptr<Enemy>enemy;
		enemy = std::make_shared<Enemy>();
		enemy->Init();
		enemy->SetPos(-640.0f + (i * 128.0f), (360.0f));
		m_objList.push_back(enemy);
	}
}

void Scene::Release()
{
}

void Scene::ImGuiUpdate()
{
	//return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// �f�o�b�O�E�B���h�E
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
