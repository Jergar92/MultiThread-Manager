#include "ModuleRender.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "GL/glew.h"
#include "SDL.h"

ModuleRender::ModuleRender(bool startEnabled) : Module(startEnabled)
{
}


ModuleRender::~ModuleRender()
{
}

bool ModuleRender::Awake()
{
	
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearDepth(1.0f);

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);

	return true;
}

bool ModuleRender::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SDL_GL_SwapWindow(window);

	return true;
}

bool ModuleRender::CleanUp()
{
	SDL_GL_DeleteContext(context);
	return true;
}

void ModuleRender::OnResize(int width, int height)
{

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

bool ModuleRender::SetWindow(SDL_Window * window, int width, int height)
{
	if (window == nullptr )
		return false;

	this->window = window;
	this->width = width;
	this->height = height;

	if (!CreateContext())
		return false;

	OnResize(width, height);

	return true;
}

bool ModuleRender::CreateContext()
{
	context = SDL_GL_CreateContext(window);

	if (context == NULL)
	{
		LOG("OpenGL context could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

