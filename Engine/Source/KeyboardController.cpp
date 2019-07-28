#include "KeyBoardController.h"
#include "InputEnum.h"
#include "SDL.h"
#include "Globals.h"
#include "Defines.h"
#define MAX_KEYBOARD_KEYS 300

KeyboardController::KeyboardController()
{
	keyboardKeys = new KeyState[MAX_KEYBOARD_KEYS];

	memset(keyboardKeys, KEY_IDLE, sizeof(KeyState)*MAX_KEYBOARD_KEYS);

}


KeyboardController::~KeyboardController()
{
}

void KeyboardController::UpdateInput()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	for (unsigned int i = 0; i < MAX_KEYBOARD_KEYS; ++i)
	{
		if (keyboardKeys[i] == 1)
		{
			if (keyboardKeys[i] == KeyState::KEY_IDLE)
			{
				keyboardKeys[i] = KeyState::KEY_DOWN;
			}
			else
			{
				keyboardKeys[i] = KeyState::KEY_REPEAT;
			}
		}
		else
		{
			if (keyboardKeys[i] == KeyState::KEY_DOWN || keyboardKeys[i] == KeyState::KEY_REPEAT)
			{
				keyboardKeys[i] = KeyState::KEY_UP;
			}
			else
			{
				keyboardKeys[i] = KeyState::KEY_IDLE;
			}
		}
	}
}

bool KeyboardController::CleanUp()
{
	RELEASE(keyboardKeys)
	return true;
}
