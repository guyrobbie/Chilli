#pragma once
#include "Tile.h"

class Tilemap
{
public:
	Tilemap(const char* map, int mapWidth, int mapHeight, int tileWidth, int tileHeight);
	~Tilemap();
	const void Draw(D3DGraphics &gfx);

private:
	Tile** tiles;
	const int width;
	const int height;
};