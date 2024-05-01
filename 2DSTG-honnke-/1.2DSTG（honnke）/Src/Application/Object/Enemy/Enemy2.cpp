#include"../../Scene.h"
#include "Enemy2.h"


void Enemy2::Update()
{
	Math::Matrix transMat;
	m_pos += m_move;
	if (m_pos.y < -360)m_aliveFlg = false;

	if (abs(m_pos.x) > 640)m_move.x *= -1;

	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Enemy2::Draw()
{
	Math::Rectangle rc;
	SHADER.m_spriteShader.SetMatrix(m_mat);
	rc = { 0,0,64,64 };
	SHADER.m_spriteShader.DrawTex(&m_tex, 0, 0, 64, 64, &rc);
}

void Enemy2::Init()
{
	m_tex.Load("Texture/enemy.png");
	m_pos = {};						//0,0で初期化
	m_mat = Math::Matrix::Identity;	//単位行列で初期化   Identity=単位行列
	m_objType = ObjectType::Enemy;
	m_move = {};
}

void Enemy2::Release()
{
}

void Enemy2::Hit()
{
	m_aliveFlg = false;
}
