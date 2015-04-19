#include "SpriteController.h"

void SpriteController::Poll()
{
	while (!kbd.KeyEmpty())
	{
		KeyEvent e = kbd.ReadKey();
		switch (e.GetCode())
		{
		case VK_RIGHT:
			if (e.IsPressed())
				sprite.GetState().OnCtrlRightDown();
			else if (e.IsRelease())
				sprite.GetState().OnCtrlRightUp();
			break;
		}
	}
}