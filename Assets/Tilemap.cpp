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

bool Tilemap::GetCRectSingle(RectF cRect, RectF& rect, float vx, float vy)
{
	if (vx > 0.0f)
	{
		if (vy > 0.0f)
		{
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

		}
		else
		{
			for (int iy = Tile::GetIndexYBiasTop(cRect.buttom), iyEnd = Tile::GetIndexYBiasButtom(cRect.top);
				iy >= iyEnd; iy--)
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

		}
	}
	else
	{
		if (vy > 0.0f)
		{
			for (int iy = Tile::GetIndexYBiasButtom(cRect.top), iyEnd = Tile::GetIndexYBiasTop(cRect.buttom);
				iy <= iyEnd; iy++)
			{
				for (int ix = Tile::GetIndexXBiasLeft(cRect.right), ixEnd = Tile::GetIndexXBiasRight(cRect.left);
					ix >= ixEnd; ix--)
				{
					if (!GetTile(ix, iy)->isPassable())
					{
						rect = Tile::GetCRect(ix, iy);
						return true;
					}
				}
			}

		}
		else
		{
			for (int iy = Tile::GetIndexYBiasTop(cRect.buttom), iyEnd = Tile::GetIndexYBiasButtom(cRect.top);
				iy >= iyEnd; iy--)
			{
				for (int ix = Tile::GetIndexXBiasLeft(cRect.right), ixEnd = Tile::GetIndexXBiasRight(cRect.left);
					ix >= ixEnd; ix--)
				{
					if (!GetTile(ix, iy)->isPassable())
					{
						rect = Tile::GetCRect(ix, iy);
						return true;
					}
				}
			}

		}
	}
	return false;
}

void Tilemap::DoCollision(Sprite& s)
{
	RectF rect;
	while (GetCRectSingle(s.GetCRect(), rect, s.GetVX(), s.GetVY()))
	{
		s.GetState().OnCollision(rect);
	}
}

void Tilemap::DoSupport(Sprite& s)
{
	RectF cRect = s.GetCRect();
	int iy = Tile::GetIndexYBiasButtom(cRect.buttom);

	for (int ix = Tile::GetIndexXBiasRight(cRect.left), ixEnd = Tile::GetIndexXBiasLeft(cRect.right);
		ix <= ixEnd; ix++)
	{
		if (!GetTile(ix, iy)->isPassable() &&
			Tile::GetCRect(ix, iy).top == cRect.buttom )
		{
			return;
		}
	}
	s.GetState().OnUnsupported();
}