#ifndef _GAME_PAD_CONTROLLER
#define _GAME_PAD_CONTROLLER
#include "Globals.h"
//Forward declarations
typedef struct _SDL_GameController SDL_GameController;
typedef struct _SDL_Joystick SDL_Joystick;
typedef struct _SDL_Haptic SDL_Haptic;

class GamePadController
{
public:
	GamePadController();
	~GamePadController();
	void UpdateInput();

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
};
#endif


