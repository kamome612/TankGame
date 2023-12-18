#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//コンストラクタ
Ground::Ground(GameObject* parent)
	:GameObject(parent,"Ground"),gModel_(-1)
{
}

//デストラクタ
Ground::~Ground()
{
}

//初期化
void Ground::Initialize()
{
	//モデルデータのロード
	gModel_ = Model::Load("Model\\Ground.fbx");
	assert(gModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

//更新
void Ground::Update()
{
}

//描画
void Ground::Draw()
{
	Model::SetTransform(gModel_, transform_);
	Model::Draw(gModel_);
}

//解放
void Ground::Release()
{
}
