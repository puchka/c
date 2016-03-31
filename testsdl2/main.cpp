#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran = NULL;
    SDL_Surface *rectangle = NULL;
    SDL_Rect position;
    ecran=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);
    rectangle=SDL_CreateRGBSurface(SDL_HWSURFACE,220,180,32,0,0,0,0);
    SDL_WM_SetCaption("Super ma fenetre SDL!",NULL);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,17,206,112));
    SDL_FillRect(rectangle,NULL,SDL_MapRGB(ecran->format,255,255,255));
    position.x=0;
    position.y=0;
    SDL_BlitSurface(rectangle,NULL,ecran,&position);
    SDL_Flip(ecran);
    pause();
    SDL_FreeSurface(rectangle);
    SDL_Quit();
    return EXIT_SUCCESS;
}

void pause()
{
    int continuer=1;
    SDL_Event event;
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer=0;
        }
    }
}
