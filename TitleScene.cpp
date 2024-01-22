#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"),tPict_(-1)
{
}

//������
void TitleScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	tPict_ = Image::Load("Picture\\TANK GAME.png");
	assert(tPict_ >= 0);
}

//�X�V
void TitleScene::Update()
{
	if (Input::IsKey(DIK_S)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void TitleScene::Draw()
{
	Image::SetTransform(tPict_, transform_);
	Image::Draw(tPict_);
}

//���
void TitleScene::Release()
{
}