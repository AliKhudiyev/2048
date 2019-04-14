#include<iostream>
#include<cstdlib>
#include"app.hpp"

using namespace std;

int main(int argc, char* argv[]){

    App* app=App::Get_Instance("2048");

    app->on_run();

    delete app;

    return 0;
}