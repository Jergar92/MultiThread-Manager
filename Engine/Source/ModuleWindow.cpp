#include "ModuleWindow.h"
#include "Globals.h"
#include "SDL.h"


ModuleWindow::ModuleWindow(bool startEnabled):Module(startEnabled)
{
	_name = "Window";
}


ModuleWindow::~ModuleWindow()
{
}

bool ModuleWindow::Awake()
{
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		LOG("Error: SDL_INIT_VIDEO fail");
		return false;
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);

	Uint32 flags = 0;
	GetDesktopResolution();
	width = 900;
	height = 600;
	flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

	flags |= SDL_WINDOW_RESIZABLE;

	window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

	if (window == NULL)
	{
		LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		screenSurface = SDL_GetWindowSurface(window);
	}
	return true;
}

void ModuleWindow::GetDesktopResolution()
{
	RECT desktop;

	const HWND hDesktop = GetDesktopWindow();

	GetWindowRect(hDesktop, &desktop);

	width = desktop.right;
	height = desktop.bottom;

}
