//Modded and Secured by TIMOTHY RYAN SCULLY

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void usage(char *arg)
{
	/* Assignment 1
    *
	 * This program is vulnerable to an overflow exploit. The use
    * of strcpy() on a source whose size is unknown can overflow
    * the destination (buf) and corrupt the stack.
    * 
    * There are several ways to protect against this, so I am not
    * looking for a specific answer.
    *
    * 1. Ensure arg will not overflow buf before copying into buf.
    * 2. Be sure buf is properly null terminated.
    *
	 */
	char buf[strlen(arg) + 1]; //Extended the length of the buf array to the length of arg.
	char* terminator = "\0"; //the null terminator. It'll be back.

	strncat(buf, terminator, 1); //append the null terminator to the buff. Told you it'll be back.
	
	strcpy(buf, arg);
	if (strcmp(buf, "--help") == 0 ||
		 strcmp(buf, "-h") == 0)
	{
		printf("\nUsage: overflow [--help]\n\n");
		printf(" --help (-h) : Displays this Message.\n\n");
	}
	else
	{
		printf("\nUnknown Option: \"%s\"\n\n", buf);
	}
}

int main (int argc, char **argv)
{

	if (argc == 2)
	{
		usage(argv[1]);
	}
	else
	{
		printf("\nThis program expects an argument.\n\n");
	}

	return 0;

}
