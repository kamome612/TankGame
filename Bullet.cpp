#include "Bullet.h"
#include "Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), bModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	bModel_ = Model::Load("Model\\Bullet.fbx");
	assert(bModel_ >= 0);
}

void Bullet::Update()
{
	//transform_.positionÇmoveDir_Ç∆bulletSpeedÇ≈çXêV
	//transform_.position_.z += 0.05;
	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed_;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
}

void Bullet::Draw()
{
	Model::SetTransform(bModel_, transform_);
	Model::Draw(bModel_);
}

void Bullet::Release()
{
}
