#include "InputController.h"
#include "GamePadController.h"
#include "KeyboardController.h"
#include "MouseController.h"
#include "Defines.h"
#include "SDL.h"
InputController::InputController()
{
	mouseController = new MouseController();
	keyboardController = new KeyboardController();

}


InputController::~InputController()
{
}

void InputController::UpdateInput()
{
	UpdateMouseKeys();
	UpdateKeyboardKeys();
}

void InputController::PollEvents(const SDL_Event & e)
{
	keyboardController->PollEvents(e);
	mouseController->PollEvents(e);	
}

bool InputController::CleanUp()
{ 
	if (keyboardController == nullptr && !keyboardController->CleanUp())
		return false;
	if (mouseController == nullptr && !mouseController->CleanUp())
		return false;

	RELEASE(keyboardController);
	RELEASE(mouseController);
	return true;
}

int InputController::GetMouseX() const
{
	return mouseController->GetMouseX();
}

int InputController::GetMouseY() const
{
	return mouseController->GetMouseY();
}

int InputController::GetMouseZ() const
{
	return mouseController->GetMouseZ();
}

int InputController::GetMouseXMotion() const
{
	return mouseController->GetMouseXMotion();
}

int InputController::GetMouseYMotion() const
{
	return mouseController->GetMouseYMotion();
}

bool InputController::GetMouseButtonDown(int id) const
{
	return mouseController->GetMouseButtonDown(id);
}

bool InputController::GetMouseButtonRepeat(int id) const
{
	return mouseController->GetMouseButtonDown(id);
}

bool InputController::GetMouseButtonUp(int id) const
{
	return mouseController->GetMouseButtonDown(id);
}

bool InputController::GetKeyDown(int id) const
{
	return keyboardController->GetKeyDown(id);
}

bool InputController::GetKeyRepeat(int id) const
{
	return keyboardController->GetKeyRepeat(id);
}

bool InputController::GetKeyUp(int id) const
{
	return keyboardController->GetKeyUp(id);
}



void InputController::UpdateKeyboardKeys()
{
	keyboardController->UpdateInput();
}

void InputController::UpdateMouseKeys()
{
	mouseController->UpdateInput();
}


