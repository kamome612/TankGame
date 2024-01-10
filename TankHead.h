#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:
    int tgModel_;//TankHeadのモデルを読む変数
    //モデル事態はグローバル領域に保存されている
public:
    /// <summary>
    /// 
    /// </summary>
    /// <param name="parent"></param>
    TankHead(GameObject* parent);
    ~TankHead();
    //初期化
    void Initialize()override;

    //更新
    void Update() override;

    //描画
    void Draw()override;

    //開放
    void Release()override;

    /// <summary>
    /// モデル番号を返す変数
    /// </summary>
    /// <returns>tgModel_:モデル番号</returns>
    int GetModelHandle() { return tgModel_; }
};

