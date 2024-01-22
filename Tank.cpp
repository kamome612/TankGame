#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Ground.h"
#include "TankHead.h"
#include "Engine/Camera.h"


//�J��������
enum CAM_TYPE
{
	FIXED_TYPE,//�Œ�
	TPS_NOROT_TYPE, //3�l�̉�]�Ȃ�
	TPS_TYPE,  //3�l��
	FPS_TYPE,  //1�l��
	MAX_TYPE   //�ԕ�����(�`�F�b�N�p�̒l)
};

//�R���X�g���N�^
Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),tbModel_(-1),front_({0,0,1,0}),speed_(0.05),camState_(CAM_TYPE::FIXED_TYPE)
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
	//tgModel_ = Model::Load("Model\\Tankgun.fbx");
	//assert(tgModel_ >= 0);
	//transform_.position_ = { 0,0,0 };
	Instantiate<TankHead>(this);
}

//�X�V
void Tank::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();//�s��̂P�@�P�ʍs��
	XMVECTOR move{ 0,0,0,0 };
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	if (Input::IsKey(DIK_A)) {
		this->transform_.rotate_.y -= 1.0f; //-1�x����]
	}
	if (Input::IsKey(DIK_D)) {
		this->transform_.rotate_.y += 1.0f; //1�x����]
	}
	if (Input::IsKey(DIK_W)) {
		dir = 1.0;
	}
	if (Input::IsKey(DIK_S)) {
		dir = -1.0;
	}

	//��]�s������߂�
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//�x�N�g���̉�]���ʂ����߂�
	rotVec = XMVector3TransformCoord(front_, rotY);
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));//XMVECTOR�ɍ��킹��
	pos = pos + dir * move;//pos = pos + speed_ * front_
	XMStoreFloat3(&(transform_.position_), pos);

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

	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		//camState_ = (++camState) & (CAM_TYPE::MAX);
		if (camState_ == CAM_TYPE::MAX_TYPE)
		{
			camState_ = CAM_TYPE::FIXED_TYPE();
		}
	}

	switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 5.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case CAM_TYPE::TPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{ 0,5,-10,0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}
	case CAM_TYPE::FPS_TYPE:
	{
		Camera::SetPosition(transform_.position_);
		XMFLOAT3 camTarget;
		XMStoreFloat3(&camTarget, pos + move);
		Camera::SetTarget(camTarget);
		break;
	}
	default:
		break;
	}
}

//�`��
void Tank::Draw()
{
	Model::SetTransform(tbModel_, transform_);
	Model::Draw(tbModel_);
	//Model::SetTransform(tgModel_, transform_);
	//Model::Draw(tgModel_);
}

//���
void Tank::Release()
{
}
