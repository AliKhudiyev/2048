
#include<SDL2/SDL.h>

#pragma once

#define BACKGROUND  "resource/background.bmp"
#define N2          "resource/2.bmp"
#define N4          "resource/4.bmp"
#define N8          "resource/8.bmp"
#define N16         "resource/16.bmp"
#define N32         "resource/32.bmp"
#define N64         "resource/64.bmp"
#define N128        "resource/128.bmp"
#define N256        "resource/256.bmp"
#define N512        "resource/512.bmp"
#define N1024       "resource/1024.bmp"
#define N2048       "resource/2048.bmp"

class Surface{
    public:
    static SDL_Surface* on_load(const char* file_name, const SDL_Surface* surface);
    static SDL_Surface* on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y);
    static SDL_Surface* on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x1, int y1, int w, int h);
};
