#include <stdio.h>
#include <stdlib.h>

int fact(int n);
int argm(int n, int p);
int comb(int n, int p);

int main(void)
{
	char **valeurs={"abcd"};
	return EXIT_SUCCESS;
}

int fact(int n)
{
	if (n==0)
		return 1;
	else
		return n*fact(n-1);
}

int argm(int n, int p)
{
	return fact(n)/fact(n-p);
}

int comb(int n, int p)
{
	return argm(n, p)/fact(p);
}
