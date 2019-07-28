#ifndef _APPLICATION
#define _APPLICATION
#include <list>
#include "Globals.h"
class Module;
class ModuleInput;
class ModuleWindow;
class ModuleRender;
class ModuleGame;
class Application
{
public:
	Application();
	~Application();

	bool Awake();
	bool Start();
	UpdateStatus Update();
	bool CleanUp();


	ModuleInput* GetModuleInput();
	ModuleWindow* GetModuleWindow();
	ModuleRender* GetModuleRender();
	ModuleGame* GetModuleGame();
private:
	UpdateStatus ProccesInput();
	UpdateStatus GameLogic();
	UpdateStatus Render();


	void AddModule(Module* module);
private:
	std::list<Module*> _modules;

	ModuleInput* moduleInput = nullptr;
	ModuleWindow* moduleWindow = nullptr;
	ModuleRender* moduleRender = nullptr;
	ModuleGame* moduleGame = nullptr;
	UpdateStatus lastStatus = UpdateStatus::UPDATE_CONTINUE;
	static Application* _instance;

};
#endif //_APPLICATION
