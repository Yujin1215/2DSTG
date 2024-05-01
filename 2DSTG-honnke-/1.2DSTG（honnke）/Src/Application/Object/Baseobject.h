#pragma once

class BaseObject
{
public:
	BaseObject(){}
	virtual~BaseObject(){}

	//�I�u�W�F�N�g�̎��
	enum class ObjectType
	{
		Player,
		Enemy,
		Enemy1,
		Bullet,
	};

	//���z�֐�
	virtual void Update();
	virtual void Draw();
	virtual void Init();
	virtual void Release();
	virtual void Hit();

	//�Z�b�^�[
	void SetTexture(std::string _fileName) { m_tex.Load(_fileName); }//�t�@�C���p�X��Load�istring�^�j

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

	ObjectType m_objType;

	

};
