#include<iostream>
#include<cstdlib>
#include<SDL2/SDL.h>

using namespace std;

int main(int argc, char* argv[]){

    SDL_Window* window=SDL_CreateWindow("Hello", 10, 10, 360, 360, SDL_INIT_VIDEO);

    SDL_Event event;
    bool quit=false;
    while (!quit)
    {
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:{
                cout<<"key down: "<<event.key.keysym.sym<<'\n';
                break;
            }
        }
    }
 
    SDL_Quit();

    free(window);

    return 0;
}