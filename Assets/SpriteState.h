#pragma once
#include "Sprite.h"

class SpriteState
{
public:
	SpriteState(SpriteCore* core)
		:
		core(core)
	{}
	virtual void OnCtrlRightDown() {}
	virtual void OnCtrlRightUp() {}
	virtual void OnUpdate() {}

protected:
	SpriteCore* core;
};