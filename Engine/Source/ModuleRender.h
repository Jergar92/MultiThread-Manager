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
	bool CleanUp();
	void OnResize(int width, int height);

	bool SetWindow(SDL_Window* window, int width, int height);
private:

	bool CreateContext();


private:
	SDL_Window* window = nullptr;
	int width = 0;
	int height = 0;
	SDL_GLContext context;

};
#endif //_MODULE_RENDER

