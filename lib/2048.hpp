
#ifndef G2048
#define G2048 2048

#include"cell.hpp"
#include"vect2d.hpp"

bool is_out(int x, int y);
bool is_empty(const Cell* const cells);
bool is_full(const Cell* const cells);
bool set_index(int x, int y, int index, Cell& cell, Cell* const cells);
Vect2D generate_position(const Cell* const cells);
bool generate_cell(Cell* const cells);
bool slide(const Vect2D& vect, Cell* const cells);
bool check_slide(const Vect2D& vect, Cell* const cells);
bool found_2048(const Cell* const cells);

#endif
