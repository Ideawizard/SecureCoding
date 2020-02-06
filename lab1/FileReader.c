#include <stdio.h>

int main(int argc, char** argv){

	FILE *file;
	char output[1000];

	
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Could not open file %s", argv[1]);
		return 1;
	}

	if (fgets(output, 1000, file) != NULL)
	{	output[999] = "\0";
		printf("%s", output);
	}
	fclose(file);
	return 0;


}


