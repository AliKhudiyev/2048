#include"surface.hpp"
#include<iostream>

SDL_Surface* Surface::on_load(const char* file_name, const SDL_Surface* surface){
    SDL_Surface* tmp_surface=nullptr;
    SDL_Surface* optimezed_surface=nullptr;

    std::cout<<"on load begins\n";
    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if(!(tmp_surface=SDL_LoadBMP(file_name))){
        // std::cout<<SDL_GetError();
        return NULL;
    }

    // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp);
    // surface=SDL_DisplayFormat(tmp);
    optimezed_surface=SDL_ConvertSurface(tmp_surface, surface->format, 0);
    // SDL_FreeSurface(tmp_surface);

    if(!surface){
        std::cout<<"the given surface is even NULL!\n";
    }
    std::cout<<"optimized surface is ready\n";
    if(!optimezed_surface){
        std::cout<<"it's null :(\n";
        // std::cout<<SDL_GetError();
    }

    return tmp_surface;
}

SDL_Surface* Surface::on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y){
    SDL_BlitSurface(src, NULL, dest, NULL);
}

SDL_Surface* Surface::on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x1, int y1, int w, int h){
    ;
}