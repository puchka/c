#include <stdio.h>
#include <stdlib.h>

int estPair(int a);
char* syracuse(int a);

int main()
{
    int a;
    printf("a = ");
    scanf("%d", &a);
    printf("%s", syracuse(a));
    return EXIT_SUCCESS;
}

int estPair(int a)
{
    return (a%2==0);
}

char* syracuse(int a)
{
    while (a!=1)
    {
        if (estPair(a))
            a = a/2;
        else
            a = (a+1)/2;
    }
    return "fini\n";
}
