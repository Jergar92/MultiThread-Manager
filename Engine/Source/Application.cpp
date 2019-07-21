#include "Application.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleRender.h"


Application* Application::_instance = nullptr;

Application::Application()
{
	moduleInput = new ModuleInput(true);
	AddModule(moduleInput);

	moduleWindow = new ModuleWindow(true);
	AddModule(moduleWindow);


	moduleRender = new ModuleRender(true);
	AddModule(moduleRender);
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
	   	
	if (ProccesInput() != UpdateStatus::UPDATE_CONTINUE)
		return lastStatus;

	if (GameLogic() != UpdateStatus::UPDATE_CONTINUE)
		return lastStatus;

	if (Render() != UpdateStatus::UPDATE_CONTINUE)
		return lastStatus;

	


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

ModuleRender * Application::GetModuleRender()
{
	return moduleRender;
}

UpdateStatus Application::ProccesInput()
{
	lastStatus = moduleInput->InputUpdate();
	return lastStatus;
}

UpdateStatus Application::GameLogic()
{
	return lastStatus;
}

UpdateStatus Application::Render()
{
	return lastStatus;
}

void Application::AddModule(Module * module)
{
	_modules.push_back(module);
}
