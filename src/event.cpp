#include"event.hpp"

void Event::on_event(SDL_Event* event){
    switch(event->type){
        case SDL_KEYDOWN:{
            switch(event->key.keysym.sym){
                case SDLK_UP:{
                    on_up_key_pressed();
                    break;
                }
                case SDLK_DOWN:{
                    on_down_key_pressed();
                    break;
                }
                case SDLK_RIGHT:{
                    on_right_key_pressed();
                    break;
                }
                case SDLK_LEFT:{
                    on_left_key_pressed();
                    break;
                }
                default: break;
            }
            break;
        }
        case SDL_QUIT:{
            on_exit();
            break;
        }
        default: break;
    }
}

void Event::on_right_key_pressed(){}

void Event::on_left_key_pressed(){}

void Event::on_up_key_pressed(){}

void Event::on_down_key_pressed(){}

void Event::on_exit(){}
