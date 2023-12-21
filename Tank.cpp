#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Ground.h"

//�R���X�g���N�^
Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),tbModel_(-1),tgModel_(-1)
{
	front_ = XMVECTOR{ 0,0,1,0 };
	speed_ = 0.05;
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
		//��]�s������߂�
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		//�x�N�g���̉�]���ʂ����߂�
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);
		

		//transform_.position_.z += 0.1f;
		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));//XMVECTOR�ɍ��킹��
		pos = pos + move;//pos = pos + speed_ * front_
		XMStoreFloat3(&(transform_.position_), pos);
	}
	if (Input::IsKey(DIK_S)) {
		//��]�s������߂�
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		//�x�N�g���̉�]���ʂ����߂�
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

		//transform_.position_.z -= 0.1f;
		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));//XMVECTOR�ɍ��킹��
		pos = pos - move;//pos = pos + speed_ * front_
		XMStoreFloat3(&(transform_.position_), pos);
	}

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;
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
