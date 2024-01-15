#pragma once
#include "Engine/GameObject.h"
class Enemy :
    public GameObject
{
    int eModel_;
public:
    int enemyCount_ = 10;

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

    int GetEC() { return enemyCount_; }

};

