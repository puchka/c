#include <SDL/SDL.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "freeflycamera.h"
#include "sdlglutils.h"

#define FPS 50

void stop();

FreeFlyCamera *camera;

int main(int argc, char *argv[]){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
    SDL_Event event;
    atexit(stop);

    const Uint32 time_per_frame = 1000/FPS;
    Uint32 last_time,current_time,elapsed_time; //for time animation
    Uint32 start_time,stop_time; //for frame limit

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70, (double)640/480, 1, 1000);

    camera = new FreeFlyCamera(Vector3D(2, 0, 2));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    GLuint texture_sol = loadTexture("floor111.jpg");
    GLuint texture_mur = loadTexture("brick009.jpg");

    while (1){
        start_time = SDL_GetTicks();
        while (SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            exit(0);
                            break;
                        default :
                            camera->OnKeyboard(event.key);
                    }
                    break;
                case SDL_KEYUP:
                    camera->OnKeyboard(event.key);
                    break;
                case SDL_MOUSEMOTION:
                    camera->OnMouseMotion(event.motion);
                    break;
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEBUTTONDOWN:
                    camera->OnMouseButton(event.button);
                    break;
            }
        }
        current_time = SDL_GetTicks();
        elapsed_time = current_time - last_time;
        last_time = current_time;

        camera->animate(elapsed_time);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity( );

        camera->look();

        glBindTexture(GL_TEXTURE_2D, texture_sol);

        glBegin(GL_QUADS);
            glTexCoord2i(0,0);
            glVertex3i(-10,-10,-1);
            glTexCoord2i(10,0);
            glVertex3i(10,-10,-1);
            glTexCoord2i(10,10);
            glVertex3i(10,10,-1);
            glTexCoord2i(0,10);
            glVertex3i(-10,10,-1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture_mur);

        glBegin(GL_QUADS);

            glTexCoord2d(0, 10);
            glVertex3d(10, 10, 10);
            glTexCoord2d(0, 0);
            glVertex3d(10 , 10, -10);
            glTexCoord2d(10, 0);
            glVertex3d(-10, 10, -10);
            glTexCoord2d(10, 10);
            glVertex3d(-10, 10, 10);

            glTexCoord2d(0, 10);
            glVertex3d(10, -10, 10);
            glTexCoord2d(0, 0);
            glVertex3d(10, -10, -10);
            glTexCoord2d(10, 0);
            glVertex3d(10, 10, -10);
            glTexCoord2d(10, 10);
            glVertex3d(10, 10, 10);

            glTexCoord2d(0, 10);
            glVertex3d(-10, -10, 10);
            glTexCoord2d(0, 0);
            glVertex3d(-10, -10, -10);
            glTexCoord2d(10, 0);
            glVertex3d(10, -10, -10);
            glTexCoord2d(10, 10);
            glVertex3d(10, -10, 10);

            glTexCoord2d(0, 10);
            glVertex3d(-10, 10, 10);
            glTexCoord2d(0, 0);
            glVertex3d(-10, 10, -10);
            glTexCoord2d(10, 0);
            glVertex3d(-10, -10, -10);
            glTexCoord2d(10, 10);
            glVertex3d(-10, -10, 10);

        glEnd();

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame)
        {
            SDL_Delay(time_per_frame - (stop_time - last_time));
        }

        glFlush();
        SDL_GL_SwapBuffers();
    }
}

void stop(){
    delete camera;
    SDL_Quit();
}
