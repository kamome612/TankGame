#pragma once
#include "Engine/GameObject.h"

//戦車を管理するクラス
class Tank:public GameObject
{
    int tbModel_;
    int tgModel_;
    XMVECTOR front_;//前ベクトル
    float speed_;
public:
    //コンストラクタ
    Tank(GameObject* parent);

    //デストラクタ
    ~Tank();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

