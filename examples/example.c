#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 5
#define STRING_LENGTH 100

int main(int argv, char** argc)
{
	char **array = (char**)malloc(1 * sizeof(char*));

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
	   array = (char**)realloc(array, (i + 1) * sizeof(char*));
		array[i] = malloc(STRING_LENGTH);
		snprintf(array[i], STRING_LENGTH, "Test %d", i);
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%s\n", array[i]);
		free(array[i]);
	}

	free(array);
	return 0;
}
