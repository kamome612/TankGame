#pragma once
#include "Engine/GameObject.h"

class PlayScene;

class Enemy :
    public GameObject
{
    int eModel_;
    int enemyCount_;
    PlayScene* playScene_;
public:

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

};

