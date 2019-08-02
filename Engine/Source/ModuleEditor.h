#ifndef _MODULE_EDITOR
#define _MODULE_EDITOR
#include "Module.h"
class OrbitalCamera;
class InputController;
class ModuleEditor:public Module
{
public:
	ModuleEditor(bool enabled = true);
	~ModuleEditor();
	bool CleanUp();

	void SetInput(InputController* input);
private:
	OrbitalCamera* camera = nullptr;
	InputController* input = nullptr;
};


#endif // !_MODULE_EDITOR
