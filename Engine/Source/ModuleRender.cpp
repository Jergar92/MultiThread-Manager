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
	context = SDL_GL_CreateContext(GetModuleWindowWindow());
	
	if (context == NULL)
	{
		LOG("OpenGL context could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}	
	
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

	OnResize(Application::GetInstance()->GetModuleWindow()->GetWidth(), Application::GetInstance()->GetModuleWindow()->GetHeight());
	return true;
}

bool ModuleRender::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SDL_GL_SwapWindow(GetModuleWindowWindow());

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

SDL_Window * ModuleRender::GetModuleWindowWindow()
{
	if (window == nullptr)
		window = Application::GetInstance()->GetModuleWindow()->window;
	return window;
}
