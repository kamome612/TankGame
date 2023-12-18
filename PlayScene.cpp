#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	Camera::SetPosition(XMFLOAT3(0, 6, -8));
	Camera::SetTarget(XMFLOAT3(0, 3, 0));
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//���
void PlayScene::Release()
{
}
