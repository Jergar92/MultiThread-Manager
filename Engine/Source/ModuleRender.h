#ifndef _MODULE_RENDER
#define _MODULE_RENDER
#include "Module.h"
 
typedef void *SDL_GLContext;
struct SDL_Window;

class ModuleRender : public Module
{
public:
	ModuleRender(bool enabled = true);
	~ModuleRender();

	bool Awake();
	bool Render();

	void OnResize(int width, int height);
private:


	SDL_Window* GetModuleWindowWindow();

private:
	SDL_Window* window = nullptr;
	SDL_GLContext context;

};
#endif //_MODULE_RENDER

