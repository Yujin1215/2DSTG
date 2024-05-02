#include"../../Scene.h"
#include "Enemy.h"


void Enemy::Update()
{
	m_pos += m_move;
	if (m_pos.x < -640)m_aliveFlg = false;

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Enemy::Draw()
{
	Math::Rectangle rc;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	rc = { 0,0,64,64 };
	SHADER.m_spriteShader.DrawTex(&m_tex, 0, 0, 64, 64, &rc);
}

void Enemy::Init()
{
	m_tex.Load("Texture/enemy.png");
	m_pos = {};						//0,0で初期化
	m_mat = Math::Matrix::Identity;	//単位行列で初期化   Identity=単位行列
	m_objType = ObjectType::Enemy;
	m_move = { 0.0f,-2.0f,0.0f };
}

void Enemy::Release()
{}

void Enemy::Hit()
{
	m_aliveFlg = false;
}
