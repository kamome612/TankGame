#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//クリアシーンを管理するクラス
class ClearScene : public GameObject
{
	Text* pText;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	ClearScene(GameObject* parent);
	int cPict_;

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};