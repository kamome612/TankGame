#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"
#include <sstream>
#include <iomanip>

using std::stringstream;

string HUD::ConstructEnemyNumberString()
{
	//敵の数を取ってきて、文字列にする
	int enemies = ((PlayScene*)GetParent())->GetEnemyNum();
	string enemyNumStr = std::to_string(enemies);
	return enemyNumStr;
}

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hHUD_(-1),hNumbers_(-1)
{
}

HUD::~HUD()
{
}

void HUD::Initialize()
{
	//画像データのロード
	hHUD_ = Image::Load("Picture\\HUD1.png");
	assert(hHUD_ >= 0);
	hNumbers_ = Image::Load("Picture\\Numbers.png");
	assert(hNumbers_ >= 0);

	for (int i = 0; i < 3; i++) {
		Transform t;
		t.position_ = { -0.77f + 0.03f * (float)i,0.92f,0.0f };
		t.scale_ = { 0.5,0.5,0.5 };
		tNumbers_.push_back(t);
	}
}

void HUD::Update()
{
	tHud_.scale_ = { 0.5,0.5,0.5 };
	tHud_.position_ = { -0.8,0.91,0 };
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	int enemies = ((PlayScene*)GetParent())->GetEnemyNum();
	string enemystr;
	stringstream emss;
	emss << std::setw(3) << std::setfill('0') << enemies;
	emss >> enemystr;

	for (int i = 0; i < enemystr.length(); i++) {
		int n = enemystr[i] - '0';
		Image::SetRect(hNumbers_, 51.2 * (float)n, 0, 51.2, 75);
		Image::SetTransform(hNumbers_, tNumbers_[i]);
		Image::Draw(hNumbers_);
	}

	/*string enemystr = ConstructEnemyNumberString();

	if (enemystr.size() < 3) {
		enemystr = std::string(3 - enemystr.size(), '0') + enemystr;
	}

	for (int i = 0; i < 3; i++) {
		int n = enemystr[i] - '0';
		Image::SetRect(hNumbers_,51.2 * (float)n,0, 51.2, 75);
		Image::SetTransform(hNumbers_, tNumbers_[i]);
		Image::Draw(hNumbers_);
	}*/

	/*for (int i = 0; i < 3;i++) {
		tNumber_.position_ = { (float)(-0.8 + (0.04 * i)),0.92,0};
		tNumber_.scale_ = { 0.5,0.5,0.5 };
		Image::SetRect(hNumbers_, 0.25, 0, 60, 106);
		Image::SetTransform(hNumbers_, tNumber_);
		Image::Draw(hNumbers_);
	}*/
}

void HUD::Release()
{
}
