#include "Arco.h"

/* STATS DEL ARMA */

#define kDmg 40
#define kCad 2
#define kVel 400.0f
#define kMuncGas 10  //MUNICION QUE GASTA EL ARMA POR DISPARO


/* -------------- */


/* DATOS DE LA BALA */

#define kFich "spritesheet_armas.png"
#define kTexLeft 0
#define kTexTop 0
#define kTexWidth 32
#define kTexHeight 10


Arco::Bala::Bala(float posX, float posY, int ori){

    sprite_bala = new M_Sprite( kFich , kTexLeft , kTexTop , kTexWidth , kTexHeight , posX, posY);

    orientacion = ori;

    if(ori != 1){

        sprite_bala->rotar(180);
    }

}

void Arco::Bala::moverse(float posX, float posY){

    sprite_bala->mover(posX, posY);
}

void Arco::Bala::rotar(float grad){

    sprite_bala->rotar(grad);
}

M_Sprite* Arco::Bala::getSprite(){

    return sprite_bala;
}

bool Arco::Bala::heColisionado(NPC* enemigo){

    if(sprite_bala->getSprite()->getGlobalBounds().intersects(enemigo->getSprite()->getSprite()->getGlobalBounds())){

        return true;
    }

    else{

        return false;
    }
}

/* ---------------- */



Arco::Arco(float posX, float posY, int orie) : Arma(){

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

Arco::~Arco(){}

bool Arco::puedeDisparar(){

    float tmp = (float) contDisparo.getElapsedTime().asMilliseconds() / 1000;

    if(tmp >= cad && municionActual > 0){

        return true;
    }

    else{

        return false;
    }
}


void Arco::disparo(){

    if(puedeDisparar()){

        if(mejora){

            for(unsigned int i = 0; i < 3; i++){
                

                Bala* bala = new Bala(pX, pY, ori); 

                switch (i) {

                    case 0:

                        bala->rotar(30);
                        break;
                    
                    case 2:

                        bala->rotar(-30);
                        break;

                    default:
                        break;
                }

                proyectiles.push_back(bala);        
            }

        }
        
        else{

            Bala* bala = new Bala(pX, pY, ori); 
            proyectiles.push_back(bala);
        }

        municionActual = municionActual - kMuncGas;
       contDisparo.restart();
    }
}

void Arco::mejorar(){

    mejora = true; 
}

void Arco::update(float dt){

    if(mejora){

        int resto = 0;

        for(unsigned int i = 0; i < proyectiles.size(); i++){

            resto = i % 3;

            switch(resto){

                case 0: 

                    proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), proyectiles.at(i)->orientacion * ((vel * dt) / 3));  //BALA SUPERIOR.
                
                    break;

                case 1:

                    proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), 0); //BALA MEDIA
                    break;

                case 2:

                    proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), -proyectiles.at(i)->orientacion * (vel * dt)/ 3); //BALA INFERIOR.
                    break;
            }

            
        }
    }

    else{

        for(unsigned int i = 0; i < proyectiles.size(); i++){

            proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), 0);
        }
    }
}

void Arco::render(M_Window* vent){
    for(unsigned int i = 0; i < proyectiles.size(); i++){

        vent->render(proyectiles.at(i)->getSprite());
    }

    
}

void Arco::balaImpactada(NPC* enemigo){
    for(unsigned int i = 0; i < proyectiles.size(); i++){

        if(proyectiles.at(i)->heColisionado(enemigo)){

            enemigo->reciboDmg(getDmg());
        }

	}
}