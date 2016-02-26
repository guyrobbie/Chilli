#pragma once

#include "D3DGraphics.h"

#include <list>

class RectF
{
public:
	RectF() {}
	RectF(float top, float buttom, float left, float right)
		:
	top(top),
	buttom(buttom),
	left(left),
	right(right)
	{}
	RectF(const RectF& rect)
	:
	top(rect.top),
	buttom(rect.buttom),
	left(rect.left),
	right(rect.right)
	{}
	void Translate(float dx, float dy)
	{
		top += dy;
		buttom += dy;
		left += dx;
		right += dx;

	}
	void Draw(D3DGraphics& gfx) const
	{
		gfx.DrawLine( (int)left, (int)top, (int)right, (int)top, 255, 0, 0);
		gfx.DrawLine( (int)right, (int)top, (int)right, (int)buttom, 255, 0, 0);
		gfx.DrawLine( (int)left, (int)buttom, (int)right, (int)buttom, 255, 0, 0);
		gfx.DrawLine( (int)left, (int)top, (int)left, (int)buttom, 255, 0, 0);
	}
public:
	float top;
	float buttom;
	float left;
	float right;
};

typedef std::list< RectF > RectFList;