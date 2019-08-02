#include "ModuleInput.h"
#include "Defines.h"
#include "SDL.h"
#include "InputController.h"
#define MAX_KEYBOARD_KEYS 300
#define MAX_MOUSE_KEYS 5



ModuleInput::ModuleInput(bool startEnabled) :Module(startEnabled)
{
	_name = "Window";

	inputController = new InputController();
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

	inputController->UpdateInput();
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		inputController->PollEvents(e);
	}
	return UpdateStatus::UPDATE_CONTINUE;
}

bool ModuleInput::CleanUp()
{
	if(inputController ==nullptr &&!inputController->CleanUp())
		return false;

	RELEASE(inputController);
	return true;
}

