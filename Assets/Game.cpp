/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
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

extern FrameTimer timer;

Game::Game( HWND hWnd, KeyboardServer& kServer,const MouseServer& mServer )
:	gfx( hWnd ),
	audio( hWnd ),
	kbd( kServer ),
	mouse( mServer )
{
	srand( time( NULL ) );
	
	LoadAnimatedSprite( &dudeTemplate,
		DUDEFILENAME,DUDEWIDTH,DUDEHEIGHT,DUDEKEYCOLOR,DUDENFRAMES,DUDEFRAMETIME );
	
	for( int index = 0; index < NDUDES; index++ )
	{
		CreateSpriteInstance( &dudeTemplate,&dudes[ index ] );
		dudes[ index ].x = rand() % (800 - dudeTemplate.frames[ 0 ].width);
		dudes[ index ].y = rand() % (600 - dudeTemplate.frames[ 0 ].height);
		dudes[ index ].currentFrame = rand() % dudeTemplate.nFrames;
	}

	LoadFont( &fixedSys,fontSurf,"fixedsys16x28.bmp",16,28,32 );

	LoadSprite( &backgroundSprite,"badhaircut.bmp",800,600,D3DCOLOR_XRGB( 255,0,255 ) );

	LoadSpriteAlpha( &alphaSprite );

	textBuffer[0] = 0;
}

Game::~Game()
{
	FreeSprite( &alphaSprite );
	FreeSprite( &backgroundSprite );
	FreeAnimatedSprite( &dudeTemplate );
}

void Game::LoadAnimatedSprite( AnimatedSpriteTemplate* templat,
	const char* basename,int width,int height,D3DCOLOR key,int nFrames,int frameDuration )
{
	templat->frames = (Sprite*)malloc( sizeof( Sprite ) * nFrames );

	for( int index = 0; index < nFrames; index++ )
	{
		char fileNameBuffer[ 64 ];
		sprintf( fileNameBuffer,"%s%.2d.bmp",basename,index );
		LoadSprite( &templat->frames[ index ],fileNameBuffer,width,height,key );
	}

	templat->nFrames = nFrames;
	templat->frameDuration = frameDuration;
}

void Game::FreeAnimatedSprite( AnimatedSpriteTemplate* templat )
{
	for( int index = 0; index < templat->nFrames; index++ )
	{
		FreeSprite( &templat->frames[ index ] );
	}

	free( templat->frames );
}

void Game::CreateSpriteInstance( AnimatedSpriteTemplate* templat,AnimatedSpriteInstance* instance )
{
	instance->templat = templat;
	instance->currentFrameExposure = 0;
	instance->currentFrame = 0;
	instance->x = 0.0f;
	instance->y = 0.0f;
}

void Game::UpdateAnimation( AnimatedSpriteInstance* instance )
{
	instance->currentFrameExposure++;
	if( instance->currentFrameExposure >= instance->templat->frameDuration )
	{
		instance->currentFrame++;
		instance->currentFrame %= instance->templat->nFrames;
		instance->currentFrameExposure = 0;
	}
}

void Game::DrawSpriteInstance( AnimatedSpriteInstance* instance )
{
	gfx.DrawSprite( (int)instance->x,(int)instance->y,
		&instance->templat->frames[ instance->currentFrame ] );
}

void Game::Go()
{
	for( int index = 0; index < NDUDES; index++ )
	{
		dudes[ index ].x += DUDESPEED;
		if( dudes[ index ].x + DUDEWIDTH >= 800 )
		{
			dudes[ index ].x = 0;
			dudes[ index ].y = rand() % (600 - dudes[ index ].templat->frames[ 0 ].height);
		}
		UpdateAnimation( &dudes[ index ] );

		while (kbd.PeekKey())
		{
			unsigned char keypress = kbd.ReadKey();
			if (keypress >= 'a' && keypress <= 'z' || keypress >= 'A' && keypress <= 'Z')
			{
				int len = strlen(textBuffer);
				textBuffer[len] = keypress;
				textBuffer[len+1] = 0;
			}
		}
		
	}



	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame()
{	
	//timer.StartFrame();
	//gfx.DrawSprite( 0,0,&backgroundSprite );
	
	for( int index = 0; index < NDUDES; index++ )
	{
		DrawSpriteInstance( &dudes[ index ] );
	}

	gfx.DrawSpriteAlpha( 200,200,&alphaSprite );
	//timer.StopFrame();

	char buffer[ 64 ];
	sprintf( buffer,"# of sprites: %d | Average render time: %.2f",NDUDES,timer.GetAvg() );
	gfx.DrawString( buffer,0,0,&fixedSys,D3DCOLOR_XRGB( 255,0,0 ) );
	sprintf(buffer, "Min render time: %.2f | Max render time: %.2f", timer.GetMin(), timer.GetMax());
	gfx.DrawString( buffer,0,28,&fixedSys,D3DCOLOR_XRGB( 255,0,0 ) );
	gfx.DrawString(textBuffer, 0, 50, &fixedSys, D3DCOLOR_XRGB(0, 0, 255));
}