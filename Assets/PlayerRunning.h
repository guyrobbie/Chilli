#pragma once

#include "SpriteState.h"
#include "PlayerStanding.h"

class PlayerRunning : public SpriteState
{
public:
	PlayerRunning(SpriteCore& core)
		:
		SpriteState(core),
		sax( 0.4f ),
		maxsx( 12.0f )
	{
		core.vx = 0;
		core.vy = 0;
		core.currentSeq = core.seqs[1];
	}
	virtual void OnUpdate();
	virtual void OnCtrlDirRelease(BiDirection d);
	virtual void OnCtrlDirPress(BiDirection d);
	virtual void OnCtrlJumpPress();
protected:
	const float sax;
	const float maxsx;

};