#include "Laser.h"

/* STATS DEL ARMA */

#define kDmg 5
#define kCad 0.2f
#define kVel 900.0f
#define kMuncGas 5  //MUNICION QUE GASTA EL ARMA POR DISPARO

/* -------------- */


/* DATOS DE LA BALA */

#define kFich "spritesheet_armas.png"
#define kTexLeft 48
#define kTexTop 0
#define kTexWidth 24
#define kTexHeight 4


Laser::Bala::Bala(float posX, float posY, int ori){

    sprite_bala = new M_Sprite( kFich , kTexLeft , kTexTop , kTexWidth , kTexHeight , posX, posY);

    pos.setPosition(posX, posY);
	pos.setPosition(posX, posY);

    orientacion = ori;

    if(ori != 1){

        sprite_bala->rotar(180);
    }

}

void Laser::Bala::moverse(float posX, float posY){

    sprite_bala->mover(posX, posY);

    pos.setPosition(sprite_bala->getPosX(), sprite_bala->getPosY());
}

void Laser::Bala::rotar(float grad){

    sprite_bala->rotar(grad);
}


M_Sprite* Laser::Bala::getSprite(){

    return sprite_bala;
}

bool Laser::Bala::heColisionado(NPC* enemigo){

    if(sprite_bala->getSprite()->getGlobalBounds().intersects(enemigo->getSprite()->getSprite()->getGlobalBounds())){

        return true;
    }

    else{

        return false;
    }
}

/* ---------------- */



Laser::Laser(float posX, float posY, int orie) : Arma(){

    pX = posX;
    pY = posY;
    ori = orie;

    dmg = kDmg;

    cad = kCad;
    vel = kVel;

    mejora = false;

    municionMax = 100;
    municionActual = 100;
}

Laser::~Laser(){}

bool Laser::puedeDisparar(){

    float tmp = (float) contDisparo.getElapsedTime().asMilliseconds() / 1000;

    if(tmp >= cad && municionActual > 0){

        return true;
    }

    else{

        return false;
    }
}

void Laser::disparo(){

    if(puedeDisparar()){

        Bala* bala = new Bala(pX, pY, ori); 
        proyectiles.push_back(bala);

       contDisparo.restart();
       municionActual = municionActual - kMuncGas;
    }
}

void Laser::mejorar(){

    if(mejora == false){

        dmg = dmg * 2;
        mejora = true;
    }

}

void Laser::update(float dt, Map* m){

    for(unsigned int i = 0; i < proyectiles.size(); i++){

        if(!balaEstaLejos(i, m)){

            proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), 0);

            if(m->checkCollision(proyectiles.at(i)->getSprite()->getSprite()))
                proyectiles.erase(proyectiles.begin() + i);
        }

        else{

            proyectiles.erase(proyectiles.begin() + i);
        }
    }
    
}

void Laser::render(M_Window* vent, float percentTick){
    for(unsigned int i = 0; i < proyectiles.size(); i++){
        Vector2D posicion;
   
        posicion.x = proyectiles.at(i)->pos.getLastX()*(1-percentTick) + proyectiles.at(i)->pos.getX()*percentTick;
        posicion.y = proyectiles.at(i)->pos.getLastY()*(1-percentTick) + proyectiles.at(i)->pos.getY()*percentTick;

        proyectiles.at(i)->getSprite()->setPosition(posicion);

        vent->render(proyectiles.at(i)->getSprite());
    }

    
}

void Laser::balaImpactada(NPC* enemigo){
    for(unsigned int i = 0; i < proyectiles.size(); i++){

        if(proyectiles.at(i)->heColisionado(enemigo)){

            enemigo->reciboDmg(this->getDmg());
            proyectiles.erase(proyectiles.begin() + i);
        }

	}
}

bool Laser::balaEstaLejos(int i, Map* m){

    if((proyectiles.at(i)->getSprite()->getPosX() / m->getWidth() > m->getWidth() || proyectiles.at(i)->getSprite()->getPosX() / m->getWidth() < 0 )){

        return true;
    }

    else {

        return false;
    }
}