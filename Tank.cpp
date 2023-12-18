#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),tbModel_(-1),tgModel_(-1)
{
}

//�f�X�g���N�^
Tank::~Tank()
{
}

//������
void Tank::Initialize()
{
	//���f���f�[�^�̃��[�h
	tbModel_ = Model::Load("Model\\Tankbody.fbx");
	assert(tbModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	tgModel_ = Model::Load("Model\\Tankgun.fbx");
	assert(tgModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

//�X�V
void Tank::Update()
{
	if (Input::IsKey(DIK_A)) {
		transform_.rotate_.y -= 1.0f; //-1�x����]
	}
	if (Input::IsKey(DIK_D)) {
		transform_.rotate_.y += 1.0f; //1�x����]
	}
	if (Input::IsKey(DIK_W)) {
		transform_.position_.z += 0.1f;
	}
	if (Input::IsKey(DIK_S)) {
		transform_.position_.z -= 0.1f;
	}
}

//�`��
void Tank::Draw()
{
	Model::SetTransform(tbModel_, transform_);
	Model::Draw(tbModel_);
	Model::SetTransform(tgModel_, transform_);
	Model::Draw(tgModel_);
}

//���
void Tank::Release()
{
}
