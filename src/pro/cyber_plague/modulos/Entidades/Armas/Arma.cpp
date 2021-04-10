#include "Arma.h"

Arma::Arma(){}
Arma::~Arma(){}

bool Arma::puedeDisparar(){

    int tmp = contDisparo.getElapsedTime().asSeconds();

    if(tmp >= cad){

        return true;
    }

    else{

        return false;
    }
}

void Arma::render(M_Window* vent){

    for(unsigned int i = 0; i < proyectiles.size(); i++){

        vent->render(proyectiles.at(i));
    }

    
}

vector<M_Sprite*> Arma::getProyectiles(){

    return proyectiles;
}

int Arma::getDmg(){

    return dmg;
}

int Arma:: getCad(){

    return cad;
}


void Arma::setDmg(int d){

    dmg = d;
}

void Arma::setCad(int c){

    cad = c;
}