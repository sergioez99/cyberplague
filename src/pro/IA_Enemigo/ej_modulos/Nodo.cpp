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

int Nodo::getX(){
    return x;
}

int Nodo::getY(){
    return y;
}

void Nodo::setPadre(Nodo *p){
    padre = p;
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

bool Nodo::operator==(const Nodo &n){
    if(x == n.x && y == n.y)
        return true;
    else
        return false;
}

bool Nodo::operator!=(const Nodo &n){
    if(x != n.x || y != n.y)
        return true;
    else
        return false;
}