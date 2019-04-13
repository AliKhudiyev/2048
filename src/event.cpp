#include"event.hpp"

void Event::on_event(SDL_Event* event){
    switch(event->type){
        case SDL_KEYDOWN:{
            on_key_down(event->key.state, event->key.keysym);
            break;
        }
        case SDL_KEYUP:{
            on_key_up(event->key.state, event->key.keysym);
            break;
        }
        default: break;
    }
}

void Event::on_key_down(Uint8 state, SDL_Keysym keysym){
    ;
}

void Event::on_key_up(Uint8 state, SDL_Keysym keysym){
    ;
}

void Event::on_exit(){

}
