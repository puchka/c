#include "trackingballcamera.h"
#include "sdlglutils.h"

TrackingBallCamera::TrackingBallCamera()
{
    const char *hand1[] =
    {
        /* width height num_colors chars_per_pixel */
        " 16 16 3 1 ",
        /* colors */
        "X c #000000",
        ". c #ffffff",
        "  c None",
        /* pixels */
        "       XX       ",
        "   XX X..XXX    ",
        "  X..XX..X..X   ",
        "  X..XX..X..X X ",
        "   X..X..X..XX.X",
        "   X..X..X..X..X",
        " XX X.......X..X",
        "X..XX..........X",
        "X...X.........X ",
        " X............X ",
        "  X...........X ",
        "  X..........X  ",
        "   X.........X  ",
        "    X.......X   ",
        "     X......X   ",
        "     X......X   ",
        "0,0"
    };

    const char *hand2[] =
    {
        /* width height num_colors chars_per_pixel */
        " 16 16 3 1 ",
        /* colors */
        "X c #000000",
        ". c #ffffff",
        "  c None",
        /* pixels */
        "                ",
        "                ",
        "                ",
        "                ",
        "    XX XX XX    ",
        "   X..X..X..XX  ",
        "   X........X.X ",
        "    X.........X ",
        "   XX.........X ",
        "  X...........X ",
        "  X...........X ",
        "  X..........X  ",
        "   X.........X  ",
        "    X.......X   ",
        "     X......X   ",
        "     X......X   ",
        "0,0"
    };
    _hand1 = cursorFromXPM(hand1);
    _hand2 = cursorFromXPM(hand2);
    SDL_SetCursor(_hand1);
    _hold = false;
    _distance = 4;
    _angleY = 0;
    _angleZ = 0;
    _motionSensivity = 1;
    _scrollSensivity = 1;
}

void TrackingBallCamera::onMotionEvent(SDL_MouseMotionEvent &event)
{
    if (_hold)
    {
        _angleY += event.yrel*_motionSensivity;
        _angleZ += event.xrel*_motionSensivity;
    }
}

void TrackingBallCamera::onButtonEvent(SDL_MouseButtonEvent &event)
{
    if (event.button == SDL_BUTTON_LEFT)
    {
        if (!_hold && event.type == SDL_MOUSEBUTTONDOWN)
        {
            _hold = true;
            SDL_SetCursor(_hand2);
        }
        else if (_hold && event.type == SDL_MOUSEBUTTONUP)
        {
            _hold = false;
            SDL_SetCursor(_hand1);
        }
    }
    else if (event.button == SDL_BUTTON_WHEELDOWN && event.type == SDL_MOUSEBUTTONDOWN)
    {
        _distance -= _scrollSensivity;
    }
    else if (event.button == SDL_BUTTON_WHEELUP && event.type == SDL_MOUSEBUTTONDOWN)
    {
        _distance += _scrollSensivity;
    }
}

void TrackingBallCamera::onKeyboardEvent(SDL_KeyboardEvent &event)
{
    switch(event.keysym.sym)
    {
        case SDLK_HOME:
            _angleY = 0;
            _angleZ = 0;
            break;
    }
}

void TrackingBallCamera::look()
{
    gluLookAt(_distance, 0, 0, 0, 0, 0, 0, 0, 1);
    glRotated(_angleY, 0, 1, 0);
    glRotated(_angleZ, 0, 0, 1);
}

TrackingBallCamera::~TrackingBallCamera()
{
    SDL_FreeCursor(_hand1);
    SDL_FreeCursor(_hand2);
    SDL_SetCursor(NULL);
}
