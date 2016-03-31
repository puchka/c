#include<stdio.h>
#include<stdlib.h>

int pgcd(int a, int b);

int main(int argc, char* argv[])
{
	if (argc<3)
	{
		printf("Error: Number of agruments.\n");
		return EXIT_FAILURE;
	}
	int a, b;
	a = strtol(argv[1], NULL, 10);
	b = strtol(argv[2], NULL, 10);
	if (a<0 || b<=0 )
	{
		printf("Error: Invalid arguments.\n");
		return EXIT_FAILURE;
	}
	printf("%d", pgcd(a, b));
	return EXIT_SUCCESS;
}

int pgcd(int a, int b)
{
	int r = 1, temp;
	if (a%b==0)
	{
		if (a>b)
			return b;
		else
			return a;
	}
	while (1)
	{
		temp = r;
		r = a%b;
		if (r==0)
			break;
		a = b;
		b = r;
	}
	return temp;
}
