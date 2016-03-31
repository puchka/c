#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main(int argc, char argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetVideoMode(200,200,32,SDL_HWSURFACE);
    SDL_Quit();
    return EXIT_SUCCESS;
}
