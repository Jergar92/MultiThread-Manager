#ifndef _MODULE_WINDOW
#define _MODULE_WINDOW
#include "Module.h"

struct SDL_Window;
struct SDL_Surface;
class ModuleWindow :public Module
{
public:
	ModuleWindow(bool startEnabled = true);
	virtual ~ModuleWindow();

	bool Awake();
	int GetWidth() const;
	int GetHeight() const;
private:
	void GetDesktopResolution();
public:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
private:


	int width = 0;
	int height = 0;
	std::string windowTitle;
};

#endif //_MODULE_WINDOW