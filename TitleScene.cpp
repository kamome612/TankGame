#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"),hPict_(-1)
{
}

//������
void TitleScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Picture\\Title.png");
	assert(hPict_ >= 0);
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
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//���
void TitleScene::Release()
{
}