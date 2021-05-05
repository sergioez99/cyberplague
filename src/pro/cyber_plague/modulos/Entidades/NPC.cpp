#include "NPC.h"

/*
CLASE ABSTRACTA NPC, NO SE PUEDE INSTANCIAR. TODAS LOS ENEMIGOS DEL JUEGO, HEREDAN DE ESTA CLASE.

Cualquier método que pueda ser usado solo por los enemigos se tiene que crear aqui.
*/

NPC::NPC(){}

NPC::~NPC(){}

void NPC::render(M_Window* vent, float percentTick){

    Vector2D posicion;

    posicion.x = pos.getLastX()*(1-percentTick) + pos.getX()*percentTick;
    posicion.y = pos.getLastY()*(1-percentTick) + pos.getY()*percentTick;

    spr->setPosition(posicion);
 
    vent->render(spr);
}

float NPC::getRango(){
    return *rango;
}

Moneda* NPC::getLoot(){

    return loot;
}

Moneda* NPC::looteoMoneda(){

    srand((unsigned) time(0));

    int probLoot = rand() % 100 + 1;
    int probMoneda = rand() % 100 + 1;

    Moneda* moneda = 0;

    if(probLoot <= 20){

        if(probMoneda <= 10){

            moneda = new Moneda(100, getPosX(), getPosY());
        }

        else if(probMoneda > 10 && probMoneda <= 40){

            moneda = new Moneda(50, getPosX(), getPosY());
        }     

        else{

            moneda = new Moneda(10, getPosX(), getPosY());
        }

    }

    return moneda;

}