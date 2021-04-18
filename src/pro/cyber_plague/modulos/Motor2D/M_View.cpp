#include "M_View.h"

M_View::M_View(int x, int y, int width, int height){
    camara = new View(FloatRect(x, y, width, height));
}

M_View::~M_View(){
    delete camara;
}

void M_View::mover(float x, float y){
    camara->move(x, y);
}

void M_View::reset(float x, float y, int width, int height){
    camara->reset(FloatRect(x, y, width, height));
}

View* M_View::getView(){
    return camara;
}