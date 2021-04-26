#include "Entidad.h"

#define kTempInv 0.5f

Entidad::Entidad(){}

Entidad::~Entidad(){}

void Entidad::escalar(float x, float y){

    spr->escalar(x, y);
}

bool Entidad::muerto(){

    if(*vida <= 0){return true;}
    else{return false;}

}

void Entidad::reciboDmg(int dmg){

    int dmgRecibido = dmg - *armadura;

    cout << "Vida: " << *vida << " --- " << "Armadura: " << *armadura << "Daño: " << dmgRecibido << endl;
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

void Entidad::renderPlayer(M_Window* vent, float percentTick, Map* mapa){
    Vector2D posicion;
     if(dmgColor!=0)
        dmgColor --;
    if(dmgColor==0)
        getSprite()->setColor(0);
    posicion.x = pos.getLastX()*(1-percentTick) + pos.getX()*percentTick;
    posicion.y = pos.getLastY()*(1-percentTick) + pos.getY()*percentTick;

    //spr->setPosition(posicion);
    vent->renderPlayer(spr, mapa);
}

void Entidad::render(M_Window* vent, float percentTick){
    Vector2D posicion;
   
    posicion.x = pos.getLastX()*(1-percentTick) + pos.getX()*percentTick;
    posicion.y = pos.getLastY()*(1-percentTick) + pos.getY()*percentTick;

    //spr->setPosition(posicion);
    vent->render(spr);
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