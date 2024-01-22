#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�N���A�V�[�����Ǘ�����N���X
class ClearScene : public GameObject
{
	Text* pText;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	ClearScene(GameObject* parent);
	int cPict_;

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};