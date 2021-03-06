/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.10.21											  *	
 *	Game.cpp																			  *
 *	Copyright 2012 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <float.h>


Game::Game( HWND hWnd,KeyboardServer& kServer,const MouseServer& mServer )
:	gfx( hWnd ),
	audio( hWnd ),
	kbd( kServer ),
	mouse( mServer ),
	t(testMap, MAPWIDTH, MAPHEIGHT, TILESIZE, TILESIZE),
	c(p,kbd)
{
	srand( (unsigned int)time( NULL ) );
}

Game::~Game()
{
}

void Game::Go()
{
	c.Poll();
	p.GetState().OnUpdate();
	t.DoCollision(p);
	t.DoSupport(p);
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame()
{
	t.Draw(gfx);
	RectFList list;
	t.GetCRectList(p.GetCRect(), list);

	for (RectFList::iterator i = list.begin(), end = list.end();
		i != end; i++)
	{
		i->Draw(gfx);
	}
	p.Draw(gfx);
}