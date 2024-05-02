#pragma once

class BaseObject;

class Scene
{
private:


public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();


	//オブジェクトリストを取得
	std::vector<std::shared_ptr<BaseObject>> GetObjList() { return m_objList; }

	//オブジェクトリストにオブジェクトを追加
	void AddObject(std::shared_ptr<BaseObject> _obj)
	{
		//リストの末尾に引数で渡された1要素を追加
		m_objList.push_back(_obj);
	}

private:

	//全オブジェクトを可変長配列で管理
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
