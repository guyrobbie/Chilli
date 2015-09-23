#include "PlayerStanding.h"
#include "PlayerRunning.h"
#include "PlayerJumping.h"

void PlayerStanding::OnCtrlDirPress(BiDirection d)
{
	core.dir = d;
	Transition(new PlayerRunning(core));
}

void PlayerStanding::OnCtrlJump()
{
	Transition(new PlayerJumping((core), 0.0f, false));
}
