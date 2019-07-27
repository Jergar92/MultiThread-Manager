#ifndef _MODULE_GAME
#define _MODULE_GAME

#include "Module.h"
#include "Globals.h"

class ModuleGame :	public Module
{
public:
	ModuleGame(bool enabled = true);
	virtual ~ModuleGame();


	UpdateStatus GameUpdate();

};

#endif // !_MODULE_GAME
