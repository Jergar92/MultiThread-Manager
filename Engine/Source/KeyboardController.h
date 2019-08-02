#ifndef _KEYBOARD_CONTROLLER
#define _KEYBOARD_CONTROLLER
enum KeyState;
union SDL_Event;
class KeyboardController
{
public:
	KeyboardController();
	~KeyboardController();
	void UpdateInput();
	void PollEvents(const SDL_Event& e);
	bool CleanUp();

	bool GetKeyDown(int id) const;
	bool GetKeyRepeat(int id) const;
	bool GetKeyUp(int id) const;
private:
	KeyState* keyboardKeys = nullptr;

};

#endif

