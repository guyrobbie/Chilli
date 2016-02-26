#pragma once
#include "BiSurfaceSequence.h"

class SpriteCore
{
public:
	float x, y;
	float vx, vy;
	BiSurfaceSequence* currentSeq;
	BiSurfaceSequence** seqs;
	class SpriteState* state;
	BiDirection dir;
};