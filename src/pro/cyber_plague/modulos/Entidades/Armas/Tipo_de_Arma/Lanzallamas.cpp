#include "Lanzallamas.h"

/* STATS DEL ARMA */

#define kDmg 10
#define kTmpMuncGas 0.4f  //TIEMPO QUE DEBE PASAR PARA QUE EL ARMA GASTE MUNICION.
#define kVel 700.0f
#define kMuncGas 2  //MUNICION QUE GASTA EL ARMA

/* -------------- */


/* DATOS DE LA BALA */

#define kFich "spritesheet_otros.png"
#define kTexLeft 73
#define kTexTop 0
#define kTexWidth 28
#define kTexHeight 23


Lanzallamas::Bala::Bala(float posX, float posY, int ori){

    sprite_bala = new M_Sprite( kFich , kTexLeft , kTexTop , kTexWidth , kTexHeight , posX, posY);

    pos.setPosition(posX, posY);
	pos.setPosition(posX, posY);

    orientacion = ori;

}

void Lanzallamas::Bala::moverse(float posX, float posY, int i, int orie){

    Vector2D position;

    if(orientacion != orie){

        sprite_bala->escalar(-1, 1);
    }

    orientacion = orie;

    switch (i)
    {

    case 0:

        position.x = posX + (orientacion * 25);
        position.y = posY - 5;

        sprite_bala->setPosition(position);

        pos.setPosition(sprite_bala->getPosX(), sprite_bala->getPosY());

        break;
    
    case 1:

        position.x = posX + (orientacion * 40);
        position.y = posY - 15;

        sprite_bala->setPosition(position);

        pos.setPosition(sprite_bala->getPosX(), sprite_bala->getPosY());

        break;
    
    case 2:

        position.x = posX + (orientacion * 60);
        position.y = posY - 18;

        sprite_bala->setPosition(position);

        pos.setPosition(sprite_bala->getPosX(), sprite_bala->getPosY());

        break;

    case 3:

        position.x = posX + (orientacion * 80);
        position.y = posY - 18;

        sprite_bala->setPosition(position);

        pos.setPosition(sprite_bala->getPosX(), sprite_bala->getPosY());

        break;

    default:

        break;
    }
}

void Lanzallamas::Bala::rotar(float grad){

    sprite_bala->rotar(grad);
}

M_Sprite* Lanzallamas::Bala::getSprite(){

    return sprite_bala;
}

bool Lanzallamas::Bala::heColisionado(NPC* enemigo){

    if(sprite_bala->intersects(enemigo->getSprite())){

        return true;
    }

    else{

        return false;
    }
}

bool Lanzallamas::Bala::heColisionado(Cofre* cofre){

    if(sprite_bala->intersects(cofre->getSprite())){
    
        return true;
    }

    else{

        return false;
    }
}


/* ---------------- */



Lanzallamas::Lanzallamas(float posX, float posY, int orie) : Arma(){

    pX = posX;
    pY = posY;
    ori = orie;

    dmg = kDmg;

    cad = kTmpMuncGas;
    vel = kVel;

    mejora = false;

    tipo = "lanzallamas";

    municionMax = 100;
    municionActual = municionMax;
}

Lanzallamas::~Lanzallamas(){}

bool Lanzallamas::puedeDisparar(){

    if(municionActual > 0){ 

        return true;
    }

    else{

        return false;
    }
}


void Lanzallamas::disparo(){

    if(proyectiles.empty()){

        if(mejora == true){

            Bala* bala1 = new Bala(pX + (ori * 25), pY - 5, ori); 
            Bala* bala2 = new Bala(pX + (ori * 25), pY - 15, ori); 
            Bala* bala3 = new Bala(pX + (ori * 25), pY - 18, ori);
            Bala* bala4 = new Bala(pX + (ori * 25), pY - 18, ori);  

            bala1->getSprite()->escalar(ori * 1.0f, 1.0f);
            bala2->getSprite()->escalar(ori * 2.0f, 2.0f);
            bala3->getSprite()->escalar(ori * 2.5f, 2.5f);
            bala4->getSprite()->escalar(ori * 3.0f, 2.5f);

            proyectiles.push_back(bala1);
            proyectiles.push_back(bala2);
            proyectiles.push_back(bala3);
            proyectiles.push_back(bala4);
        }

       else{

            Bala* bala1 = new Bala(pX + (ori * 25), pY - 5, ori); 
            Bala* bala2 = new Bala(pX + (ori * 25), pY - 15, ori); 

            bala1->getSprite()->escalar(ori * 1.0f, 1.0f);
            bala2->getSprite()->escalar(ori * 2.0f, 2.0f);

            proyectiles.push_back(bala1);
            proyectiles.push_back(bala2);
        } 

        
    }

    float tmp = (float) contDisparo.getElapsedTime().asMilliseconds() / 1000;

    if(tmp >= cad){

        municionActual = municionActual - kMuncGas;

        contDisparo.restart();
    }   
}

void Lanzallamas::mejorar(){

    if(mejora == false){

        dmg = dmg * 2;

        mejora = true;
    }
}

void Lanzallamas::update(float dt, Map* m){

    for(unsigned int i = 0; i < proyectiles.size(); i++){

        proyectiles.at(i)->moverse(pX, pY, i, ori);
    }
}

void Lanzallamas::render(M_Window* vent, float percentTick){
    
    for(unsigned int i = 0; i < proyectiles.size(); i++){
        Vector2D posicion;
   
        posicion.x = proyectiles.at(i)->pos.getLastX()*(1-percentTick) + proyectiles.at(i)->pos.getX()*percentTick;
        posicion.y = proyectiles.at(i)->pos.getLastY()*(1-percentTick) + proyectiles.at(i)->pos.getY()*percentTick;

        proyectiles.at(i)->getSprite()->setPosition(posicion);

        vent->render(proyectiles.at(i)->getSprite());
    }

    
}

void Lanzallamas::balaImpactada(NPC* enemigo){

    for(unsigned int i = 0; i < proyectiles.size(); i++){

        if(proyectiles.at(i)->heColisionado(enemigo) && puedeDisparar()){

            enemigo->reciboDmg(this->getDmg());
        }

	}
}

void Lanzallamas::balaImpactada(Cofre* cofre){
    for(unsigned int i = 0; i < proyectiles.size(); i++){

        if(proyectiles.at(i)->heColisionado(cofre)){

            cofre->abrir();
        }
	}
}

void Lanzallamas::limpiarCargador(){

    proyectiles.clear();
}