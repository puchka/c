#include "SDL/SDL.h"
#include "GL/gl.h"
#include "GL/glu.h"

class TrackBallCamera
{
    public:
        TrackBallCamera();
        void onMotionEvent(SDL_MouseMotionEvent &event);
        void onButtonEvent(SDL_MouseButtonEvent &event);
        void onKeyboardEvent(SDL_KeyboardEvent &event);
        void look();
        void setMotionSensivity(double sensivity);
        void setScrollSensivity(double sensivity);
        ~TrackBallCamera();
    protected:
        double _distance;
        double _angleY;
        double _angleZ;
        double _motionSensivity;
        double _scrollSensivity;
        bool _hold;
        SDL_Cursor *_hand1;
        SDL_Cursor *_hand2;
};
