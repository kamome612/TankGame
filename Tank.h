#pragma once
#include "Engine/GameObject.h"

//��Ԃ��Ǘ�����N���X
class Tank:public GameObject
{
public:
    //�R���X�g���N�^
    Tank(GameObject* parent);

    //�f�X�g���N�^
    ~Tank();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

