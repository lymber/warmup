#include <stdio.h>
#include <stdlib.h>
#include "auxiliary.h"

/*
  The mallocX() function allocates size bytes and returns a pointer to the
  allocated memory.  The memory is not cleared.  If size is 0, then it
  returns whatever the standard library malloc() returns, unless it is NULL.

  In the circumstances where the return value would be NULL, it terminates
  the execution of the program.
*/

void *mallocX(size_t size)
{
	void *res;
	res = malloc(size);
	if (res == NULL) {
		perror("Could not allocate memory");
		exit(EXIT_FAILURE);
	}
	return res;
}
