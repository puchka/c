#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 543;
    int p = 5;
    float x = 34.5678;
    printf("A : %d %f\n", n, x);
    printf("B : %4d %10f\n", n, x);
    printf("C : %2d %3f\n", n, x);
    printf("D : %10.3f %10.3e\n", x, x);
    printf("E : %-5d %f\n", n, x);
    printf("F : %*d\n", p, n);
    printf("G : %*.*f\n", 12, 5, x);
    printf("H : %x : %8x :\n", n, n);
    printf("I : %o : %8o :\n", n, n);
    scanf("%4d %2d", &n, &p);
    printf("n = %d\np = %d\n", n, p);
    return 0;
}
