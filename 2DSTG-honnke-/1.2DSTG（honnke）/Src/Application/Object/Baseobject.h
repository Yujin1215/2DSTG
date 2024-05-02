#pragma once

class BaseObject
{
public:
	BaseObject() {}
	virtual~BaseObject() {}


	//�I�u�W�F�N�g�̎��
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

	//���z�֐�
	virtual void Update();
	virtual void Draw();
	virtual void Init();
	virtual void Release();
	virtual void Hit();
	virtual void Up();

	//�Z�b�^�[
	void SetTexture(std::string _fileName) { m_tex.Load(_fileName); }//�t�@�C���p�X��Load�istring�^�j
	void SetAlive(bool _aliveFlg) { m_aliveFlg = _aliveFlg; }

	//�Q�b�^�[
	ObjectType GetObjType() { return m_objType; }
	Math::Vector3 GetPos() { return m_pos; }
	bool GetAliveFlg() { return m_aliveFlg; }

private:

protected:

	//�e�N�X�`���[
	KdTexture m_tex;

	//���W�n
	Math::Vector3 m_pos;
	Math::Vector3 m_move;

	//�s��
	Math::Matrix m_mat;

	//�t���O
	bool m_aliveFlg = true;
	float m_upFlg = 0;

	float g = 0;

	ObjectType m_objType;

	

};
