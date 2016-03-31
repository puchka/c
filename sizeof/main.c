#include <stdio.h>
#include <stdlib.h>

typedef struct Coordonnees;
struct Coordonnees
{
    int x;
    int y;
};

int main()
{
    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("float : %d octets\n", sizeof(float));
    printf("double : %d octets\n", sizeof(double));
    printf("Coordonnees : %d octets\n", sizeof(struct Coordonnees));
    return 0;
}
