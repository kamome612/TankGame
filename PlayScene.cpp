#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
//#include "TankHead.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),pText(nullptr)
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player=Instantiate<Tank>(this);
	for (int i = 0; i < 10; i++) {
		Enemy*e =Instantiate<Enemy>(this);
		e->SetPosition(i * 3-15, 0, 15);
	}
	pText = new Text;
	pText->Initialize();
	//Instantiate<TankHead>(this);
	//Camera::SetPosition(XMFLOAT3(0, 8, -30));
	//Camera::SetTarget(XMFLOAT3(0, 0, 0));
}

//�X�V
void PlayScene::Update()
{
	//�^���N�ƈꏏ�ɃJ�����𓮂�����
	Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);
	EC = ec->GetEC();
}

//�`��
void PlayScene::Draw()
{
	pText->Draw(30, 30, "Enemy : ");
	pText->Draw(150, 30, EC);
}

//���
void PlayScene::Release()
{
}
