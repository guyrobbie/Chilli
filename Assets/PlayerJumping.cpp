#include "PlayerJumping.h"
#include "PlayerRunning.h"

void PlayerJumping::OnUpdate()
{
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

	core.x += core.vx;
	core.y += core.vy;

	if (core.vy >= 0.0f)
	{
		core.currentSeq = core.seqs[3];
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

void PlayerJumping::OnCollision(const RectF& rect)
{
	RectF sRect = core.GetCRect();
	if (core.vx > 0)
	{
		if (core.vy > 0)
		{
			float px = sRect.right - rect.left;
			float py = sRect.buttom - rect.top;

			if (core.vy*px > core.vx*py)
			{
				// top collision
				core.vy = 0.0f;
				core.y -= py;
				if (isMoving)
				{
					Transition(new PlayerRunning(core));
				}
				else
				{
					Transition(new PlayerStanding(core));
				}
			}
			else // core.vy*px < core.vx*py
			{
				// side collision
				core.vx = 0.0f;
				core.x -= px;
			}
		}
		else // core.vy < 0
		{
			float px = sRect.right - rect.left;
			float py = rect.buttom - sRect.top;

			if ( (-core.vy)*px > core.vx*py)
			{
				// top collision
				core.vy = 0.0f;
				core.y += py;
			}
			else // core.vy*px < core.vx*py
			{
				// side collision
				core.vx = 0.0f;
				core.x -= px;
			}
		}
	}
	else // core.vx < 0
	{
		if (core.vy > 0)
		{
			float px = rect.right - sRect.left;
			float py = sRect.buttom - rect.top;

			if (core.vy*px > (-core.vx)*py)
			{
				// top collision
				core.vy = 0.0f;
				core.y -= py;
				if (isMoving)
				{
					Transition(new PlayerRunning(core));
				}
				else
				{
					Transition(new PlayerStanding(core));
				}
			}
			else // core.vy*px < core.vx*py
			{
				// side collision
				core.vx = 0.0f;
				core.x += px;
			}
		}
		else // core.vy < 0
		{
			float px = rect.right - sRect.left;
			float py = rect.buttom - sRect.top;

			if ((-core.vy)*px > (-core.vx)*py)
			{
				// top collision
				core.vy = 0.0f;
				core.y += py;
			}
			else // core.vy*px < core.vx*py
			{
				// side collision
				core.vx = 0.0f;
				core.x += px;
			}
		}
	}

}