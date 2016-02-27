#pragma once
#include "SpriteCore.h"
#include "RectF.h"

class Sprite
{
public:
	void Draw(D3DGraphics& gfx) const;
	virtual ~Sprite() {}
	SpriteState& GetState() { return *(core.state); }
	RectF GetCRect() const
	{
		return core.GetCRect();
	}
	float GetVX() const { return core.vx; }
	float GetVY() const { return core.vy; }
	//just for now
	float GetY() const
	{
		return core.y;
	}
protected:
	SpriteCore core;
};