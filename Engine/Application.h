#ifndef _APPLICATION
#define _APPLICATION
#include <list>
#include "Globals.h"
class Module;

class Application
{
public:
	Application();
	~Application();

	bool Awake();
	bool Start();
	UpdateStatus Update();
	bool CleanUp();

private:
	UpdateStatus LateUpdate();

	void AddModule(Module* module);
private:
	std::list<Module*> _modules;
};
#endif //_APPLICATION
