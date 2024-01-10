#include "TankHead.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

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
		transform_.rotate_.y -= 1.0f; //-1度ずつ回転
	}
	if (Input::IsKey(DIK_RIGHT)) {
		transform_.rotate_.y += 1.0f; //1度ずつ回転
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
