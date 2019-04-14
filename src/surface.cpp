#include"surface.hpp"
#include<iostream>

SDL_Surface* Surface::on_load(const char* file_name, const SDL_Surface* surface){
    SDL_Surface* tmp_surface=nullptr;
    SDL_Surface* optimezed_surface=nullptr;

    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if(!(tmp_surface=SDL_LoadBMP(file_name))) return NULL;

    // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp);
    optimezed_surface=SDL_ConvertSurface(tmp_surface, surface->format, 0);
    SDL_FreeSurface(tmp_surface);

    return optimezed_surface;
}

bool Surface::on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y){
    if(!dest || !src) return false;
    
    SDL_Rect d_rect;
    d_rect.x=x;
    d_rect.y=y;

    SDL_BlitSurface(src, NULL, dest, &d_rect);

    return true;
}

bool Surface::on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x1, int y1, int w, int h){
    if(!dest || !src) return false;
    
    SDL_Rect s_rect;
    s_rect.x=x1;
    s_rect.y=y1;
    s_rect.w=w;
    s_rect.h=h;

    SDL_Rect d_rect;
    d_rect.x=x;
    d_rect.y=y;

    SDL_BlitSurface(src, &s_rect, dest, &d_rect);

    return true;
}