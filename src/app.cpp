#include"app.hpp"
#include"surface.hpp"
#include<iostream>
#include<cstdlib>

#define UP_ARROW    1073741906
#define DOWN_ARROW  1073741905
#define LET_ARROW   1073741904
#define RIGHT_ARROW 1073741903

App* App::app=nullptr;

App::App(const std::string& title){
    running=true;
    name=title;
    window=nullptr;
    surface=nullptr;
}

App* App::Get_Instance(const std::string& title){
    if(!app) app=new App(title);
    return app;
}

int App::on_run(){
    if(on_init()) return 1;

    std::cout<<"Init passed.\n";

    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)) on_event(&event);
        on_execute();
        on_render();
    }

    std::cout<<"App working passed\n";

    on_quit();

    std::cout<<"Quit passed.\n";

    return 0;
}

int App::on_init(){
    int renderer_flags=SDL_RENDERER_ACCELERATED, window_flags=0;
    if(SDL_Init(SDL_INIT_VIDEO)<0) return 1;
    if(!(window=SDL_CreateWindow(name.c_str(), 100, 100, WIDTH, HEIGHT, window_flags))) return 1;
    // if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear")) return 1;
    if(!(surface=SDL_GetWindowSurface(window))) return 1;
    if(!(renderer=SDL_CreateRenderer(window, -1, renderer_flags))) return 1;
    if(!(background=Surface::on_load(BACKGROUND, surface))) return 1;
    return 0;
    
}

void App::on_event(SDL_Event* event){
    Event::on_event(event);
}

void App::on_execute(){
    ;
}

void App::on_render(){
    // SDL_RenderClear(renderer);
    // SDL_RenderCopy(renderer, texture, NULL, NULL);
    // SDL_RenderPresent(renderer);
    SDL_BlitSurface(background, NULL, surface, NULL);
    std::cout<<"blitted the surface\n";
    if(SDL_UpdateWindowSurface(window)==-1){
        std::cout<<SDL_GetError()<<'\n';
        exit(1);
    }
}

void App::on_quit(){
    // if(surface) SDL_FreeSurface(surface);
    if(texture) SDL_DestroyTexture(texture);
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::on_exit(){
    running=false;
}