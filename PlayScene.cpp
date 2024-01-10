#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
//#include "TankHead.h"
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
	Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
	Camera::SetPosition(XMFLOAT3(0, 5, -20));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));
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
