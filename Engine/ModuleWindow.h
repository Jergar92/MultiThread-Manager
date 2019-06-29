#ifndef _MODULE_WINDOW
#define _MODULE_WINDOW
#include "Module.h"

class ModuleWindow :public Module
{
public:
	ModuleWindow(bool startEnabled = true);
	virtual ~ModuleWindow();

	static ModuleWindow* GetInstance(bool enabled = true)
	{
		if (_instance == nullptr)
		{
			_instance = new ModuleWindow(enabled);
		}
		return _instance;
	}


private:
	static ModuleWindow* _instance;

};

#endif //_MODULE_WINDOW