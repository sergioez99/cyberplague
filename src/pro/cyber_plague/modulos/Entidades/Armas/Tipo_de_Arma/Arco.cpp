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


/* ---------------- */



Arco::Arco() : Arma(){

    dmg = kDmg;
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

                M_Sprite* bala = new M_Sprite(kFich, kTexLeft, kTexTop, kTexWidth, kTexHeight, 640 / 2, 480 / 2); 
                proyectiles.push_back(bala);
            }

        }
        
        else{

            M_Sprite* bala = new M_Sprite(kFich,kTexLeft, kTexTop, kTexWidth, kTexHeight, 640 / 2, 480 / 2);
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

                    proyectiles.at(i)->mover(vel * dt, (vel * dt) / 3);  //BALA SUPERIOR.
                    break;

                case 1:

                    proyectiles.at(i)->mover(vel * dt, 0); //BALA MEDIA
                    break;

                case 2:

                    proyectiles.at(i)->mover(vel * dt, -(vel * dt) / 3); //BALA INFERIOR.
                    break;
            }

            
        }
    }

    else{

        for(unsigned int i = 0; i < proyectiles.size(); i++){

            proyectiles.at(i)->mover(vel * dt, 0);
        }
    }
}