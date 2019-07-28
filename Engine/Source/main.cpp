#include "stdlib.h"
#include "Application.h"
#include "Globals.h"
#include "Defines.h"
#include "SDL.h"

enum EngineStatus
{
	ENGINE_CREATION,
	ENGINE_START,
	ENGINE_UPDATE,
	ENGINE_FINISH,
	ENGINE_EXIT
};

int main(int argc, char *argv[])
{
	int mainReturn = EXIT_FAILURE;
	EngineStatus status = EngineStatus::ENGINE_CREATION;

	Application* App = nullptr;
	
	while (status != EngineStatus::ENGINE_EXIT)
	{

		switch (status)
		{
		case EngineStatus::ENGINE_CREATION:
			LOG("ENGINE_CREATION success");
			App = Application::GetInstance();
			status = EngineStatus::ENGINE_START;

			break;
		case EngineStatus::ENGINE_START:
			if (!App->Awake())
			{
				LOG("ENGINE_START fail on Awake");

				status = EngineStatus::ENGINE_EXIT;
				break;
			}

			if (!App->Start())
			{
				LOG("ENGINE_START fail on Start");

				status = EngineStatus::ENGINE_EXIT;
				break;
			}
			LOG("ENGINE_START success");

			status = EngineStatus::ENGINE_UPDATE;

			break;
		case EngineStatus::ENGINE_UPDATE:
		{
			UpdateStatus updateStatus = App->Update();
			switch (updateStatus)
			{
			case UPDATE_ERROR:
				LOG("ENGINE_UPDATE exit with error");
				status = ENGINE_EXIT;
				break;
			case UPDATE_STOP:
				LOG("ENGINE_UPDATE exit with success");
				status = ENGINE_FINISH;
				break;
			}
		}
			break;
		case EngineStatus::ENGINE_FINISH:
			if (App->CleanUp())
			{
				mainReturn = EXIT_SUCCESS;
			}
			else
			{
				LOG("ENGINE_FINISH exit with error on CleanUp");

				//ERROR
			}
			status = ENGINE_EXIT;

			break;		
		default:
			break;
		}
	}
	RELEASE(App);

	return mainReturn;
}