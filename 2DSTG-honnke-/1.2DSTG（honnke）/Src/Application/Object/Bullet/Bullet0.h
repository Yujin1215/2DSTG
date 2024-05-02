#pragma once
#include"../Baseobject.h"

class Scene;

class Bullet0 :public BaseObject
{
public:
	Bullet0() { Init(); }
	~Bullet0() { Release(); }

	void Update()override;
	void Draw() override;
	void Init() override;
	void Release() override;

	void Hit()override;


	void SetPos(Math::Vector3 _pos) { m_pos = _pos; }
	void SetMove(Math::Vector3 _move) { m_move = _move; }

	void SetOwner(Scene* _owner) { m_owner = _owner; }

private:


	Math::Vector3 m_move;

	Scene* m_owner = nullptr;


};
