#pragma once
#include"../Baseobject.h"


class Scene;

class Enemy2 :public BaseObject
{
public:
	Enemy2() {}
	~Enemy2() { Release(); }

	void Update()override;
	void Draw() override;
	void Init() override;
	void Release() override;
	void Hit()override;

	void SetPos(Math::Vector3 _pos) { m_pos = _pos; }
	void SetPos(float _x, float _y) { m_pos = { _x,_y,0.0f }; }//SetPosをオーバーロード

	void SetMove(Math::Vector3 _move) { m_move = _move; }

private:

	Math::Vector3 m_move;

	Scene* m_owner = nullptr;

};
