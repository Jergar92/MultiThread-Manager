#ifndef _MODULE_INPUT
#define _MODULE_INPUT
#include "Module.h"
#include "Globals.h"
#include <list>
enum KeyState
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};
//Forward declarations
typedef struct _SDL_GameController SDL_GameController;
typedef struct _SDL_Joystick SDL_Joystick;
typedef struct _SDL_Haptic SDL_Haptic;

class ModuleInput :
	public Module
{
public:
	ModuleInput(bool enabled = true);
	virtual ~ModuleInput();

	bool Awake();
	UpdateStatus InputUpdate();
	bool CleanUp();

private:
	void UpdateKeyboardKeys();
	void UpdateMouseKeys();
private:


	struct GamePad
	{
		bool Empty();
		void Clear();
		SDL_GameController* controller = nullptr;
		SDL_Joystick* joystick = NULL;
		SDL_Haptic* haptic = NULL;
		int id = -1;
	};

	int mouseX = 0;
	int mouseY = 0;
	int mouseZ = 0;
	int mouseMotionX = 0;
	int mouseMotionY = 0;

	KeyState* keyboardKeys = nullptr;
	KeyState* mouseKeys = nullptr;
	std::list<GamePad*> gamePads;
	

	int gamePadsLimit = 4;
};

#endif //_MODULE_INPUT
