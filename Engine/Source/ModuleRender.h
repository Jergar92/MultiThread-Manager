#ifndef _MODULE_RENDER
#define _MODULE_RENDER
#include "Module.h"

typedef void *SDL_GLContext;

class ModuleRender : public Module
{
public:
	ModuleRender(bool enabled = true);
	~ModuleRender();

	bool Awake();
	bool Update();

private:

	SDL_GLContext context;

};
#endif //_MODULE_RENDER

