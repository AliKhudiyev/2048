
#include<SDL2/SDL_events.h>

#pragma once

class Event{
    public:
    Event(){}
    virtual ~Event(){}

    protected:
    virtual void on_event(SDL_Event* event);
    virtual void on_right_key_pressed();
    virtual void on_left_key_pressed();
    virtual void on_up_key_pressed();
    virtual void on_down_key_pressed();
    virtual void on_exit();
};
