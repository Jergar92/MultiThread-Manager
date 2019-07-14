#include "ModuleInput.h"
#include "Defines.h"
#include "SDL.h"

#define MAX_KEYBOARD_KEYS 300
#define MAX_MOUSE_KEYS 300



ModuleInput::ModuleInput(bool startEnabled) :Module(startEnabled)
{
	_name = "Window";

	keyboardKeys = new KeyState[MAX_KEYBOARD_KEYS];
	mouseKeys = new KeyState[MAX_MOUSE_KEYS];

	memset(keyboardKeys, KEY_IDLE, sizeof(KeyState)*MAX_KEYBOARD_KEYS);
	memset(mouseKeys, KEY_IDLE, sizeof(KeyState)*MAX_MOUSE_KEYS);

}


ModuleInput::~ModuleInput()
{

}

bool ModuleInput::Awake()
{
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_InitSubSystem fails");
		return false;
	}
	return true;
}

UpdateStatus ModuleInput::InputUpdate()
{
	SDL_PumpEvents();

	UpdateKeyboardKeys();
	UpdateMouseKeys();

	return UpdateStatus::UPDATE_CONTINUE;
}

bool ModuleInput::CleanUp()
{
	if (keyboardKeys == nullptr || mouseKeys == nullptr)
	{
		LOG("ERROR Keyboard or Mouse are nullptr");
		return false;
	}
	RELEASE_ARRAY(keyboardKeys);
	RELEASE_ARRAY(mouseKeys);

	return true;
}

void ModuleInput::UpdateKeyboardKeys()
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

void ModuleInput::UpdateMouseKeys()
{
	const Uint32 keys = SDL_GetMouseState(&mouseX, &mouseY);
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

bool ModuleInput::GamePad::Empty()
{
	return false;
}

void ModuleInput::GamePad::Clear()
{
}
