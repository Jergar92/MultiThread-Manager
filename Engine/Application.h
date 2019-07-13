#ifndef _APPLICATION
#define _APPLICATION
#include <list>
#include "Globals.h"
class Module;
class ModuleInput;
class ModuleWindow;
class Application
{
public:
	Application();
	~Application();

	bool Awake();
	bool Start();
	UpdateStatus Update();
	bool CleanUp();

	static Application* GetInstance(bool enabled = true)
	{
		if (_instance == nullptr)
		{
			_instance = new Application();
		}
		return _instance;
	}
	ModuleInput* GetModuleInput();
	ModuleWindow* GetModuleWindow();

private:

	void AddModule(Module* module);
private:
	std::list<Module*> _modules;

	ModuleInput* moduleInput = nullptr;
	ModuleWindow* moduleWindow = nullptr;

	
	static Application* _instance;

};
#endif //_APPLICATION
