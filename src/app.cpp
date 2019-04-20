#include"app.hpp"
#include"surface.hpp"
#include"2048.hpp"
#include<iostream>
#include<cstdlib>

#define I2P_Y(index)       ((index)/MAX_COLUMN)
#define I2P_X(index)       ((index)-MAX_COLUMN*I2P_Y(index))
#define I2Y(index, offset) (CELL_HEIGHT*I2P_Y(index)+offset)
#define I2X(index, offset) (CELL_WIDTH*I2P_X(index)+offset)

App* App::app=nullptr;
Vect2D Cell::vect=Vect2D(0,0);

App::App(const std::string& title){
    running=true;
    name=title;
    window=nullptr;
    surface=nullptr;
    generate_cell(cells);
}

void App::on_update(){
    std::string name;
    for(unsigned i=0;i<MAX_CELLS;++i){
        if(cells[i].number){
            name=RESOURCE+std::to_string(cells[i].number)+EXTN;
            cells[i].block=nullptr;
            cells[i].block=Surface::on_load(name.c_str(), surface);
            if(!cells[i].block) std::cout<<"Failed to load the image "<<name<<".\n";
        }
    }
}

void App::on_post_render(bool win){
    if(win && (background=Surface::on_load(WIN, surface))){
        Surface::on_draw(surface, background);
    } else if((background=Surface::on_load(LOSE, surface))){
        Surface::on_draw(surface, background);
    } else std::cout<<"Failed to load the image!\n";
    SDL_FreeSurface(background);
    SDL_UpdateWindowSurface(window);
}

App* App::Get_Instance(const std::string& title){
    if(!app) app=new App(title);
    return app;
}

int App::on_run(){
    if(on_init()) return 1;

    bool stat;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)) on_event(&event);
        stat=on_execute();
        on_render();
        SDL_Delay(100);
    }   running=true;
    on_post_render(true);
    while(running){
        while(SDL_PollEvent(&event)) on_event(&event);
        SDL_Delay(100);
    }

    on_quit();

    return 0;
}

int App::on_init(){
    int renderer_flags=SDL_RENDERER_ACCELERATED, window_flags=0;
    if(SDL_Init(SDL_INIT_VIDEO)<0) return 1;
    if(!(window=SDL_CreateWindow(name.c_str(), 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN))) return 1;
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear")) return 1;
    if(!(surface=SDL_GetWindowSurface(window))) return 1;
    // if(!(renderer=SDL_CreateRenderer(window, -1, renderer_flags))) return 1;
    if(!(background=Surface::on_load(BACKGROUND, surface))) return 1;
    return 0;
}

void App::on_event(SDL_Event* event){
    Event::on_event(event);
}

bool App::on_execute(){
    bool stat;
    if(Cell::vect.x_ || Cell::vect.y_){
        running=false;
        if(found_2048(cells)) stat=true;
        else if(!check_slide(Cell::vect, cells)) running=true;
        else if(!generate_cell(cells)) stat=false;
        else running=true;
        Cell::vect=Vect2D(0, 0);
    }
    on_update();
    return stat;
}

void App::on_render(){
    // SDL_RenderClear(renderer);
    // SDL_RenderCopy(renderer, texture, NULL, NULL);
    // SDL_RenderPresent(renderer);
    // SDL_BlitSurface(background, NULL, surface, NULL);
    if(!Surface::on_draw(surface, background)){
        std::cout<<"Couldn't draw the image!\n";
    }
    for(unsigned i=0;i<MAX_CELLS;++i){
        if(cells[i].number && cells[i].block){
            if(!Surface::on_draw(surface, cells[i].block, I2X(i, 3), I2Y(i, 3))){
                std::cout<<"Couldn't draw the image!\n";
            }
            SDL_FreeSurface(cells[i].block);
        }
        cells[i].is_addable=true;
    }
    SDL_UpdateWindowSurface(window);
}

void App::on_quit(){
    if(surface) SDL_FreeSurface(surface);
    // if(texture) SDL_DestroyTexture(texture);
    // if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::on_right_key_pressed(){
    Cell::vect=Vect2D(1, 0, -1);
}

void App::on_left_key_pressed(){
    Cell::vect=Vect2D(-1, 0);
}

void App::on_up_key_pressed(){
    Cell::vect=Vect2D(0, -1);
}

void App::on_down_key_pressed(){
    Cell::vect=Vect2D(0, 1, -1);
}

void App::on_exit(){
    running=false;
}