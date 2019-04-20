
#include<string>
#include<new>

#pragma once

#include"event.hpp"
#include"cell.hpp"
#include"surface.hpp"
#include"texture.hpp"

#define WIDTH       (MAX_COLUMN*CELL_WIDTH)
#define HEIGHT      (MAX_ROW*CELL_HEIGHT)

class App: public Event{

    private:
    static App* app;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    private:
    App(const std::string& title);
    void on_update();
    void on_post_render(unsigned stat);
    
    public:
    ~App(){}

    static App* Get_Instance(const std::string& title);
    int on_run();
    int on_init();
    void on_event(SDL_Event* event);
    unsigned on_execute();
    void on_render();
    void on_quit();

    void on_right_key_pressed();
    void on_left_key_pressed();
    void on_up_key_pressed();
    void on_down_key_pressed();
    void on_exit();

    private:
    bool running;
    std::string name;
    SDL_Surface *surface, *background;
    Cell cells[MAX_CELLS];    
};
