#ifndef _GLOBALS
#define _GLOBALS

#include <windows.h>
#include <stdio.h>

#define LOG(format, ...) log(format, __VA_ARGS__);


void log(const char* format, ...);

enum UpdateStatus
{
	UPDATE_ERROR,
	UPDATE_CONTINUE,
	UPDATE_STOP
};
#endif // !_GLOBALS
