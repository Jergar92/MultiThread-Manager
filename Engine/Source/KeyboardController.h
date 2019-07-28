#ifndef _KEYBOARD_CONTROLLER
#define _KEYBOARD_CONTROLLER
enum KeyState;
class KeyboardController
{
public:
	KeyboardController();
	~KeyboardController();
	void UpdateInput();
	bool CleanUp();
private:
	KeyState* keyboardKeys = nullptr;

};

#endif

