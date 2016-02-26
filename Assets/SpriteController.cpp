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
			{
				sprite.GetState().OnCtrlDirPress(BiDirection::MakeRight());
			}
			else if (e.IsRelease())
			{
				sprite.GetState().OnCtrlDirRelease(BiDirection::MakeRight());
			}
			break;
		case VK_LEFT:
			if (e.IsPressed())
			{
				sprite.GetState().OnCtrlDirPress(BiDirection::MakeLeft());
			}
			else if (e.IsRelease())
			{
				sprite.GetState().OnCtrlDirRelease(BiDirection::MakeLeft());
			}
			break;
		case VK_SPACE:
			if (e.IsPressed())
			{
				sprite.GetState().OnCtrlJumpPress();
			}			
			else if (e.IsRelease())
			{
				sprite.GetState().OnCtrlJumpRelease();
			}
			break;
		}
	}
}