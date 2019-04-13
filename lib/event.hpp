
#include<SDL2/SDL_events.h>

#pragma once

class Event{
    public:
    Event();
    virtual ~Event();

    protected:
    virtual void on_event(SDL_Event* event);
    virtual void on_key_down(Uint8 state, SDL_Keysym keysym);
    virtual void on_key_up(Uint8 state, SDL_Keysym keysym);
    virtual void on_exit();
};
