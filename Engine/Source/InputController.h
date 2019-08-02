#ifndef _INPUT_CONTROLLER
#define _INPUT_CONTROLLER

class KeyboardController;
class MouseController;
class GamePadController;
union SDL_Event;

class InputController
{
public:
	InputController();
	~InputController();
	void UpdateInput();
	void PollEvents(const SDL_Event& e);

	bool CleanUp();

	//Mouse Getters
	int GetMouseX() const;
	int GetMouseY() const;
	int GetMouseZ() const;
	int GetMouseXMotion() const;
	int GetMouseYMotion() const;
	bool GetMouseButtonDown(int id) const;
	bool GetMouseButtonRepeat(int id) const;
	bool GetMouseButtonUp(int id) const;
	//Keyboard Getters
	bool GetKeyDown(int id) const;
	bool GetKeyRepeat(int id) const;
	bool GetKeyUp(int id) const;

private:
	void UpdateKeyboardKeys();
	void UpdateMouseKeys();
private:
	KeyboardController* keyboardController = nullptr;
	MouseController* mouseController = nullptr;
	GamePadController* gamePadController = nullptr;

};
#endif


