#include"g2048.hpp"
#include<cstdlib>
#include<iostream>

bool is_out(int x, int y){
    if(x<0 || x>=MAX_COLUMN ||
       y<0 || y>=MAX_ROW) return true;
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
// |x|*(X(x)-j*x)+|y|*i, |x|*i+|y|*(Y(y)-j*y)
int find_x(const Vect2D& vect, int i, int j){
    return abs(vect.x_)*((5*vect.x_+3)/2-j*vect.x_)+abs(vect.y_)*((3*vect.y_+3)/2-i*vect.y_);
}
// |x|*(X(x)-j*x)+|y|*i, |x|*i+|y|*(Y(y)-j*y)
int find_y(const Vect2D& vect, int i, int j){
    return abs(vect.x_)*((3*vect.x_+3)/2-i*vect.x_)+abs(vect.y_)*((5*vect.y_+3)/2-j*vect.y_);
}

bool set_index(int x, int y, Cell& cell, Cell cells[]){
    if(is_out(x, y) || !cell.number) return false;
    if(cell.number!=cells[MAX_COLUMN*y+x].number &&
       cells[MAX_COLUMN*y+x].number) return false;
    unsigned stat=0;
    if(cells[MAX_COLUMN*y+x].number==cell.number && cells[MAX_COLUMN*y+x].is_addable && cell.is_addable){
        cells[MAX_COLUMN*y+x].number*=2;
        cells[MAX_COLUMN*y+x].is_addable=false;
        cell.number=0;
        cell.is_addable=true;
    } else if(cells[MAX_COLUMN*y+x].number!=cell.number){
        cells[MAX_COLUMN*y+x].number=cell.number;
        cell.number=0;
        cell.is_addable=true;
    } else return false;

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

    return pos;
}

bool generate_cell(const Vect2D& vect, Cell cells[]){
    Vect2D v=generate_position(vect, cells);
    
    if(v.k_==0) return false;

    // std::cout<<"new position: "<<v.x_<<' '<<v.y_<<'\n';
    cells[MAX_COLUMN*v.y_+v.x_].index=MAX_COLUMN*v.y_+v.x_;
    cells[MAX_COLUMN*v.y_+v.x_].number=2;

    return true;
}

bool slide(const Vect2D& vect, Cell cells[]){
    bool slidable=true;
    int x, y, x_dest, y_dest, n_set;
    while(slidable){
        slidable=false;
        // std::cout<<"\tsliding..\n";
        for(int i=0;i<MAX_ROW;++i){
            for(int j=0;j<MAX_COLUMN;++j){
                x_dest=find_x(vect, i, j);
                y_dest=find_y(vect, i, j);
                x=find_x(vect, i, j)-vect.x_;
                y=find_y(vect, i, j)-vect.y_;
                if(set_index(x_dest, y_dest, cells[4*y+x], cells)){
                    slidable=true;
                    // std::cout<<"Dest: "<<x_dest<<' '<<y_dest<<'\n';
                    // std::cout<<"Src: "<<x<<' '<<y<<'\n';
                }
            }
        }
    }
    return true;
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