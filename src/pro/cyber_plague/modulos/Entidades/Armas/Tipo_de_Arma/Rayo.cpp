#include "Rayo.h"

/* STATS DEL ARMA */

#define kDmg 10
#define kCad 0.3f
#define kVel 700.0f

/* -------------- */


/* DATOS DE LA BALA */

#define kFich "spritesheet_armas.png"
#define kTexLeft 32
#define kTexTop 0
#define kTexWidth 16
#define kTexHeight 8


Rayo::Bala::Bala(float posX, float posY, int ori){

    sprite_bala = new M_Sprite( kFich , kTexLeft , kTexTop , kTexWidth , kTexHeight , posX, posY);

    orientacion = ori;

    if(ori != 1){

        sprite_bala->rotar(180);
    }

}

void Rayo::Bala::moverse(float posX, float posY){

    sprite_bala->mover(posX, posY);
}

void Rayo::Bala::rotar(float grad){

    sprite_bala->rotar(grad);
}

M_Sprite* Rayo::Bala::getSprite(){

    return sprite_bala;
}

bool Rayo::Bala::heColisionado(NPC* enemigo){

    if(sprite_bala->getSprite()->getGlobalBounds().intersects(enemigo->getSprite()->getSprite()->getGlobalBounds())){

        return true;
    }

    else{

        return false;
    }
}

/* ---------------- */



Rayo::Rayo(float posX, float posY, int orie) : Arma(){

    pX = posX;
    pY = posY;
    ori = orie;

    dmg = kDmg;

    cad = kCad;
    vel = kVel;

    mejora = false;
}

Rayo::~Rayo(){}

bool Rayo::puedeDisparar(){

    float tmp = (float) contDisparo.getElapsedTime().asMilliseconds() / 1000;

    if(tmp >= cad){

        return true;
    }

    else{

        return false;
    }
}


void Rayo::disparo(){

    if(puedeDisparar()){

        Bala* bala = new Bala(pX, pY, ori); 
        proyectiles.push_back(bala);

       contDisparo.restart();
    }
}

void Rayo::mejorar(){

    //ESTA ARMA NO SE MEJORA.
}

void Rayo::update(float dt){

    for(unsigned int i = 0; i < proyectiles.size(); i++){

        proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), 0);
    }
    
}

void Rayo::render(M_Window* vent){
    for(unsigned int i = 0; i < proyectiles.size(); i++){

        vent->render(proyectiles.at(i)->getSprite());
    }

    
}

void Rayo::balaImpactada(NPC* enemigo){
    for(unsigned int i = 0; i < proyectiles.size(); i++){

        if(proyectiles.at(i)->heColisionado(enemigo)){

            enemigo->reciboDmg(this->getDmg());
            proyectiles.erase(proyectiles.begin() + i);
        }

	}
}