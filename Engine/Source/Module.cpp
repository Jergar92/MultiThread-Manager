#include "Module.h"

Module::Module(bool startEnabled) : _startEnabled(startEnabled), _isActive(startEnabled)
{

}


Module::~Module()
{
}

bool Module::Awake()
{
	return true;
}

bool Module::Start()
{
	return true;
}

bool Module::Update()
{
	return true;
}

bool Module::LateUpdate()
{
	return true;
}

bool Module::CleanUp()
{
	return true;
}

bool Module::IsActive() const
{
	return _isActive;
}

const char*  Module::GetName() const
{
	return _name.c_str();
}
