#pragma once
#include "Sprite.h"

class SpriteState
{
public:
	SpriteState(SpriteCore& core)
		:
		core(core)
	{}
	virtual ~SpriteState() {}
	virtual void OnCtrlDirPress( BiDirection d) {}
	virtual void OnCtrlDirRelease(BiDirection d) {}
	virtual void OnCtrlJump() {}
	virtual void OnUpdate() {}
	virtual void OnCollision(const float floorY) {}

	

protected:
	void Transition(SpriteState* state)
	{
		core.state = state;
		delete this;
	}

protected:
	SpriteCore& core;
};