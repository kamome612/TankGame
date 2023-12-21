#pragma once
#include "Engine/GameObject.h"

//�n�ʂ��Ǘ�����N���X
class Ground:public GameObject
{
    int gModel_;
public:
    //�R���X�g���N�^
    Ground(GameObject* parent);

    //�f�X�g���N�^
    ~Ground();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    int GetModelHandle() { return(gModel_); }
};

