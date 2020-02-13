#include <stdio.h>
#include <string.h>

char* ReadLine(FILE *file, char output[]);

int main(int argc, char** argv){

	FILE *file;	
	char* input = argv[1];
	char output[1000];
	char* fileText[100];
	
	file = fopen(input, "r");

	if (file == NULL)
	{
		printf("Could not open file %s", input);
		return 1;
	}

	else
	{	for(int i = 0; ReadLine(file, output) != NULL ;i++)
		{
			fileText[i] = ReadLine(file, output);
		}
	}

	return 0;


}

char* ReadLine(FILE *file, char output[])
{

	if (fgets(output, 1000, file) != NULL)
	{	output[999] = '\0';
		printf("%s", output);
	
	}
	else
	{
		output = NULL;
		fclose(file);
	}

	return output;
}
