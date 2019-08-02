#include "ModuleEditor.h"
#include "OrbitalCamera.h"
#include "Defines.h"
#include "InputController.h"
ModuleEditor::ModuleEditor(bool enabled)
{
	camera = new OrbitalCamera();
}

ModuleEditor::~ModuleEditor()
{
}

bool ModuleEditor::CleanUp()
{
	if(camera == nullptr)
		return false;

	RELEASE(camera);
	return true;
}

void ModuleEditor::SetInput(InputController* input)
{
	this->input = input;
}
