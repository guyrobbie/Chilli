#include "PlayerStanding.h"
#include "PlayerRunning.h"
#include "PlayerJumping.h"

void PlayerStanding::OnUpdate()
{
	core.x += core.vx;
	core.vx *= sdx;
}

void PlayerStanding::OnCtrlDirPress(BiDirection d)
{
	core.dir = d;
	Transition(new PlayerRunning(core));
}

void PlayerStanding::OnCtrlJumpPress()
{
	Transition(new PlayerJumping((core), false));
}