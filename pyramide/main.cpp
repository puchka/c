#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <math.h>

int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_SetVideoMode(640, 480, 16, SDL_OPENGL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, double(640/480), 0.1, 1000);
    glEnable(GL_DEPTH_TEST);

    double teta = 0, x, y, z = 0;

    Uint32 previous_time, current_time, ellapsed_time;

    SDL_EnableKeyRepeat(10, 10);

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
                case SDL_QUIT:
                    done = true;
                    break;

                // check for keypresses
                case SDL_KEYDOWN:
                {
                    switch(event.key.keysym.sym)
                    {
                        // exit if ESCAPE is pressed
                        case SDLK_ESCAPE:
                            done = true;
                            break;
                        case SDLK_UP:
                            z+= 0.1;
                            break;
                        case SDLK_DOWN:
                            z-= 0.1;
                            break;
                    }
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        current_time = SDL_GetTicks();

        teta+=0.1;

        x = cos(teta);
        y = sin(teta);

        gluLookAt(x, y, z, 0, 0, 0, 0, 0, 1);

        glBegin(GL_TRIANGLES);
            glColor3ub(255, 0, 0); // face rouge
            glVertex3d(0, 0, 1);
            glVertex3d(-0.5, -0.5, 0);
            glVertex3d(0.5, -0.5, 0);
            glColor3ub(0, 255, 0); // face verte
            glVertex3d(-0.5, -0.5, 0);
            glVertex3d(-0.5, 0.5, 0);
            glVertex3d(0, 0, 1);
            glColor3ub(0, 0, 255); // face bleue
            glVertex3d(-0.5, 0.5, 0);
            glVertex3d(0.5, 0.5, 0);
            glVertex3d(0, 0, 1);
            glColor3ub(255, 255, 0); // face jaune
            glVertex3d(0.5, 0.5, 0);
            glVertex3d(0.5, -0.5, 0);
            glVertex3d(0, 0, 1);
        glEnd();

        glBegin(GL_QUADS);
            glColor3ub(128, 128, 0);
            glVertex3d(0.5, 0.5, 0);
            glVertex3d(-0.5, 0.5, 0);
            glVertex3d(-0.5, -0.5, 0);
            glVertex3d(0.5, -0.5, 0);
        glEnd();

        previous_time = current_time;
        ellapsed_time = current_time - previous_time;
        SDL_Delay(30-ellapsed_time);

        // DRAWING ENDS HERE
        glFlush();
        // finally, update the screen :)
        SDL_GL_SwapBuffers();
    } // end main loop

    return 0;
}
