#include "ModuleWindow.h"


ModuleWindow* ModuleWindow::_instance = nullptr;

ModuleWindow::ModuleWindow(bool startEnabled):Module(startEnabled)
{
	_name = "Window";
}


ModuleWindow::~ModuleWindow()
{
}
