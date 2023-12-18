#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Ground::Ground(GameObject* parent)
	:GameObject(parent,"Ground"),gModel_(-1)
{
}

//�f�X�g���N�^
Ground::~Ground()
{
}

//������
void Ground::Initialize()
{
	//���f���f�[�^�̃��[�h
	gModel_ = Model::Load("Model\\Ground.fbx");
	assert(gModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

//�X�V
void Ground::Update()
{
}

//�`��
void Ground::Draw()
{
	Model::SetTransform(gModel_, transform_);
	Model::Draw(gModel_);
}

//���
void Ground::Release()
{
}
