#ifndef TRACKINGBALLCAMERA_H
#define TRACKINGBALLCAMERA_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class TrackingBallCamera
{
    public:
        TrackingBallCamera();
        void onMotionEvent(SDL_MouseMotionEvent &event);
        void onButtonEvent(SDL_MouseButtonEvent &event);
        void onKeyboardEvent(SDL_KeyboardEvent &event);
        void setMotionSensivity(double sensivity);
        void setScrollSensivity(double sensivity);
        void look();
        ~TrackingBallCamera();
    protected:
        bool _hold;
        double _distance;
        double _angleY;
        double _angleZ;
        double _motionSensivity;
        double _scrollSensivity;
        SDL_Cursor *_hand1;
        SDL_Cursor *_hand2;
};

#endif
