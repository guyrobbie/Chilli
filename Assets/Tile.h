#pragma once
#include "D3DGraphics.h"
#include "Surface.h"
#include "RectF.h"

class Tile
{
public:
	Tile(int x, int y, bool passable, D3DCOLOR color);
	virtual ~Tile();
	void Draw(D3DGraphics &gfx) const;
	bool isPassable() const
	{
		return passable;
	}
public:
	static void SetWidthAndHeight(int w, int h){ width = w; height = h; };
	static int GetIndexXBiasRight(float x){ return x / width; }
	static int GetIndexXBiasLeft(float x)
	{
		int ix = (int)x / width;
		if ((float)ix*width == x)
		{
			ix--;
		}
		return ix;
	}
	static int GetIndexYBiasButtom(float y){ return y / width; }
	static int GetIndexYBiasTop(float y)
	{
		int iy = (int)y / height;
		if ((float)iy*height == y)
		{
			iy--;
		}
		return iy;
	}
	static RectF GetCRect(int ix, int iy)
	{
		return RectF((float)iy*height, (float)(iy+1)*height , 
			(float)ix*width, (float)(ix+1)*width );
	}

private:
	int x;
	int y;
	D3DCOLOR color;
	static int width;
	static int height;
	bool passable;
};