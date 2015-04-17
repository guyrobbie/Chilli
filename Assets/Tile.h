#pragma once
#include "D3DGraphics.h"
#include "Surface.h"

class Tile
{
public:
	Tile(int x, int y, bool passable, D3DCOLOR color);
	virtual ~Tile();
	const void Draw(D3DGraphics &gfx);
	static void SetWidthAndHeight(int w, int h){ width = w; height = h; };
	
private:
	int x;
	int y;
	D3DCOLOR color;
	static int width;
	static int height;
	bool passable;
};