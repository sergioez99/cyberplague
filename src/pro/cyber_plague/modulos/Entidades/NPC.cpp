#include "NPC.h"

/*
CLASE ABSTRACTA NPC, NO SE PUEDE INSTANCIAR. TODAS LOS ENEMIGOS DEL JUEGO, HEREDAN DE ESTA CLASE.

Cualquier método que pueda ser usado solo por los enemigos se tiene que crear aqui.
*/

NPC::NPC(){}

NPC::~NPC(){}

void NPC::render(M_Window* vent, float percentTick){
    if(dmgColor!=0)
        dmgColor --;
    if(dmgColor==0)
        getSprite()->setColor(0);

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

void NPC::colision(float deltaTime, NPC* enemigo){
    //Simulamos el movimiento de ambos NPCs
    if(this->getScaleX() < 0)
        this->getSprite()->mover(-deltaTime * this->getVelMovimiento(), 0);
    else
        this->getSprite()->mover(deltaTime * this->getVelMovimiento(), 0);

    if(enemigo->getScaleX() < 0)
        enemigo->getSprite()->mover(-deltaTime * enemigo->getVelMovimiento(), 0);
    else
        enemigo->getSprite()->mover(deltaTime * enemigo->getVelMovimiento(), 0);

    if(this->getSprite()->getSprite()->getGlobalBounds().intersects(enemigo->getSprite()->getSprite()->getGlobalBounds())){
        //Si se chocan de frente ambos se dan la vuelta
        if((this->getScaleX() < 0 && enemigo->getScaleX() > 0) ||(this->getScaleX() > 0 && enemigo->getScaleX() < 0)){
            this->escalar(-1.0f, 1.0f);
            enemigo->escalar(-1.0f, 1.0f);
        }
        else{
            //Si ambos van en la misma direccion se da la vuelta el NPC que choque por detras al otro
            if(this->getScaleX() < 0){
                if(this->getPosX() > enemigo->getPosX())
                    this->escalar(-1.0f, 1.0f);
                else
                    enemigo->escalar(-1.0f, 1.0f);
            }
            else{
                if(this->getPosX() < enemigo->getPosX())
                    this->escalar(-1.0f, 1.0f);
                else
                    enemigo->escalar(-1.0f, 1.0f);
            }
        }
    }
}