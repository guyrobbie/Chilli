#include "Tilemap.h"
#include "Sprite.h"
#include "SpriteState.h"

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

void Tilemap::GetCRectList(RectF cRect, RectFList& list)
{
	int ixEnd, iyEnd;

	for (int iy = Tile::GetIndexYBiasButtom(cRect.top), iyEnd = Tile::GetIndexYBiasTop(cRect.buttom);
		iy <= iyEnd ; iy++)
	{
		for (int ix = Tile::GetIndexXBiasRight(cRect.left), ixEnd = Tile::GetIndexXBiasLeft(cRect.right);
			ix <= ixEnd; ix++)
		{
			if ( !GetTile(ix, iy)->isPassable() )
			{
				list.push_back( Tile::GetCRect(ix, iy));
			}
		}
	}
	
}

bool Tilemap::GetCRectSingle(RectF cRect, RectF& rect)
{
	int ixEnd, iyEnd;

	for (int iy = Tile::GetIndexYBiasButtom(cRect.top), iyEnd = Tile::GetIndexYBiasTop(cRect.buttom);
		iy <= iyEnd; iy++)
	{
		for (int ix = Tile::GetIndexXBiasRight(cRect.left), ixEnd = Tile::GetIndexXBiasLeft(cRect.right);
			ix <= ixEnd; ix++)
		{
			if (!GetTile(ix, iy)->isPassable())
			{
				rect = Tile::GetCRect(ix, iy);
				return true;
			}
		}
	}
	return false;
}

void Tilemap::DoCollision(Sprite& s)
{
	RectF rect;
	while (GetCRectSingle(s.GetCRect(), rect))
	{
		s.GetState().OnCollision(rect);
	}
	RectFList list;
	
	for (RectFList::iterator i = list.begin(), end = list.end();
		i != end; i++)
	{
		GetCRectList(s.GetCRect(), list);
	}
	

}