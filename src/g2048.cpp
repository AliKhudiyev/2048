#include"g2048.hpp"
#include<cstdlib>
#include<iostream>

bool is_out(int x, int y){
    if(x<0 || x>MAX_COLUMN ||
       y<0 || y>MAX_ROW) return true;
    return false;
}

bool is_empty(const Cell cells[]){
    for(unsigned i=0;i<MAX_CELLS;++i){
        if(cells[i].number) return false;
    }
    return true;
}

bool is_full(const Cell cells[]){
    for(unsigned i=0;i<MAX_CELLS;++i){
        if(!cells[i].number) return false;
    }
    return true;
}

bool set_index(int x, int y, Cell& cell, Cell cells[]){
    if(is_out(x, y) || !cell.number) return false;
    if(cell.number!=cells[MAX_COLUMN*y+x].number &&
       cells[MAX_COLUMN*y+x].number) return false;
    
    cells[MAX_COLUMN*y+x].index=MAX_COLUMN*y+x;
    cells[MAX_COLUMN*y+x].number*=2;
    return true;
}

Vect2D generate_position(const Vect2D& vect, Cell cells[]){
    Vect2D pos(0, 0);

    if(is_full(cells)){
        pos.k_=0;
        std::cout<<"couldnt generate a position, bc cells are full\n";
        return pos;
    }

    int i=rand()%MAX_CELLS;
    unsigned index=0;
    for(unsigned j=0;i>-1;++j){
        if(j>=MAX_CELLS) j=0;
        if(cells[j].number==0){ index=j; --i; }
    }
    pos.y_=index/MAX_COLUMN;
    pos.x_=index-MAX_COLUMN*pos.y_;

    std::cout<<"generting a brand new position\n";

    return pos;
}

bool generate_cell(const Vect2D& vect, Cell cells[]){
    Vect2D v=generate_position(vect, cells);
    
    if(v.k_==0) return false;

    std::cout<<"new position: "<<v.x_<<' '<<v.y_<<'\n';
    cells[MAX_COLUMN*v.y_+v.x_].index=MAX_COLUMN*v.y_+v.x_;
    cells[MAX_COLUMN*v.y_+v.x_].number=2;

    return true;
}

bool slide(const Vect2D& vect, Cell cells[]){
    bool result=false, slidable=true;
    while(slidable){
        slidable=false;
        std::cout<<"\tsliding..\n";
        for(int i=0;i<MAX_ROW;++i){
            for(int j=0;j<MAX_COLUMN;++j){
                std::cout<<"cell ("<<j<<", "<<i<<")\n";
                if(set_index(j+vect.x_, i+vect.y_, cells[MAX_COLUMN*i+j], cells)){
                    result=slidable=true;
                    std::cout<<"slide result is true!\n";
                }
            }
        }
    }
    return result;
}

bool delete_number(unsigned x, unsigned y, Cell cells[]){
    if(is_out(x, y) || !cells[MAX_COLUMN*y+x].number) return false;
    cells[MAX_COLUMN*y+x].number=0;
    delete cells[MAX_COLUMN*y+x].block;
    cells[MAX_COLUMN*y+x].block=nullptr;
    return true;
}

bool found_2048(Cell cells[]){
    for(unsigned i=0;i<MAX_CELLS;++i){
        if(cells[i].number==2048) return true;
    }
    return false;
}