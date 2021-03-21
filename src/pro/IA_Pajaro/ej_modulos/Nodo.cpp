#include "Nodo.h"

#include <iostream>

Nodo::Nodo(Nodo *p, int coorX, int coorY){
    padre = p;
    f = g = h = 0;
    x = coorX;
    y = coorY;
}

Nodo::Nodo(const Nodo &n){
    padre = n.padre;
    f = n.f;
    g = n.g;
    h = n.h;
    x = n.x;
    y = n.y;
}

Nodo::~Nodo(){
    padre = NULL; //Con esto el camino solo tiene el nodo meta y el anterior, sin esto peta
}

Nodo & Nodo::operator=(const Nodo &n){
    if(this != &n){
        padre = n.padre;
        f = n.f;
        g = n.g;
        h = n.h;
        x = n.x;
        y = n.y;
    }

    return *this;
}

Nodo* Nodo::getPadre(){
    return padre;
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