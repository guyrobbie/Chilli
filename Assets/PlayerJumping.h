#pragma once

#include "SpriteState.h"
#include "RectF.h"

class PlayerJumping : public SpriteState
{
public:
	PlayerJumping(SpriteCore& core, bool isMoving, bool hasJumped = true)
		:
		SpriteState(core),
		isMoving(isMoving),
		ay(0.6f),
		sax(0.4f),
		sdx( 0.97f ),
		maxsx( 7.5f ),
		isBoosting( true ),
		sdy( 0.4f )
	{
		if (hasJumped)
		{
			core.vy = -12.0f;
		}
		core.currentSeq = core.seqs[2];
	}
	virtual void OnUpdate();
	virtual void OnCtrlDirPress(BiDirection d);
	virtual void OnCtrlDirRelease(BiDirection d);
	virtual void OnCtrlJumpRelease();
	virtual void OnCollision(const RectF& rect);
protected:
	float sax;
	float sdx; // speed decay coefficient
	const float ay;
	const float maxsx;
	bool isMoving;
	bool isBoosting;
	const float sdy; // upwards velocity decay coefficient
};