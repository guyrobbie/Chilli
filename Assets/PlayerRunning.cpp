#include "PlayerRunning.h"
#include "PlayerJumping.h"

void PlayerRunning::OnUpdate()
{
	
	
	core.vx += core.dir.Transform(sax);
	core.vx = min(core.vx, maxsx);
	core.vx = max(core.vx, -maxsx);
	
	core.x += core.vx;

	core.currentSeq->Advance(core.dir);
}

void PlayerRunning::OnCtrlDirRelease(BiDirection d)
{
	if (core.dir == d)
	{
		Transition(new PlayerStanding(core));
	}
}

void PlayerRunning::OnCtrlDirPress(BiDirection d)
{
	core.dir = d;
}

void PlayerRunning::OnCtrlJumpPress()
{
	Transition(new PlayerJumping(core, true));
}

