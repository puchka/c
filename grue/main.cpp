#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define LARGEUR_FENETRE 500
#define HAUTEUR_FENETRE 500

/*
    Dessine le repère actuel pour faciliter
    la compréhension des transformations.
    Utiliser « echelle » pour avoir un repère bien orienté et positionné
    mais avec une échelle différente.
*/
void dessinerRepere(unsigned int echelle = 1)
{
    glPushMatrix();
    glScalef(echelle, echelle, echelle);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 255);
    glVertex2i(0, 0);
    glVertex2i(1, 0);
    glColor3ub(0, 255, 0);
    glVertex2i(0, 0);
    glVertex2i(0, 1);
    glEnd();
    glPopMatrix();
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Exercice Grue", NULL);
    SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_OPENGL);

    int teta = 0, teta2 = 90, l=200;

    SDL_EnableKeyRepeat(10, 10);

    bool continuer = true;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_DOWN:
                        if (l<200)
                            l++;
                        break;
                    case SDLK_UP:
                        if (l>10)
                            l--;
                        break;
                    case SDLK_LEFT:
                        if (event.key.keysym.mod && KMOD_SHIFT)
                        {
                            if (teta>0)
                                teta--;
                        }
                        else
                        {
                            if (teta2>20)
                                teta2--;
                        }
                        break;
                    case SDLK_RIGHT:
                        if (event.key.keysym.mod && KMOD_SHIFT)
                        {
                            if (teta<30)
                                teta++;
                        }
                        else
                        {
                            if (teta2<90)
                                teta2++;
                        }
                        break;
                    case SDLK_e:
                        continuer = false;
                        break;
                }
                break;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity( );
        gluOrtho2D(0, LARGEUR_FENETRE, 0, HAUTEUR_FENETRE);

        glBegin(GL_QUADS);
            glColor3ub(254, 127, 1);
            glVertex2i(50, 50);
            glVertex2i(50, 100);
            glVertex2i(150, 100);
            glVertex2i(150, 50);
        glEnd();

        dessinerRepere(50);

        // Dessin grand bras

        glTranslated(100, 100, 0);
        glRotated(-teta, 0, 0, 1);

        glBegin(GL_QUADS);
            glColor3ub(248, 230, 7);
            glVertex2i(-20, 0);
            glVertex2i(-20, 250);
            glVertex2i(20, 250);
            glVertex2i(20, 0);
        glEnd();

        dessinerRepere(50);

        // Dessin petit bras

        glTranslated(0, 250, 0);
        glRotated(-teta2, 0, 0, 1);

        glBegin(GL_QUADS);
            glColor3ub(185, 234, 20);
            glVertex2i(-10, 0);
            glVertex2i(-10, 100);
            glVertex2i(10, 100);
            glVertex2i(10, 0);
        glEnd();

        dessinerRepere(50);

        // Dessin fil

        glTranslated(0, 95, 0);
        glRotated(teta+teta2-180, 0, 0, 1);

        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2i(0, 0);
            glVertex2i(0, l);
        glEnd();

        dessinerRepere(50);

        glTranslated(0, l, 0);

        // Dessin charge

        glBegin(GL_QUADS);
            glColor3ub(174, 174, 84);
            glVertex2d(-10, 0);
            glVertex2d(-10, 20);
            glVertex2d(10, 20);
            glVertex2d(10, 0);
        glEnd();

        dessinerRepere(50);

        glFlush();
        SDL_GL_SwapBuffers();
    }

    SDL_Quit();

    return 0;
}
