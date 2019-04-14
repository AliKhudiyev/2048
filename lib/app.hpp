
#include<string>

#pragma once

#include"event.hpp"
#include"cell.hpp"
#include"surface.hpp"
#include"texture.hpp"

#define MAX_COLUMN  4
#define MAX_ROW     4
#define MAX_CELLS   (MAX_COLUMN*MAX_ROW)
#define WIDTH       (MAX_COLUMN*CELL_WIDTH)
#define HEIGHT      (MAX_ROW*CELL_HEIGHT)

class App: public Event{
    friend class Surface;
    friend class Texture;

    private:
    static App* app;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    private:
    App(const std::string& title);
    
    public:
    ~App(){}

    static App* Get_Instance(const std::string& title);
    int on_run();
    int on_init();
    void on_event(SDL_Event* event);
    void on_execute();
    void on_render();
    void on_quit();

    void on_exit();

    private:
    bool running;
    std::string name;
    SDL_Surface *surface, *background;
    Cell cells[MAX_CELLS];    
};
