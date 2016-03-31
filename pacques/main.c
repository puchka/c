#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    printf("Année : ");
    scanf("%d", &m);
    int c = m/100;
    int n = (11*(m%19)+14-c+c/4+((8*c+13)/25))%30;
    int q = (30+(m%19)/11-n)/30;
    int p = 51-n-q+(n+q+4*(m%7)+2*(m%4)+6*(c%7)+2*(c%4)+3)%7;
    printf("Date du Pacques pour %d : ", m);
    if (p<=31)
        printf("%d Mars.\n", p);
    else
        printf("%d Avril.\n", p-31);
    return 0;
}
