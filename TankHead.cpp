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
		transform_.rotate_.y -= 1.0f; //-1“x‚¸‚Â‰ñ“]
	}
	if (Input::IsKey(DIK_RIGHT)) {
		transform_.rotate_.y += 1.0f; //1“x‚¸‚Â‰ñ“]
	}
}

void TankHead::Draw()
{
	//transform_‚Í©•ª(TankHead)‚Ìƒƒ“ƒo•Ï”
	Model::SetTransform(tgModel_, transform_);
	Model::Draw(tgModel_);
}

void TankHead::Release()
{
}
