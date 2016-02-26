#include "Sprite.h"

void Sprite::Draw(D3DGraphics& gfx) const
{
	core.currentSeq->Draw(core.x, core.y, core.dir,gfx);
	core.GetCRect().Draw(gfx);
}