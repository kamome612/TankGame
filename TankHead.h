#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:
    int tgModel_;//TankHead�̃��f����ǂޕϐ�
    //���f�����Ԃ̓O���[�o���̈�ɕۑ�����Ă���
public:
    /// <summary>
    /// 
    /// </summary>
    /// <param name="parent"></param>
    TankHead(GameObject* parent);
    ~TankHead();
    //������
    void Initialize()override;

    //�X�V
    void Update() override;

    //�`��
    void Draw()override;

    //�J��
    void Release()override;

    /// <summary>
    /// ���f���ԍ���Ԃ��ϐ�
    /// </summary>
    /// <returns>tgModel_:���f���ԍ�</returns>
    int GetModelHandle() { return tgModel_; }
};

