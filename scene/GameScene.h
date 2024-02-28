#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Enemy.h"
#include "FollowCamera.h"
#include "Ground.h"
#include "Input.h"
#include "Item.h"
#include "Model.h"
#include "Player.h"
#include "SafeDelete.h"
#include "Scene.h"
#include "Skydome.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <memory>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void Reset();

	/// <summary>
	/// 当たり判定
	/// </summary>
	void CheckAllCollision();

	/// <summary>
	/// アイテム発生データを読み込み
	/// </summary>
	void LoadItemPopData();

	/// <summary>
	/// アイテムの発生コマンドの更新
	/// </summary>
	void UpdataItemPopCommands();

	/// <summary>
	/// アイテムの生成
	/// </summary>
	/// <param name="positioin"></param>
	void ItemGenerate(Vector3 position);

	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	bool IsSceneEnd() { return isSceneEnd; }

	Scene NextScene() { return Scene::GAMECLEAR; }

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// スプライト
	Sprite* fadeSprite_ = nullptr;
	Vector4 fadeColor_ = {1.0f, 1.0f, 1.0f, 1.0f};

	// 自キャラの3Dモデル
	std::unique_ptr<Model> modelPlayer_;
	// 天球の3Dモデル
	std::unique_ptr<Model> modelSkydome_;
	// 地面の3Dモデル
	std::unique_ptr<Model> modelGround_;
	// 自キャラの3Dモデル
	std::unique_ptr<Model> modelFighterBody_;
	std::unique_ptr<Model> modelFighterHead_;
	std::unique_ptr<Model> modelFighterL_arm_;
	std::unique_ptr<Model> modelFighterR_arm_;

	// 敵の3Dモデル
	std::unique_ptr<Model> modelEnemyBody_;
	std::unique_ptr<Model> modelEnemyL_arm;
	std::unique_ptr<Model> modelEnemyR_arm;

	// ハンマーの3Dモデル
	std::unique_ptr<Model> modelHammer_;

	// アイテムの3Dモデル
	std::unique_ptr<Model> modelItem_;

	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// ビュープロダクション
	ViewProjection viewProjection_;
	// 自キャラ
	std::unique_ptr<Player> player_;
	// 敵
	std::unique_ptr<Enemy> enemy_;
	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;
	// 天球
	std::unique_ptr<Skydome> skydome_;
	// 地面
	std::unique_ptr<Ground> ground_;
	// 追従カメラ
	std::unique_ptr<FollowCamera> followCamera_;
	// アイテム
	std::list<std::unique_ptr<Item>> items_;
	// アイテムの発生コマンド
	std::stringstream itemPopCommands;

	// シーンを終わらせるフラグ
	bool isSceneEnd = false;

	int count_ = 0;
};
