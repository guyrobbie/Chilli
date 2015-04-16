#pragma once

#include "SurfaceSequence.h"

class Tile
{
public:
	Tile(Surface* surface, int x, int y)
		:
		surface(surface),
		x(x),
		y(y)
	{}
	~Tile()
	{
		delete surface;
	}
	void Draw(D3DGraphics& gfx)
	{
		surface->Draw(x, y, gfx);
	}

private:
	int x, y;
	Surface* surface;
};
