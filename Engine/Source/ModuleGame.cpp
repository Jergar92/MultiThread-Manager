#include "ModuleGame.h"

ModuleGame::ModuleGame(bool enabled)
{
}

ModuleGame::~ModuleGame()
{
}

UpdateStatus ModuleGame::GameUpdate()
{
	LOG("HI");
	return UpdateStatus::UPDATE_CONTINUE;
}
