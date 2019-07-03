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

	static ModuleWindow* GetInstance(bool enabled = true)
	{
		if (_instance == nullptr)
		{
			_instance = new ModuleWindow(enabled);
		}
		return _instance;
	}
	bool Awake();
private:
	void GetDesktopResolution();
public:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
private:


	static ModuleWindow* _instance;
	int width = 0;
	int height = 0;
	std::string windowTitle;
};

#endif //_MODULE_WINDOW