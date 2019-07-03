#ifndef _MODULE_INPUT
#define _MODULE_INPUT
#include "Module.h"
#include "Globals.h"
enum KeyState
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput :
	public Module
{
public:
	ModuleInput(bool enabled = true);
	virtual ~ModuleInput();

	bool Awake();
	UpdateStatus InputUpdate();
	bool CleanUp();
	static ModuleInput* GetInstance(bool enabled = true)
	{
		if (_instance == nullptr)
		{
			_instance = new ModuleInput(enabled);
		}
		return _instance;
	}
private:
	int mouseX = 0;
	int mouseY = 0;
	int mouseZ = 0;
	int mouseMotionX = 0;
	int mouseMotionY = 0;

	KeyState* keyboardKeys = nullptr;
	KeyState* mouseKeys = nullptr;
	static ModuleInput* _instance;

};
#endif //_MODULE_INPUT
