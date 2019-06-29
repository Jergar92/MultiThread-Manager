#include "Module.h"

Module::Module(bool startEnabled) : _startEnabled(startEnabled)
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
