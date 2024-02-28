#pragma once
#include "BaseCharacter.h"
#include "MT.h"
class Enemy : public BaseCharacter {

public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize(const std::vector<Model*>& models) override;

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Updata() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw(const ViewProjection& viewProjection);

	void SetViewProjection(const ViewProjection* viewProjection) {
		viewProjection_ = viewProjection;
	}
	/// <summary>
	///  ワールド座標を取得
	/// </summary>
	/// <returns></returns>
	const WorldTransform& GetWorldTransform();

	/// <summary>
	///  ワールド座標を取得
	/// </summary>
	/// <returns></returns>
	Vector3 GetWorldPosition();

	// getter
	float GetRadius() { return radius_; }

	bool IsDead() const { return isDead_; }

	void OnCollision();

	void ResetPosition();

private:

	WorldTransform worldTransformBody_;
	/*WorldTransform worldTransformL_arm_;
	WorldTransform worldTransformR_arm_;*/

	// カメラのビュープロジェクション
	const ViewProjection* viewProjection_ = nullptr;

	enum EnemyNum {
		kModeIndexBody,
		/*kModeIndexL_arm,
		kModeIndexR_arm,*/
	};

	// 半径
	float radius_ = 4;

	// デスフラグ
	bool isDead_ = false;

};
