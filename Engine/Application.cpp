#include "Application.h"
#include "Module.h"
#include "ModuleWindow.h"

Application::Application()
{
	AddModule(ModuleWindow::GetInstance());
}


Application::~Application()
{
}

bool Application::Awake()
{
	return false;
}

bool Application::Start()
{
	return false;
}

UpdateStatus Application::Update()
{
	return UpdateStatus();
}

bool Application::CleanUp()
{
	return false;
}

UpdateStatus Application::LateUpdate()
{
	return UpdateStatus();
}

void Application::AddModule(Module * module)
{
	_modules.push_back(module);
}
