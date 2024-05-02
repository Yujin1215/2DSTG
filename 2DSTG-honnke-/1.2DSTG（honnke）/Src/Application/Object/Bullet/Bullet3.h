#pragma once
#include"../Baseobject.h"

class Scene;

class Bullet3 :public BaseObject
{
public:
	Bullet3() { Init(); }
	~Bullet3() { Release(); }

	void Update()override;
	void Draw() override;
	void Init() override;
	void Release() override;

	void Hit()override;


	void SetPos(Math::Vector3 _pos) { m_pos = _pos; }
	void SetPos(float _x, float _y) { m_pos = { _x,_y,0.0f }; }//SetPosをオーバーロード
	void SetMove(Math::Vector3 _move) { m_move = _move; }

	void SetOwner(Scene* _owner) { m_owner = _owner; }


private:


	Math::Vector3 m_move;

	Scene* m_owner = nullptr;

};
