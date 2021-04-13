#include "Arco.h"

/* STATS DEL ARMA */

#define kDmg 40
#define kCad 2
#define kVel 400.0f

/* -------------- */


/* DATOS DE LA BALA */

#define kFich "flecha.png"
#define kTexLeft 0
#define kTexTop 0
#define kTexWidth 32
#define kTexHeight 10


Arma::Bala::Bala(float posX, float posY, int ori){

    sprite_bala = new M_Sprite( kFich , kTexLeft , kTexTop , kTexWidth , kTexHeight , posX, posY);

    orientacion = ori;

    if(ori != 1){

        sprite_bala->rotar(180);
    }

}

void Arma::Bala::moverse(float posX, float posY){

    sprite_bala->mover(posX, posY);
}

void Arma::Bala::rotar(float grad){

    sprite_bala->rotar(grad);
}

M_Sprite* Arma::Bala::getSprite(){

    return sprite_bala;
}

/* ---------------- */



Arco::Arco(Player * p) : Arma(){

    jugador = p;

    dmg = kDmg + p->getDmg();
    cad = kCad;
    vel = kVel;

    mejora = false;
}

Arco::~Arco(){}

void Arco::disparo(){

    if(puedeDisparar()){

        if(mejora){

            for(unsigned int i = 0; i < 3; i++){

                //La posicion habria que ajustarla a la del jugador.

                

                Bala* bala = new Bala(jugador->getPosX(), jugador->getPosY(), jugador->mirandoDerecha()); 

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

            Bala* bala = new Bala(jugador->getPosX(), jugador->getPosY(), jugador->mirandoDerecha()); 
            proyectiles.push_back(bala);
        }

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