#include "Arco.h"

/* STATS DEL ARMA */

#define kDmg 40
#define kCad 2
#define kVel 400.0f
#define kMuncGas 10  //MUNICION QUE GASTA EL ARMA POR DISPARO


/* -------------- */


/* DATOS DE LA BALA */

#define kFich "spritesheet_otros.png"
#define kTexLeft 0
#define kTexTop 0
#define kTexWidth 32
#define kTexHeight 10


Arco::Bala::Bala(float posX, float posY, int ori){

    sprite_bala = new M_Sprite( kFich , kTexLeft , kTexTop , kTexWidth , kTexHeight , posX, posY);

    pos.setPosition(posX, posY);
	pos.setPosition(posX, posY);

    orientacion = ori;

    if(ori != 1){

        sprite_bala->rotar(180);
    }

}

void Arco::Bala::moverse(float posX, float posY){

    sprite_bala->mover(posX, posY);

    pos.setPosition(sprite_bala->getPosX(), sprite_bala->getPosY());
}

void Arco::Bala::rotar(float grad){

    sprite_bala->rotar(grad);
}

float Arco::Bala::getRotation(){

    return sprite_bala->getRotation();
}

M_Sprite* Arco::Bala::getSprite(){

    return sprite_bala;
}

bool Arco::Bala::heColisionado(NPC* enemigo){

    if(sprite_bala->intersects(enemigo->getSprite())){

        return true;
    }

    else{

        return false;
    }
}

bool Arco::Bala::heColisionado(Cofre* cofre){

    if(sprite_bala->intersects(cofre->getSprite())){
    
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
    municionActual = municionMax;

    tipo = "arco";
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

void Arco::mejorar(){

    mejora = true; 
}

void Arco::update(float dt, Map* m){

    if(mejora){

        for(unsigned int i = 0; i < proyectiles.size(); i++){

            if(!balaEstaLejos(i, m)){

                float rotacion = proyectiles.at(i)->getRotation();

                if(rotacion == 30 || rotacion == 210){

                    proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), proyectiles.at(i)->orientacion * ((vel * dt) / 3));  //BALA SUPERIOR.
                }

                else if(rotacion == 330 || rotacion == 150){

                    proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), -proyectiles.at(i)->orientacion * (vel * dt)/ 3); //BALA INFERIOR.
                }

                else{

                    proyectiles.at(i)->moverse(proyectiles.at(i)->orientacion * (vel * dt), 0); //BALA MEDIA
                }
                
                if(m->checkCollision(proyectiles.at(i)->getSprite()->getSprite()))
                    proyectiles.erase(proyectiles.begin() + i);
            }

            else{

                proyectiles.erase(proyectiles.begin() + i);
            }

            
        }
    }

    else{

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
}

void Arco::render(M_Window* vent, float percentTick){
    for(unsigned int i = 0; i < proyectiles.size(); i++){
        Vector2D posicion;
   
        posicion.x = proyectiles.at(i)->pos.getLastX()*(1-percentTick) + proyectiles.at(i)->pos.getX()*percentTick;
        posicion.y = proyectiles.at(i)->pos.getLastY()*(1-percentTick) + proyectiles.at(i)->pos.getY()*percentTick;

        proyectiles.at(i)->getSprite()->setPosition(posicion);

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

void Arco::balaImpactada(Cofre* cofre){
    for(unsigned int i = 0; i < proyectiles.size(); i++){

        if(proyectiles.at(i)->heColisionado(cofre)){

            cofre->abrir();
        }

	}
}

bool Arco::balaEstaLejos(int i, Map* m){

    if((proyectiles.at(i)->getSprite()->getPosX() / m->getWidth() > m->getWidth() || proyectiles.at(i)->getSprite()->getPosX() / m->getWidth() < 0 ) || (proyectiles.at(i)->getSprite()->getPosY() / m->getHeight() > 2 * m->getHeight()|| proyectiles.at(i)->getSprite()->getPosY() / m->getHeight() < 0)){

        return true;
    }

    else {

        return false;
    }
}

void Arco::limpiarCargador(){

    proyectiles.clear();
}