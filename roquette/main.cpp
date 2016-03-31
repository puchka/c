#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "sdlglutils.h"
#include "TrackBallCamera.h"

TrackBallCamera *camera;

void stop();

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Roquette", NULL);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
    atexit(stop);
    camera = new TrackBallCamera();
    camera->setMotionSensivity(1);
    SDL_Event event;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, double(640/480), 1, 1000);
    GLUquadric *params;
    params = gluNewQuadric();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    Uint32 start_time, end_time;
    GLuint texture_top = loadTexture("rocket_top.jpg");
    GLuint texture_middle = loadTexture("rocket_middle.jpg");
    GLuint texture_bottom = loadTexture("rocket_bottom.jpg");
    GLuint texture_motor = loadTexture("rocket_motor.jpg");
    while(true)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                    camera->onButtonEvent(event.button);
                    break;
                case SDL_MOUSEMOTION:
                    camera->onMotionEvent(event.motion);
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

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        camera->look();
        glTranslated(0, 0, -1.3);
        glBindTexture(GL_TEXTURE_2D, texture_motor);
        start_time = SDL_GetTicks();
        gluDisk(params, 0, 0.3, 20, 1);
        glColor3ub(255, 255, 255);
        glBindTexture(GL_TEXTURE_2D, texture_bottom);
        gluCylinder(params, 0.3, 0.15, 0.25, 20, 1);
        glTranslated(0, 0, 0.25);
        glBindTexture(GL_TEXTURE_2D, texture_middle);
        gluCylinder(params, 0.15, 0.5, 1.05, 20, 1);
        glTranslated(0, 0, 1.05);
        glBindTexture(GL_TEXTURE_2D, texture_top);
        gluCylinder(params, 0.5, 0, 1.6, 20, 1);
        gluDeleteQuadric(params);
        glFlush();
        SDL_GL_SwapBuffers();
        end_time = SDL_GetTicks();
        if (end_time-start_time<20)
        {
            SDL_Delay(20-end_time+start_time);
        }
    }
    stop();
    return 0;
}

void stop()
{
    delete camera;
    SDL_Quit();
}
