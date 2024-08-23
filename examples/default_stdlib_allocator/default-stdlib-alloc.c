/*
*/

	#include <stdlib.h>
	#include <stdio.h>
	#include <assert.h>
	#include <stdbool.h>

	#include "strbuf.h"
	#include "strview.h"

//********************************************************************************************************
// Configurable defines
//********************************************************************************************************

	#define INITIAL_BUF_CAPACITY 16

//********************************************************************************************************
// Local defines
//********************************************************************************************************

	#define DBG(_fmtarg, ...) printf("%s:%.4i - "_fmtarg"\n" , __FILE__, __LINE__ ,##__VA_ARGS__)

//********************************************************************************************************
// Private prototypes
//********************************************************************************************************


//********************************************************************************************************
// Public functions
//********************************************************************************************************

int main(int argc, const char* argv[])
{
	strbuf_t* buf;

	DBG("Creating buffer with initial capacity of %i", INITIAL_BUF_CAPACITY);
	buf = strbuf_create(INITIAL_BUF_CAPACITY, NULL);

	strbuf_append(&buf, cstr("This "));
	strbuf_append(&buf, cstr("buffer "));
	strbuf_append(&buf, cstr("lives "));
	strbuf_append(&buf, cstr("on "));
	strbuf_append(&buf, cstr("the "));
	strbuf_append(&buf, cstr("heap. "));

	// This can only be done with dynamic allocation, as it creates a temporary buffer
	strbuf_cat(&buf, cstr("Let's say this twice {"), strbuf_view(&buf), strbuf_view(&buf), cstr("}"));

	DBG("%s", buf->cstr);

	strbuf_destroy(&buf);

	return 0;
}

