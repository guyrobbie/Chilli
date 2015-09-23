#include "PlayerRunning.h"
#include "PlayerJumping.h"

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
void PlayerRunning::OnCtrlJump()
{
	Transition(new PlayerJumping(core, sx,true));
}

void PlayerRunning::OnUpdate()
{
	core.x += core.dir.Transform(sx);
	core.currentSeq->Advance(core.dir);
}
