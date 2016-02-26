#pragma once

#include "SpriteState.h"

class PlayerStanding : public SpriteState
{
public:
	PlayerStanding(SpriteCore& core)
		:
		SpriteState(core),
		sdx( 0.92f )
	{
		core.currentSeq = core.seqs[0];
	}
	virtual void OnCtrlDirPress(BiDirection d);
	virtual void OnCtrlJumpPress();
	virtual void OnUpdate();
protected:
	const float sdx; // speed decay coefficient
};