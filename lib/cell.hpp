
#include<SDL2/SDL.h>

#pragma once

#include"vect2d.hpp"

#define MAX_COLUMN  4
#define MAX_ROW     4
#define MAX_CELLS   (MAX_COLUMN*MAX_ROW)
#define CELL_WIDTH  90
#define CELL_HEIGHT 90

typedef unsigned index_t;
typedef unsigned number_t;

struct Cell{
    index_t index=0;
    number_t number=0;
    bool is_addable=true;
    SDL_Surface* block=nullptr;
    static Vect2D vect;
};
