#include "PlayerJumping.h"
#include "PlayerRunning.h"

void PlayerJumping::OnUpdate()
{
	core.x += core.vx;
	core.y += core.vy;
	core.vy += ay;

	if (isMoving)
	{
		core.vx += core.dir.Transform(sax);
		core.vx = min(core.vx, maxsx);
		core.vx = max(core.vx, -maxsx);
	}
	else
	{
		core.vx *= sdx;
	}

	if (!isBoosting && core.vy < 0.0f)
	{
		core.vy *= sdy;
	}

	if (core.vy >= 0.0f)
	{
		core.currentSeq = core.seqs[3];
	}
}

void PlayerJumping::OnCollision( const float floorY)
{
	core.y = floorY;
	if (isMoving)
	{
		Transition(new PlayerRunning(core));
	}
	else
	{
		Transition(new PlayerStanding(core));
	}
}

void PlayerJumping::OnCtrlDirRelease(BiDirection d)
{

	if (core.dir == d)
	{
		isMoving = false;
	}
}

void PlayerJumping::OnCtrlDirPress(BiDirection d)
{
	core.dir = d;
	isMoving = true;

}

void PlayerJumping::OnCtrlJumpRelease()
{
	isBoosting = false;
}