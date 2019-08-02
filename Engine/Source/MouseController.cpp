#include "MouseController.h"
#include "Globals.h"
#include "InputEnum.h"
#include "SDL.h"
#include "Defines.h"
#define MAX_MOUSE_KEYS 5


MouseController::MouseController()
{
	mouseKeys = new KeyState[MAX_MOUSE_KEYS];

	memset(mouseKeys, KEY_IDLE, sizeof(KeyState)*MAX_MOUSE_KEYS);

}


MouseController::~MouseController()
{
}

void MouseController::UpdateInput()
{
	const Uint32 keys = SDL_GetMouseState(&mouseX, &mouseY);

	mouseZ = 0;


	for (unsigned int i = 0; i < MAX_MOUSE_KEYS; ++i)
	{
		if (SDL_BUTTON(i))
		{
			if (mouseKeys[i] == KeyState::KEY_IDLE)
			{
				mouseKeys[i] = KeyState::KEY_DOWN;
			}
			else
			{
				mouseKeys[i] = KeyState::KEY_REPEAT;
			}
		}
		else
		{
			if (mouseKeys[i] == KeyState::KEY_DOWN || mouseKeys[i] == KeyState::KEY_REPEAT)
			{
				mouseKeys[i] = KeyState::KEY_UP;
			}
			else
			{
				mouseKeys[i] = KeyState::KEY_IDLE;
			}
		}
	}

}

void MouseController::PollEvents(const SDL_Event& e)
{
}

bool MouseController::CleanUp()
{
	RELEASE(mouseKeys)
	return true;
}

int MouseController::GetMouseX() const
{
	return mouseX;
}

int MouseController::GetMouseY() const
{
	return mouseY;
}

int MouseController::GetMouseZ() const
{
	return mouseZ;
}

int MouseController::GetMouseXMotion() const
{
	return mouseMotionX;
}

int MouseController::GetMouseYMotion() const
{
	return mouseMotionY;
}

bool MouseController::GetMouseButtonDown(int id) const
{
	if (id<0 || id>MAX_MOUSE_KEYS)
		return false;
	return mouseKeys[id] == KEY_DOWN;
}

bool MouseController::GetMouseButtonRepeat(int id) const
{
	if (id<0 || id>MAX_MOUSE_KEYS)
		return false;
	return  mouseKeys[id] == KEY_REPEAT;
}

bool MouseController::GetMouseButtonUp(int id) const
{
	if (id<0 || id>MAX_MOUSE_KEYS)
		return false;
	return  mouseKeys[id] == KEY_UP;
}

