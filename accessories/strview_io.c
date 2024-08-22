/*
*/
	#include <limits.h>
	#include <unistd.h>
	#include "strview.h"

//********************************************************************************************************
// Local defines
//********************************************************************************************************

//********************************************************************************************************
// Private prototypes
//********************************************************************************************************

//********************************************************************************************************
// Public functions
//********************************************************************************************************

int strview_write(int fd, strview_t* src)
{
	int retval = 0;

	if(src && strview_is_valid(*src))
	{
		retval = write(fd, src->data, src->size);
		if(retval > 0)
			*src = strview_sub(*src, retval, INT_MAX);
	};

	return retval;
}

//********************************************************************************************************
// Private functions
//********************************************************************************************************
