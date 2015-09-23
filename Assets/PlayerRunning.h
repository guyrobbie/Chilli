#pragma once

#include "SpriteState.h"
#include "PlayerStanding.h"

class PlayerRunning : public SpriteState
{
public:
	PlayerRunning(SpriteCore& core)
		:
		SpriteState(core),
		sx(6.0f)
	{
		core.currentSeq = core.seqs[1];
	}
	virtual void OnUpdate();
	virtual void OnCtrlDirRelease(BiDirection d);
	virtual void OnCtrlDirPress(BiDirection d);
	virtual void OnCtrlJump();
protected:
	const float sx;

};