#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),cPict_(-1),pText(nullptr)
{
}

void ClearScene::Initialize()
{
	//画像データのロード
	cPict_ = Image::Load("Picture\\clear.png");
	assert(cPict_ >= 0);
	pText = new Text;
	pText->Initialize();
}

void ClearScene::Update()
{
	XMFLOAT3 mouse;
	mouse = Input::GetMousePosition();
	if (Input::IsMouseButtonDown(0))
	{
		if (mouse.y >= 510 && mouse.y <= 601) {
			if (mouse.x >= 193 && mouse.x <= 475) {
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(SCENE_ID_TITLE);
			}
			else if (mouse.x >= 503 && mouse.x <= 785) {
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(SCENE_ID_PLAY);
			}
			else if (mouse.x >= 814 && mouse.x <= 1096) {
				exit(1);
			}
		}
	}
	//左クリックされた
	/*if (Input::IsMouseButtonDown(0))
	{
		XMFLOAT3 mouse;
		mouse = Input::GetMousePosition();
		if(mouse)
	}*/
}

void ClearScene::Draw()
{
	Image::SetTransform(cPict_, transform_);
	Image::Draw(cPict_);
	//XMFLOAT3 mouse;
	//mouse = Input::GetMousePosition();
	//pText->Draw(30, 30, mouse.x);
	//pText->Draw(100, 30, mouse.y);
}

void ClearScene::Release()
{
}
