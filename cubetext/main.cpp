#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include "sdlglutils.h"

void Dessiner();

double angleZ = 0;
double angleX = 0;

int main(int argc, char *argv[])
{
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_WM_SetCaption("SDL GL Application", NULL);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70,(double)640/480,1,1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    Dessiner();

    for (;;)
    {
        SDL_PollEvent(&event);
        {
            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
            }
        }

        Dessiner();

    }

    return 0;
}

void Dessiner()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    gluLookAt(3,4,2,0,0,0,0,0,1);

    GLuint texture1 = loadTexture("stainedglass05.jpg");

    glBindTexture(GL_TEXTURE_2D, texture1);
    glBegin(GL_QUADS);

        glTexCoord2d(0, 1);
        glVertex3d(1,1,1);
        glTexCoord2d(0, 0);
        glVertex3d(1,1,-1);
        glTexCoord2d(1, 0);
        glVertex3d(-1,1,-1);
        glTexCoord2d(1, 1);
        glVertex3d(-1,1,1);

    glEnd();

    glFlush();
    SDL_GL_SwapBuffers();
}
