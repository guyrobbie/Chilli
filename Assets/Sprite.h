#pragma once
#include "SpriteCore.h"

class Sprite
{
public:
	void Draw(D3DGraphics& gfx) const;
	virtual ~Sprite() {}
	SpriteState& GetState() { return *core.state; }
protected:
	SpriteCore core;
};