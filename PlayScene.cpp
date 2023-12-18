#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
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
	Camera::SetPosition(XMFLOAT3(0, 6, -8));
	Camera::SetTarget(XMFLOAT3(0, 3, 0));
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
