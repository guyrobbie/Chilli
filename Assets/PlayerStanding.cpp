#include "PlayerStanding.h"
#include "PlayerRunning.h"

void PlayerStanding::OnCtrlRightDown()
{
	core->state = new  PlayerRunning(core);
	delete this;
}