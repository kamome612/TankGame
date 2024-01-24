#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Tank.h"
#include "Enemy.h"

//�v���C�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
	Text* pText;
	Tank* player;
	int enemyNum;
	int em;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	//�C�����C����`
	void DescEnemy() { enemyNum--; }//�e��Enemy�ɓ��������猸�炷
	bool InEnemyLeft() { return enemyNum > 0; }//Enemy�����邩���Ȃ����𔻒f����
	int GetEnemyNum() { return enemyNum; }//enemyNum���Ƃ��Ă���
};