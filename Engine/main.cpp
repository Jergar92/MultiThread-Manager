#include "stdlib.h"
#include "SDL.h"
#include "Application.h"
#include "Globals.h"
#include "Defines.h"
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

			App = new Application();
			status = EngineStatus::ENGINE_START;

			break;
		case EngineStatus::ENGINE_START:
			if (!App->Awake())
			{
				status = EngineStatus::ENGINE_EXIT;
			}

			if (!App->Start())
			{
				status = EngineStatus::ENGINE_EXIT;
			}
			status = EngineStatus::ENGINE_UPDATE;

			break;
		case EngineStatus::ENGINE_UPDATE:
		{
			UpdateStatus updateStatus = App->Update();
			switch (updateStatus)
			{
			case UPDATE_ERROR:
				status = ENGINE_EXIT;
				break;
			case UPDATE_STOP:
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