#pragma once
#include "Tile.h"
#include "RectF.h"
#include "Sprite.h"

class Tilemap
{
public:
	Tilemap(const char* map, int mapWidth, int mapHeight, int tileWidth, int tileHeight);
	~Tilemap();
	const void Draw(D3DGraphics &gfx);
	void GetCRectList(RectF cRect, RectFList& list);
	bool GetCRectSingle(RectF cRect, RectF& rect);
	void DoCollision(Sprite& s);
private:
	Tile* GetTile(int ix, int iy) const
	{
		return tiles[ix + iy*width];
	}

private:
	Tile** tiles;
	const int width;
	const int height;
};