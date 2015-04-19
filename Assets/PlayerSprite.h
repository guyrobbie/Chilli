#pragma once
#include "Sprite.h"
#include "PlayerStanding.h"
class PlayerSprite : public Sprite
{
public:
	PlayerSprite()
	{
		core.x = 100;
		core.y = 575;
		core.seqs = new SurfaceSequence*[2];
		core.seqs[0] = new SurfaceSequence(std::wstring(L"StickStand\\Stand"), 1, 60,12,60);
		core.seqs[1] = new SurfaceSequence(std::wstring(L"StickRun\\Run"), 13, 4, 30, 58);
		core.state = new PlayerStanding(&core);
		
	}
	virtual ~PlayerSprite()
	{
		delete core.seqs[0];
		delete core.seqs[1];
		delete[] core.seqs;
		delete core.state;
	}

};