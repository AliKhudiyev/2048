#include"app.hpp"
#include"surface.hpp"
#include"g2048.hpp"
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
}

void App::on_update(){
    std::string name;
    for(unsigned i=0;i<MAX_CELLS;++i){
        if(cells[i].number){
            name=RESOURCE+std::to_string(cells[i].number)+EXTN;
            cells[i].block=Surface::on_load(name.c_str(), surface);
            if(!cells[i].block){
                std::cout<<"failed to load bmp "<<name<<"\n";
            }
        }
    }
}

App* App::Get_Instance(const std::string& title){
    if(!app) app=new App(title);
    return app;
}

int App::on_run(){
    if(on_init()) return 1;

    std::cout<<"Init passed.\n";

    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)) on_event(&event);
        on_execute();
        on_render();
    }

    std::cout<<"App working passed\n";

    on_quit();

    std::cout<<"Quit passed.\n";

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

void App::on_execute(){
    if(Cell::vect.x_ || Cell::vect.y_){
        std::cout<<"VECT : "<<Cell::vect.x_<<' '<<Cell::vect.y_<<'\n';
        if(found_2048(cells)){
            std::cout<<"You won!\n";
            running=false;
        }
        else if(!slide(Cell::vect, cells)){
            std::cout<<"SLIDE: You lost!\n";
            running=false;
        }
        else if(!generate_cell(Cell::vect, cells)){
            std::cout<<"GEN: You lost!\n";
            running=false;
        }
        Cell::vect=Vect2D(0, 0);
        std::cout<<std::endl;
    }
    on_update();
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
    }
    SDL_UpdateWindowSurface(window);
}

void App::on_quit(){
    if(surface) SDL_FreeSurface(surface);
    if(texture) SDL_DestroyTexture(texture);
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::on_right_key_pressed(){
    std::cout<<"right key pressed\n";
    Cell::vect=Vect2D(1, 0, -1);
}

void App::on_left_key_pressed(){
    std::cout<<"left key pressed\n";
    Cell::vect=Vect2D(-1, 0);
}

void App::on_up_key_pressed(){
    std::cout<<"up key pressed\n";
    Cell::vect=Vect2D(0, -1);
}

void App::on_down_key_pressed(){
    std::cout<<"down key pressed\n";
    Cell::vect=Vect2D(0, 1, -1);
}

void App::on_exit(){
    running=false;
}