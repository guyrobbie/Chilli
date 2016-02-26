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
		core.vx = 0.0f;
		core.vy = 0.0f;
		core.seqs = new BiSurfaceSequence*[4];
		core.seqs[0] = new BiSurfaceSequence(std::wstring(L"StickStand\\Stand"), 1, 60,12,60);
		core.seqs[1] = new BiSurfaceSequence(std::wstring(L"StickRun\\Run"), 13, 4, 30, 58);
		core.seqs[2] = new BiSurfaceSequence(std::wstring(L"StickJump\\Jump"), 1, 60, 16, 72);
		core.seqs[3] = new BiSurfaceSequence(std::wstring(L"StickFall\\Fall"), 1, 60, 32, 62);
		core.state = new PlayerStanding(core);
		core.dir.SetRight();
		
	}
	virtual ~PlayerSprite()
	{
		delete core.seqs[0];
		delete core.seqs[1];
		delete core.seqs[2];
		delete core.seqs[3];
		delete[] core.seqs;
		delete core.state;
	}

};