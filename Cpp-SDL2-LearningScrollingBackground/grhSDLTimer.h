#ifndef GRHSDLTIMER_H_INCLUDED
#define GRHSDLTIMER_H_INCLUDED

#include <SDL.h>

class grhTimer
{
private:
    unsigned int pastTicks;
public:
    grhTimer()
    {
        pastTicks=SDL_GetTicks();
    }
    void setTimer()
    {
        pastTicks=SDL_GetTicks();
    }
    unsigned int getTimeElapsed()
    {
        return SDL_GetTicks()-pastTicks;
    }
};

#endif // GRHSDLTIMER_H_INCLUDED
