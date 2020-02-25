#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv){

	FILE *file;	
	char* input = argv[1];
	char fileText[100][1000];

	file = fopen(input, "r");

	if (file == NULL)
	{
		printf("Could not open file %s", input);
		return 1;
	}
	else
	{	
		for(int i = 0; i < 100; i++)
		{
			fgets(fileText[i], 1000, file);

			if (fileText[i] == NULL)
			{
				fileText[i][1000] = '\0';
				break;
			}

		}

		srand(time(NULL));		
		printf("%s", fileText[rand() % 8]);
	}

	

}

