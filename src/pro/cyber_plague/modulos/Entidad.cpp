#include "Entidad.h"

Entidad::Entidad(){}

Entidad::~Entidad(){}

void Entidad::escalar(float x, float y){

    spr->escalar(x, y);
}

bool Entidad::muerto(){

    if(*vida <= 0){return true;}
    else{return false;}

}

void Entidad::render(M_Window* vent){

    vent->render(spr);
}

/* SETTERS Y GETTERS */

M_Sprite* Entidad::getSprite(){

    return spr;
}


bool Entidad::isGrounded(){

    return grounded;

}

void Entidad::setGrounded(bool ground){
    grounded = ground;
}
int Entidad::getVida(){

    return *vida;
}

int Entidad::getArmadura(){

    return *armadura;
}

float Entidad::getVelMovimiento(){

    return *vel;
}

float Entidad::getPosX(){

    return spr->getSprite()->getPosition().x;
}

float Entidad::getPosY(){

    return spr->getSprite()->getPosition().y;
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

Vector2D Entidad::getLastPosition(){
    return lastPosition;
}

void Entidad::setLastPosition(){
    lastPosition.x = getPosX();
    lastPosition.y = getPosY();
}

/* ---------------------------------------------------------- */