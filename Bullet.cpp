#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

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
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.3f);
	AddCollider(collision);
}

void Bullet::Update()
{
	gravity_ += 0.01;
	//transform_.position‚ðmoveDir_‚ÆbulletSpeed‚ÅXV
	//transform_.position_.z += 0.05;
	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed_;
	transform_.position_.y = transform_.position_.y + (moveDir_.y - gravity_) * bulletSpeed_;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed_;
	/*transform_.position_->XMVECTOR pos;
	moveDir->XMVECTOR dir;
	pos = pos + bulletSpeed_ * dir;*/
	if (transform_.position_.y <= -1.0)
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(bModel_, transform_);
	Model::Draw(bModel_);
}

void Bullet::Release()
{
}
