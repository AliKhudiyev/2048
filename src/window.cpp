#include"window.hpp"
#include"surface.hpp"
#include<iostream>

#define UP_ARROW    1073741906
#define DOWN_ARROW  1073741905
#define LET_ARROW   1073741904
#define RIGHT_ARROW 1073741903

Window* Window::window=nullptr;

Window::Window(){
    running=true;
    surface=nullptr;
}

int Window::on_run(){
    if(window->on_init()) return 1;

    SDL_Event event;
    while(window->running){
        while(SDL_PollEvent(&event)) window->on_event(&event);
        window->on_execute();
        window->on_render();
    }

    window->on_quit();

    return 0;
}

int Window::on_init(){
    if(SDL_Init(SDL_INIT_VIDEO)) return 1;
    if(!(surface=Surface::on_load(BACKGROUND))) return 1;
    return 0;
}

void Window::on_event(SDL_Event* event){
    on_event(event);
}

void Window::on_execute(){

}

void Window::on_render(){
    ;
}

void Window::on_quit(){
    ;
}

void Window::on_key_down(Uint8 state, SDL_Keysym keysym){
    std::cout<<"Key down: "<<state<<", "<<keysym.sym<<'\n';
}

void Window::on_key_up(Uint8 state, SDL_Keysym keysym){
    ;
}