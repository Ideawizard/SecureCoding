#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <errno.h>

#define SUCCESS       0
#define FAILURE       -1
#define BUFFER_SIZE   256

int allocate(char **buffer, size_t size)
{
	errno = 0;
	*buffer = (char*)malloc(size);

	if (*buffer == NULL || errno == ENOMEM)
	{
		printf("malloc returned [%s] errno = %d\n",
			(*buffer == NULL) ? "null" : *buffer, errno);
		return FAILURE;
	}
	return SUCCESS;
}

void deallocate(char **buffer)
{
	/*
	 * Part One: Add code here to correctly release memory
	 * allocated by malloc() in the allocate() 
	 * function.
	 */
	
	free(buffer);

}

int read (char *msg, char **buffer, size_t size)
{
	printf ("%s", msg);

	errno = 0;
	if (fgets(*buffer, size - 1, stdin) != NULL)
	{
		char *pos;
		/* cleanup the \n at the end of name_buffer from fgets() */
		if ((pos = strchr(*buffer, '\n')) != NULL) *pos = '\0';
		return SUCCESS;
	}

	printf("fgets returned [%s] errno = %d\n",
		(*buffer == NULL) ? "null" : *buffer, errno);

	return FAILURE;
}

int main (int argc, char **argv)
{
	/*
	 * Part Two: add a call to deallocate().  There
	 * is one place in main() where this call should
	 * be made.
	 *
	 * Part Three: run the program trough valgrind
	 * to verify the memory leak as been addressed.
	 */

	char *buffer;

	if (allocate(&buffer, BUFFER_SIZE) == FAILURE)
	{
		return -1;
	}

	if (read("Enter some text : ", &buffer, BUFFER_SIZE) == SUCCESS)
	{
		printf ("you entered     : %s\n", buffer);
	}

	deallocate(buffer);

	return 0;
}

