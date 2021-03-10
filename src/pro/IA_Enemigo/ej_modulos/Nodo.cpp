#include "Nodo.h"

#include <iostream>

Nodo::Nodo(Nodo *p, int coorX, int coorY){
    padre = p;
    f = g = h = 0;
    x = coorX;
    y = coorY;
}

int Nodo::getF(){
    return f;
}

int Nodo::getG(){
    return g;
}

int Nodo::getH(){
    return h;
}

void Nodo::setF(int fn){
    f = fn;
}

void Nodo::setG(int gn){
    g = gn;
}

void Nodo::setH(int hn){
    h = hn;
}