#pragma once
#include "Engine/GameObject.h"
class Enemy :
    public GameObject
{
    int eModel_;
public:
    int enemyCount_ = 10;

    //コンストラクタ
    Enemy(GameObject* parent);

    //デストラクタ
    ~Enemy();

    //初期化
    void Initialize()override;

    //更新
    void Update()override;

    //描画
    void Draw()override;

    //開放
    void Release()override;

    void OnCollision(GameObject* pTarget) override;

    int GetEC() { return enemyCount_; }

};

