#pragma once
#include "Engine/GameObject.h"
#include <string>
#include <vector>
#include <iomanip>

using std::string;


class HUD :
    public GameObject
{
    string ConstructEnemyNumberString();
public:
    //�R���X�g���N�^
    //�����Fparent �e�I�u�W�F�N�g(SceneManager)
    HUD(GameObject* parent);
    //�f�X�g���N�^
    ~HUD();
    int hHUD_;//�c��Z�Z�@�̉摜
    int hNumbers_;//�����̉摜
    Transform tHud_;
    Transform tNumber_;
    std::vector<Transform> tNumbers_;

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;

};

