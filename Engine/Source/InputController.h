#ifndef _INPUT_CONTROLLER
#define _INPUT_CONTROLLER

class KeyboardController;
class MouseController;
class GamePadController;

class InputController
{
public:
	InputController();
	~InputController();
	void UpdateInput();
	bool CleanUp();
private:
	void UpdateKeyboardKeys();
	void UpdateMouseKeys();
private:
	KeyboardController* keyboardController = nullptr;
	MouseController* mouseController = nullptr;
	GamePadController* gamePadController = nullptr;

};
#endif


