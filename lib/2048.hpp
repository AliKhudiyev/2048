
#pragma once

#include"cell.hpp"
#include"vect2d.hpp"

bool is_out(int x, int y);
bool is_empty(const Cell cells[]);
bool is_full(const Cell cells[]);
bool set_index(int x, int y, int index, Cell& cell, Cell cells[]);
Vect2D generate_position(const Vect2D& vect, Cell cells[]);
bool generate_cell(const Vect2D& vect, Cell cells[]);
bool slide(const Vect2D& vect, Cell cells[]);
bool found_2048(Cell cells[]);
