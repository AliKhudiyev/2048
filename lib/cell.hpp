
#include<SDL2/SDL.h>

#pragma once

typedef unsigned index_t;
typedef unsigned number_t;

struct Cell{
    index_t index=0;
    number_t number=0;
    SDL_Surface* block=nullptr;
};
