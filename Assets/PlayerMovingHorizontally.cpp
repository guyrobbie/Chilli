#include "PlayerMovingHorizontally.h"

void PlayerMovingHorizontally::OnCollision(const RectF& rect)
{
	if (core.vx > 0)
	{
		core.x -= core.GetCRect().right - rect.left;
		core.vx = 0.0f;
	}

	else if (core.vx < 0)
	{
		core.x += rect.right - core.GetCRect().left;
		core.vx = 0.0f;
	}
}