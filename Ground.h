#pragma once
#include "Engine/GameObject.h"

//地面を管理するクラス
class Ground:public GameObject
{
    int gModel_;
public:
    //コンストラクタ
    Ground(GameObject* parent);

    //デストラクタ
    ~Ground();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    int GetModelHandle() { return(gModel_); }
};

