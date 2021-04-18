#include "Arma.h"

Arma::Arma(){}

Arma::~Arma(){}



int Arma::getDmg(){

    return dmg;
}

int Arma:: getCad(){

    return cad;
}

int Arma::getMunicionMax(){

    return municionMax;
}

int Arma::getMunicionAct(){

    return municionActual;
}


void Arma::setDmg(int d){

    dmg = d;
}

void Arma::setCad(int c){

    cad = c;
}

void Arma::setDatosJugador(float posX, float posY, int orie){

    pX = posX;
    pY = posY;

    ori = orie;

}

void Arma::setMunicionMax(int max){

    municionMax = max;
}

void Arma::setMunicionAct(int act){

    municionActual = act;
}


