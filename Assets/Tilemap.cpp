#include "Tilemap.h"

Tilemap::Tilemap(const char* map, int mapWidth, int mapHeight, int tileWidth, int tileHeight)
	:
	width(mapWidth),
	height(mapHeight)
{
	Tile::SetWidthAndHeight(tileWidth, tileHeight);
	tiles = new Tile*[mapWidth*mapHeight];
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
		{
			const int i = x + y*mapWidth;
			switch (map[i])
			{
			case ' ':
				tiles[i] = new Tile(x*tileWidth, y*tileHeight, true, D3DCOLOR_XRGB(0xE0, 0xE0, 0xE0));
					break;
			case '#':
				tiles[i] = new Tile(x*tileWidth, y*tileHeight, false, D3DCOLOR_XRGB(0, 0, 0));
				break;
			default:
				tiles[i] = NULL;
				break;
			}
		}
	}
}

Tilemap::~Tilemap()
{
	for (int i = 0; i < width*height; i++)
	{
		delete tiles[i];
	}
	delete [] tiles;

}

const void Tilemap::Draw(D3DGraphics &gfx)
{
	for (int i = 0; i < width*height; i++)
	{
		tiles[i]->Draw(gfx);
	}
}
