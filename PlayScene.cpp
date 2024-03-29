#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
//#include "TankHead.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"
#include "HUD.h"

namespace
{
	const int ENEMY_NUM{ 30 };
}

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),pText(nullptr)
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player=Instantiate<Tank>(this);
	enemyNum = ENEMY_NUM;
	for (int i= 0; i < enemyNum; i++) {
		Instantiate<Enemy>(this);
	}
	pText = new Text;
	pText->Initialize();
	//Instantiate<TankHead>(this);
	//Camera::SetPosition(XMFLOAT3(0, 8, -30));
	//Camera::SetTarget(XMFLOAT3(0, 0, 0));

	Instantiate<HUD>(this);
}

//更新
void PlayScene::Update()
{
	//タンクと一緒にカメラを動かすよ
	/*Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);*/
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
} 

//描画
void PlayScene::Draw()
{
	//敵の数を文字で表示する場合
	/*pText->Draw(30, 30, "Enemy : ");
	pText->Draw(130, 30, enemyNum);*/
}

//解放
void PlayScene::Release()
{
}
