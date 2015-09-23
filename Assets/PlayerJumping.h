#pragma once

#include "SpriteState.h"

class PlayerJumping : public SpriteState
{
public:
	PlayerJumping(SpriteCore& core, float sx, bool isMoving)
		:
		SpriteState(core),
		sx(sx),
		isMoving(isMoving),
		ay(0.6f),
		vy(-12.0f)
	{
		core.currentSeq = core.seqs[2];
	}
	virtual void OnUpdate();
	virtual void OnCollision(const float floorY);
	virtual void OnCtrlDirPress(BiDirection d);
	virtual void OnCtrlDirRelease(BiDirection d);
protected:
	float vy;
	const float sx;
	const float ay;
	bool isMoving;
};