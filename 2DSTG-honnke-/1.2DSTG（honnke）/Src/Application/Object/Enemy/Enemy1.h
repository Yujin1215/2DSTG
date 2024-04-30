#pragma once
#include"../Baseobject.h"


class Scene;

class Enemy1 :public BaseObject
{
public:
	Enemy1() {}
	~Enemy1() { Release(); }

	void Update()override;
	void Draw() override;
	void Init() override;
	void Release() override;
	void Hit()override;

	void SetPos(Math::Vector3 _pos) { m_pos = _pos; }
	void SetPos(float _x, float _y) { m_pos = { _x,_y,0.0f }; }//SetPosをオーバーロード



	void SetMovePow(Math::Vector3 _move) { m_move = _move; }

private:

	//Math::Vector3 m_move;

	Scene* m_owner = nullptr;

	float angle=0;

};
