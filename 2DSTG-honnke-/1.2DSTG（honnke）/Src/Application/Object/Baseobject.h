#pragma once

class BaseObject
{
public:
	BaseObject() {}
	virtual~BaseObject() {}


	//オブジェクトの種類
	enum class ObjectType
	{
		Player,
		Enemy,
		Enemy1,
		Enemy2,
		Bullet0,
		Bullet,
		Bullet2A,
		Bullet2B,
		Bullet3,
		Item,
	};

	//仮想関数
	virtual void Update();
	virtual void Draw();
	virtual void Init();
	virtual void Release();
	virtual void Hit();
	virtual void Up();

	//セッター
	void SetTexture(std::string _fileName) { m_tex.Load(_fileName); }//ファイルパスでLoad（string型）
	void SetAlive(bool _aliveFlg) { m_aliveFlg = _aliveFlg; }

	//ゲッター
	ObjectType GetObjType() { return m_objType; }
	Math::Vector3 GetPos() { return m_pos; }
	bool GetAliveFlg() { return m_aliveFlg; }

private:

protected:

	//テクスチャー
	KdTexture m_tex;

	//座標系
	Math::Vector3 m_pos;
	Math::Vector3 m_move;

	//行列
	Math::Matrix m_mat;

	//フラグ
	bool m_aliveFlg = true;
	float m_upFlg = 0;

	float g = 0;

	ObjectType m_objType;

	

};
