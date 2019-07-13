#include "Application.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"


Application* Application::_instance = nullptr;

Application::Application()
{
	moduleInput = new ModuleInput(true);
	AddModule(moduleInput);

	moduleWindow = new ModuleWindow(true);
	AddModule(moduleWindow);

}


Application::~Application()
{
}

bool Application::Awake()
{
	for (Module* module : _modules)
	{
		if (!module->Awake())
		{
			LOG("Module %s exit with error in Awake", module->GetName());
			return false;

		}

	}
	return true;
}

bool Application::Start()
{
	for (Module* module : _modules)
	{
		if (!module->Start())
		{
			LOG("Module %s exit with error in Start", module->GetName());
			return false;

		}

	}
	return true;
}

UpdateStatus Application::Update()
{

	UpdateStatus inputStatus = moduleInput->InputUpdate();
	if (inputStatus != UpdateStatus::UPDATE_CONTINUE)
		return inputStatus;
	for (Module* module : _modules)
	{
		if (!module->IsActive())
			continue;

		if(!module->Update())
			return UpdateStatus::UPDATE_ERROR;

	}


	for (Module* module : _modules)
	{
		if (!module->IsActive())
			continue;

		if (!module->LateUpdate())
			return UpdateStatus::UPDATE_ERROR;

	}

	return UpdateStatus::UPDATE_CONTINUE;
}

bool Application::CleanUp()
{
	return true;
}



ModuleInput * Application::GetModuleInput()
{
	return moduleInput;
}

ModuleWindow * Application::GetModuleWindow()
{
	return moduleWindow;
}

void Application::AddModule(Module * module)
{
	_modules.push_back(module);
}
