#ifndef _DEFINES
#define _DEFINES

#include <stdio.h>

#ifdef NULL
#undef NULL
#endif
#define NULL  0

#define RELEASE( pointer )	\
 {							\
	if (pointer != NULL)	\
	{						\
		delete pointer;		\
		pointer = NULL;		\
	}						\
}
	

#define RELEASE_ARRAY(pointer)	\
{								\
	if (pointer != NULL)		\
	{							\
		delete[] pointer;		\
		pointer = NULL;			\
	}							\
}

#endif // !_DEFINES
