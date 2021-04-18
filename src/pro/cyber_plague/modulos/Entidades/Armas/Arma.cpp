#include "Arma.h"

Arma::Arma(){}

Arma::~Arma(){}

Arma::Bala::~Bala(){
    delete sprite_bala;
}

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

        vent->render(proyectiles.at(i)->getSprite());
    }

    
}

void Arma::checkEnemyColision(vector<NPC*> enemigos){
    for(unsigned int i = 0; i < proyectiles.size(); i++){
        for(unsigned int j = 0; j < enemigos.size(); j++){
            if(proyectiles.at(i)->getSprite()->getSprite()->getGlobalBounds().intersects(enemigos.at(j)->getSprite()->getSprite()->getGlobalBounds())){
                enemigos.at(j)->setVida(enemigos.at(j)->getVida() - dmg);
                delete proyectiles.at(i);
                proyectiles.erase(proyectiles.begin()+i);
            }
        }
	}
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