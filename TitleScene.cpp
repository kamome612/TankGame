#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"),tPict_(-1),pText(nullptr)
{
}

//初期化
void TitleScene::Initialize()
{
	//画像データのロード
	tPict_ = Image::Load("Picture\\TANK GAME.png");
	assert(tPict_ >= 0);
	pText = new Text;
	pText->Initialize();
}

//更新
void TitleScene::Update()
{
	XMFLOAT3 mouse;
	mouse = Input::GetMousePosition();
	if (Input::IsMouseButtonDown(0))
	{
		if (mouse.y >= 507 && mouse.y <= 599) {
			if (mouse.x >= 345 && mouse.x <= 627) {
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(SCENE_ID_PLAY);
			}
			else if (mouse.x >= 655 && mouse.x <= 937) {
				exit(1);
			}
		}
	}
	/*if (Input::IsKey(DIK_S)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}*/
}

//描画
void TitleScene::Draw()
{
	Image::SetTransform(tPict_, transform_);
	Image::Draw(tPict_);
	/*XMFLOAT3 mouse;
	mouse = Input::GetMousePosition();
	pText->Draw(30, 30, mouse.x);
	pText->Draw(100, 30, mouse.y);*/
}

//解放
void TitleScene::Release()
{
}