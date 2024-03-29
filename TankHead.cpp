#include "TankHead.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),tgModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	tgModel_ = Model::Load("Model\\Tankgun.fbx");
	assert(tgModel_ >= 0);

}

void TankHead::Update()
{
	if (Input::IsKey(DIK_LEFT)) {
		transform_.rotate_.y -= 2.0f; //-1度ずつ回転
	}
	if (Input::IsKey(DIK_RIGHT)) {
		transform_.rotate_.y += 2.0f; //1度ずつ回転
	}
	if (Input::IsKeyDown(DIK_SPACE)) {
		XMFLOAT3 cannonTopPos = Model::GetBonePosition(tgModel_, "CannonPos");
		XMFLOAT3 cannonRootPos = Model::GetBonePosition(tgModel_, "CannonRoot");
		XMVECTOR vtop = XMLoadFloat3(&cannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&cannonRootPos);
		XMVECTOR moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);//単位ベクトル化
		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(cannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpeed(0.2);
	}
}

void TankHead::Draw()
{
	//transform_は自分(TankHead)のメンバ変数
	Model::SetTransform(tgModel_, transform_);
	Model::Draw(tgModel_);
}

void TankHead::Release()
{
}
