
#pragma once

#include"event.hpp"
#include"cell.hpp"

#define MAX_COLUMN  4
#define MAX_ROW     4
#define MAX_CELLS   (MAX_COLUMN*MAX_ROW)

class Window: public Event{
    private:
    static Window* window;
    // static SDL_Window* window;

    public:
    Window();
    ~Window();

    static int on_run();
    int on_init();
    void on_event(SDL_Event* event);
    void on_execute();
    void on_render();
    void on_quit();

    void on_key_down(Uint8 state, SDL_Keysym keysym);
    void on_key_up(Uint8 state, SDL_Keysym keysym);

    private:
    bool running;
    SDL_Surface* surface;
    Cell cells[MAX_CELLS];    
};
