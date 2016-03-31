#include <stdio.h>
#include <stdlib.h>

typedef struct Coordonnees Coordonnees;

struct Coordonnees
{
    int x;
    int y;
};

void initialiserCoordonnees(Coordonnees *point);

int main()
{
    Coordonnees point;
    initialiserCoordonnees(&point);
    printf("point.x = %d\npoint.y = %d", point.x, point.y);
    return 0;
}

void initialiserCoordonnees(Coordonnees *point)
{
    point->x = 0;
    point->y = 0;
}
