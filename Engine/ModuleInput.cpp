#include "ModuleInput.h"
#include "Defines.h"
#include "SDL.h"
#define MAX_KEYBOARD_KEYS 300
#define MAX_MOUSE_KEYS 300


ModuleInput* ModuleInput::_instance = nullptr;

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
