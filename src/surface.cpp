#include"surface.hpp"

SDL_Surface* Surface::on_load(const char* file_name){
    SDL_Surface* tmp=nullptr;
    SDL_Surface* surface=nullptr;

    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if(!(tmp=SDL_LoadBMP(file_name))) return NULL;

    // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp);
    // surface=SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);

    return surface;
}

SDL_Surface* Surface::on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y){
    SDL_BlitSurface(src, NULL, dest, NULL);
}

SDL_Surface* Surface::on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x1, int y1, int w, int h){
    ;
}