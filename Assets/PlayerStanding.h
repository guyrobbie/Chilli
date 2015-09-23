#pragma once

#include "SpriteState.h"

class PlayerStanding : public SpriteState
{
public:
	PlayerStanding(SpriteCore& core)
		:
		SpriteState(core)
	{
		core.currentSeq = core.seqs[0];
	}
	virtual void OnCtrlDirPress(BiDirection d);
	virtual void OnCtrlJump();
	

};