#include "Tile.h"

int Tile::width;
int Tile::height;


Tile::Tile(int x, int y, bool passable, D3DCOLOR color)
	:
	x(x),
	y(y),
	color(color),
	passable(passable)
{}

Tile::~Tile()
{}

void Tile::Draw(D3DGraphics &gfx) const
{
	// Was too lazy to write a method in Graphics to Draw Rectangle.
	for (int iy = y; iy < y + height; iy++)
	{
		for (int ix = x; ix < x + width; ix++)
		{
			gfx.PutPixel(ix, iy, color);
		}
	}
}