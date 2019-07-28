#include "InputController.h"
#include "GamePadController.h"
#include "KeyboardController.h"
#include "MouseController.h"
#include "Defines.h"

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

void InputController::UpdateKeyboardKeys()
{
	keyboardController->UpdateInput();
}

void InputController::UpdateMouseKeys()
{
	mouseController->UpdateInput();
}


