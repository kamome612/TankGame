#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Tank.h"
#include "Enemy.h"

//プレイシーンを管理するクラス
class PlayScene : public GameObject
{
	Text* pText;
	Tank* player;
	int enemyNum;
	int em;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	//インライン定義
	void DescEnemy() { enemyNum--; }//弾がEnemyに当たったら減らす
	bool InEnemyLeft() { return enemyNum > 0; }//Enemyがいるかいないかを判断する
	int GetEnemyNum() { return enemyNum; }//enemyNumをとってくる
};