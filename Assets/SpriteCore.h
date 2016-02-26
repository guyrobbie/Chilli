#pragma once
#include "BiSurfaceSequence.h"
#include "RectF.h"

class SpriteCore
{
public:
	RectF GetCRect() const
	{
		RectF rect(cRect);
		rect.Translate(x, y);
		return rect;
	}
public:
	float x, y;
	float vx, vy;
	BiSurfaceSequence* currentSeq;
	BiSurfaceSequence** seqs;
	class SpriteState* state;
	BiDirection dir;
	RectF cRect;
};