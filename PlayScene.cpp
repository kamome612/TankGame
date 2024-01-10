#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
//#include "TankHead.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
	Camera::SetPosition(XMFLOAT3(0, 5, -20));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//解放
void PlayScene::Release()
{
}
