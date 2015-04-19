#pragma once
#include "SurfaceSequence.h"

class SpriteCore
{
public:
	float x, y;
	SurfaceSequence* currentSeq;
	SurfaceSequence** seqs;
	class SpriteState* state;
};