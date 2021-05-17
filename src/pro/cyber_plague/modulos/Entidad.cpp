#include "Entidad.h"

#define kTempInv 0.5f

Entidad::Entidad(){}

Entidad::~Entidad(){}

void Entidad::escalar(float x, float y){

    spr->escalar(x, y);
}


bool Entidad::muerto(){

    if(*vida <= 0){
        
        heMuerto = true;
        *vida = 0;
    }
    
    return heMuerto;
}

void Entidad::vivo(){

    heMuerto = false;

    *vida = *vidaMax;
}

void Entidad::reciboDmg(int dmg){

    int dmgRecibido = dmg - *armadura;
    
    float temp = (float) invencibilidad.getElapsedTime().asMilliseconds() / 1000;
    cout << temp << endl;
    if(temp > kTempInv){

        if(dmgRecibido <= 0){

            *vida = *vida - 1;
        }

        else{

            *vida = *vida - dmgRecibido;
        }
        invencibilidad.restart();
        getSprite()->setColor(1);
        dmgColor=15;
    }

}

/* SETTERS Y GETTERS */

M_Sprite* Entidad::getSprite(){

    return spr;
}


bool Entidad::isGrounded(){

    return grounded;

}

bool Entidad::isJumping(){
    if(salto>0)
        return true;
    return false;

}

void Entidad::setGrounded(bool ground){
    grounded = ground;
}
int Entidad::getVida(){

    return *vida;
}

int Entidad::getVidaMax(){

    return *vidaMax;
}

int Entidad::getArmadura(){

    return *armadura;
}

float Entidad::getVelMovimiento(){

    return *vel;
}

float Entidad::getPosX(){

    return spr->getPosX();
}

float Entidad::getPosY(){

    return spr->getPosY();
}

float Entidad::getScaleX(){

    return spr->getSprite()->getScale().x;
}

float Entidad::getScaleY(){

    return spr->getSprite()->getScale().y;
}


void Entidad::setVida(int vi){

    if(vida == 0){vida = new int(vi);}
    else{

        *vida = vi;
    }
}

void Entidad::setArmadura(int arm){

    if(armadura == 0){armadura = new int(arm);}
    else{

        *armadura = arm;
    }

}

void Entidad::setVelocidad(float velMov){

    if(vel == 0){vel = new float(velMov);}
    else{

        *vel = velMov;
    }
}

void Entidad::setPosition(Vector2D position){

    pos.setPosition(position.x, position.y);
    spr->setPosition(position);
}

void Entidad::setPosition(float posX, float posY){

    pos.setPosition(posX, posY);
    spr->setPosition(posX, posY);
}

Vector2D Entidad::getLastPosition(){
    return lastPosition;
}

void Entidad::setLastPosition(){
    lastPosition.x = getPosX();
    lastPosition.y = getPosY();
}

/* ---------------------------------------------------------- */