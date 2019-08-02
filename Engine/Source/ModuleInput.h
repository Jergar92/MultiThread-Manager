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

class InputController;
class ModuleInput :
	public Module
{
public:
	ModuleInput(bool enabled = true);
	~ModuleInput();

	bool Awake();
	UpdateStatus InputUpdate();
	bool CleanUp();


private:
	InputController* inputController = nullptr;





	

};

#endif //_MODULE_INPUT
