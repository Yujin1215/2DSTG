//#pragma once
//
//
//
//class GameScene
//{
//public://外部から呼べる・いじれる
//	GameScene() {}
//	~GameScene() { Release(); }//破壊時にRelease()
//
//	void Update();		//更新
//	void Draw();		//描画
//	void Init();		//初期化
//
//
//
//private://外部からよばれない・いじられない
//
//	void Release();		//終了処理 ※外部に呼ばれたくないのでprivate
//
//
//
////public:
////	static GameScene& GetInstance()
////	{
////		static GameScene instance;
////		return instance;
////	}
//
//};
//
////#define GAMESCENE GameScene::GetInstance()