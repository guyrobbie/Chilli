#pragma once

#include "SurfaceSequence.h"
#include "BiDirection.h"
class BiSurfaceSequence
{
public:

	BiSurfaceSequence(std::wstring basename, unsigned int nSurfaces, unsigned int nHoldFrames,
	int basex, int basey, D3DCOLOR key = D3DCOLOR_XRGB(255, 255, 255))
		:
	rightSeq(new SurfaceSequence(basename, nSurfaces, nHoldFrames, basex, basey, key))
	{
		leftSeq = rightSeq->CloneMirrored();
	}
	~BiSurfaceSequence()
	{
		delete leftSeq;
		delete rightSeq;
	}
	void Draw(int x, int y, BiDirection d,D3DGraphics& gfx) const
	{
		if (d.IsRight())
		{
			rightSeq->Draw(x,y,gfx);
		}
		else if (d.IsLeft())
		{
			leftSeq->Draw(x, y, gfx);
		}
	}
	void Advance(BiDirection d)
	{
		if (d.IsRight())
		{
			rightSeq->Advance();
		}
		else if (d.IsLeft())
		{
			leftSeq->Advance();
		}
	}

protected:
	SurfaceSequence* leftSeq;
	SurfaceSequence* rightSeq;
};