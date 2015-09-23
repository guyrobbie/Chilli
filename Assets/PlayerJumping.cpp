#include "PlayerJumping.h"
#include "PlayerRunning.h"

void PlayerJumping::OnUpdate()
{
	core.x += core.dir.Transform(sx);
	core.y += vy;
	vy += ay;
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
	if (core.dir == d)
	{
		isMoving = true;
	}
}
