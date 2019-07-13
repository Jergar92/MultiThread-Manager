#include "ModuleRender.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "SDL.h"


ModuleRender::ModuleRender(bool startEnabled) : Module(startEnabled)
{
}


ModuleRender::~ModuleRender()
{
}

bool ModuleRender::Awake()
{
	context = SDL_GL_CreateContext(Application::GetInstance()->GetModuleWindow()->window);
	
	if (context == NULL)
	{
		LOG("OpenGL context could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	
	return true;
}

bool ModuleRender::Update()
{
	return true;
}
