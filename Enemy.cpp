#include "Enemy.h"
#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Bullet"), eModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	eModel_ = Model::Load("Model\\kinoko.fbx");
	assert(eModel_ >= 0);
	transform_.rotate_.y += 180.0f;
	transform_.scale_ = {2.0,2.0,2.0};
	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.3f);
	AddCollider(collision);

	float x = (float)rand() / RAND_MAX;//0-1の乱数
	x = 2.0 * x;//0-2の乱数
	float z = (float)rand() / RAND_MAX;//0-1の乱数
	z = 2.0 * z;//0-2の乱数

	//アニメーションのセット
	Model::SetAnimFrame(eModel_, 1, 60, 1);
}

void Enemy::Update()
{
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist/2;
	}
}

void Enemy::Draw()
{
	Model::SetTransform(eModel_, transform_);
	Model::Draw(eModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
	}
}
