/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
 *	Keyboard.cpp																		  *
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
#include "Keyboard.h"
#include "windows.h"


KeyboardClient::KeyboardClient( KeyboardServer& kServer )
	: server( kServer )
{}

bool KeyboardClient::KeyIsPressed(unsigned char keycode) const
{
	return server.keyState[keycode];
}

void KeyboardClient::FlushBuffer()
{
	while (!server.keyBuffer.empty())
	{
		server.keyBuffer.pop();
	}
}


KeyboardServer::KeyboardServer()
{
	for (int x = 0; x < nKeys; x++)
	{
		keyState[x] = false;
	}
}

void KeyboardServer::OnKeyPressed(unsigned char keycode)
{
	keyState[keycode] = true;
	if (!keyState[VK_SHIFT])
	{
		if (keycode > 'A' && keycode < 'Z')
		{
			keycode = towlower(keycode);
		}
	}
	keyBuffer.push(keycode);
	
}

unsigned char KeyboardClient::ReadKey()
{
	unsigned char keycode = server.keyBuffer.front();
	server.keyBuffer.pop();
	return keycode;

}

unsigned char KeyboardClient::PeekKey()
{
	if (server.keyBuffer.size() > 0)
	{
		return server.keyBuffer.front();
	}
	else
	{
		return 0;
	}
}

void KeyboardServer::OnKeyReleased(unsigned char keycode)
{
	keyState[keycode] = false;
}

