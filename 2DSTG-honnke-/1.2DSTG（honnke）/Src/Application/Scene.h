#pragma once

class BaseObject;

class Scene
{
private:


public:

	// �����ݒ�
	void Init();

	// ���
	void Release();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw2D();

	// GUI����
	void ImGuiUpdate();


	//�I�u�W�F�N�g���X�g���擾
	std::vector<std::shared_ptr<BaseObject>> GetObjList() { return m_objList; }

	//�I�u�W�F�N�g���X�g�ɃI�u�W�F�N�g��ǉ�
	void AddObject(std::shared_ptr<BaseObject> _obj)
	{
		//���X�g�̖����Ɉ����œn���ꂽ1�v�f��ǉ�
		m_objList.push_back(_obj);
	}

private:

	//�S�I�u�W�F�N�g���ϒ��z��ŊǗ�
	std::vector<std::shared_ptr<BaseObject>>m_objList;

 	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
