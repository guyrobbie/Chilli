#include "PlayerRunning.h"

void PlayerRunning::OnCtrlRightDown()
{}

void PlayerRunning::OnCtrlRightUp()
{
	core->state = new  PlayerStanding(core);
	delete this;
}


void PlayerRunning::OnUpdate()
{
	core->x += 2.0f;
	core->currentSeq->Advance();
}
