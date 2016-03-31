#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "sdlglutils.h"
#include "trackingballcamera.h"

void stop();

TrackingBallCamera *camera;

int main ( int argc, char** argv )
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Globe", NULL);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
    atexit(stop);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, (double)640/480, 0.1, 1000);
    camera = new TrackingBallCamera();
    GLUquadric *params;
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    GLuint texture = loadTexture("world_map.jpg");
    Uint32 start_time, end_time;
    SDL_Event event;
    while (true)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_MOUSEMOTION:
                    camera->onMotionEvent(event.motion);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                    camera->onButtonEvent(event.button);
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            exit(0);
                            break;
                        default:
                            camera->onKeyboardEvent(event.key);
                            break;
                    }
            }
        }
        start_time = SDL_GetTicks();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        camera->look();
        params = gluNewQuadric();
        gluQuadricTexture(params, GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glColor3ub(255, 255, 255);
        gluSphere(params, 1, 20, 20);
        gluDeleteQuadric(params);
        glFlush();
        SDL_GL_SwapBuffers();
        end_time = SDL_GetTicks();
        if (end_time-start_time<20)
        {
            SDL_Delay(20+start_time-end_time);
        }
    }
    return 0;
}

void stop()
{
    delete camera;
    SDL_Quit();
}
