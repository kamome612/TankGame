#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"),tPict_(-1)
{
}

//初期化
void TitleScene::Initialize()
{
	//画像データのロード
	tPict_ = Image::Load("Picture\\TANK GAME.png");
	assert(tPict_ >= 0);
}

//更新
void TitleScene::Update()
{
	if (Input::IsKey(DIK_S)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TitleScene::Draw()
{
	Image::SetTransform(tPict_, transform_);
	Image::Draw(tPict_);
}

//解放
void TitleScene::Release()
{
}