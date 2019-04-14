
#include<SDL2/SDL.h>

#pragma once

#define RESOURCE    "resource/"
#define EXTN        ".bmp"
#define BACKGROUND  RESOURCE"background" EXTN
#define N2          RESOURCE"2" EXTN
#define N4          RESOURCE"4" EXTN
#define N8          RESOURCE"8" EXTN
#define N16         RESOURCE"16" EXTN
#define N32         RESOURCE"32" EXTN
#define N64         RESOURCE"64" EXTN
#define N128        RESOURCE"128" EXTN
#define N256        RESOURCE"256" EXTN
#define N512        RESOURCE"512" EXTN
#define N1024       RESOURCE"1024" EXTN
#define N2048       RESOURCE"2048" EXTN

class Surface{
    public:
    static SDL_Surface* on_load(const char* file_name, const SDL_Surface* surface);
    static bool on_draw(SDL_Surface* dest, SDL_Surface* src, int x=0, int y=0);
    static bool on_draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x1, int y1, int w, int h);
};
