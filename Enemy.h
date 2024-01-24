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

    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;

    void OnCollision(GameObject* pTarget) override;

};

