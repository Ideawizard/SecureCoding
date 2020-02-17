#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*
	This program represents the wrong way to
	test for integer overflow (wrap).
	The program is incorrectly checking if (sum + i)
 	is greater than UINT_MAX, because if sum equals
	UINT_MAX, sum + i will overflow.

	Assignment : Modify this program to correctly
	check and alert on an overflow condition.

*/

int main (int argc, char **argv)
{
	unsigned int i = 1;
	unsigned int sum;
	
	if (argc < 2)
	{
		printf("wrap expects one argument.\n");
		return -1;
	}

	sum = atoi(argv[1]);

	printf ("sum           : %u\n", sum);

	printf ("overflow test : (sum + %u > UINT_MAX) : ", i);

	if (sum + i > UINT_MAX)
	{
		printf ("overflow : sum + %u : %u\n", i, sum + i);
	}
	else 
	{
		printf ("NO overflow : sum + %u : %u\n", i, sum + i);
	}
}
