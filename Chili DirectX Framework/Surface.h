#pragma once

#include "D3DGraphics.h"

class Surface
{
public:
	Surface();
private:
	unsigned int width;
	unsigned int height;
	D3DCOLOR* surface;
};