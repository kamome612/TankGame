#pragma once
#include "Engine/GameObject.h"
class Bullet :
    public GameObject
{
	int bModel_;//�e�ۂ̃��f���ԍ������߂Ă������
	float bulletSpeed_;//�e�ۂ̑���
	XMFLOAT3 moveDir_;//�����̃x�N�g��
	float gravity_;
public:
	//�R���X�g���N�^
	Bullet(GameObject* parent);
	
	//�f�X�g���N�^(Release�����邩���ʂ��������������C++�I�Ȃ��)
	~Bullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { bulletSpeed_ = _speed; }
};

