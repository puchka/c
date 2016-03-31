#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(int argc , char *argv[] )
{
    int a=0;
    int b,c;
    srand(time(NULL));
    b=(rand() %99+1);

do {
    printf("entrer un nombre:");
    scanf("%d\n",&c);
    if (c>b) printf("plus petit");

    else if (c<b) printf("plus grand");

    else printf("vous avez gagner");
    a++;
    }while(c!=b);
printf("vous avez trouver le nombre en %d coup", a);
   return 0;
}
