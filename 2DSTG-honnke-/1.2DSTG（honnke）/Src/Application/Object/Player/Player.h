#pragma once
#include"../BaseObject.h"
class Scene;

class Player :public BaseObject
{
public:
	Player() {}
	~Player() { Release(); }

	void Update()override;
	void Draw() override;
	void Init() override;
	void Release() override;

	void SetMove(Math::Vector3 _move) { m_move = _move; }
	void SetOwner(Scene* _owner) { m_owner = _owner; }
	void Hit()override { m_aliveFlg = false; }

	void Up()override { m_upFlg++; }

private:

	Scene* m_owner = nullptr;
	float shotWait = 0;

};

