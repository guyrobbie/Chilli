#pragma once

#include "SpriteState.h"
#include "PlayerStanding.h"

class PlayerRunning : public SpriteState
{
public:
	PlayerRunning(SpriteCore* core)
		:
		SpriteState(core)
	{
		core->currentSeq = core->seqs[1];
	}
	virtual void OnCtrlRightDown();
	virtual void OnCtrlRightUp();
	virtual void OnUpdate();

};