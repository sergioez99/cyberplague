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

string Arma::getTipo(){

    return tipo;
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

    if(max < 300){

        municionMax = max;
        municionActual = max;  //Cuando el jugador coja una mejora de municion, tambien recupera la municion perdida.
    }
}

void Arma::recargaArma(){

    municionActual = municionMax;
}

void Arma::setMunicionAct(int act){

    municionActual = act;
}


