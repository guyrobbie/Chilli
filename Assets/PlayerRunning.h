#pragma once

#include "SpriteState.h"
#include "PlayerStanding.h"
#include "PlayerMovingHorizontally.h"

class PlayerRunning : public PlayerMovingHorizontally
{
public:
	PlayerRunning(SpriteCore& core)
		:
		PlayerMovingHorizontally(core),
		sax( 0.4f ),
		maxsx( 12.0f )
	{
		//core.vx = 0;
		//core.vy = 0;
		core.currentSeq = core.seqs[1];
	}
	virtual void OnUpdate();
	virtual void OnCtrlDirRelease(BiDirection d);
	virtual void OnCtrlDirPress(BiDirection d);
	virtual void OnCtrlJumpPress();
	virtual void OnUnsupported();
protected:
	const float sax;
	const float maxsx;

};