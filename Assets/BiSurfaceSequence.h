#pragma once

#include "SurfaceSequence.h"
#include "BiDirection.h"
class BiSurfaceSequence
{
public:

	BiSurfaceSequence(std::wstring basename, unsigned int nSurfaces, unsigned int nHoldFrames,
		int basex, int basey, D3DCOLOR key = D3DCOLOR_XRGB(255, 255, 255))
		:
	rightSeq(new SurfaceSequence(basename, nSurfaces, nHoldFrames, basex, basey, key)),
	leftSeq(rightSeq->CloneMirrored()),
	dir(BiDirection::MakeRight())
	{}
	void Draw(int x, int y,D3DGraphics& gfx) const
	{
		if (dir.IsRight())
		{
			rightSeq->Draw(x,y,gfx);
		}
		else if (dir.IsLeft())
		{
			leftSeq->Draw(x, y, gfx);
		}
	}
	void Advance()
	{
		if (dir.IsRight())
		{
			rightSeq->Advance();
		}
		else if (dir.IsLeft())
		{
			leftSeq->Advance();
		}
	}
	void SetDir(BiDirection d)
	{
		dir = d;
	}

protected:
	SurfaceSequence* leftSeq;
	SurfaceSequence* rightSeq;
	BiDirection dir;

};