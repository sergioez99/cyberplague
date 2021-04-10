#include "Pajaro.h"

/* STATS */

#define kVida  5
#define kArm  1
#define kVel  300.0f
#define kRang  50.0f

/*--------------*/



Pajaro::Pajaro(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(){

    spr = new M_Sprite(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY);

    vida = new int( kVida );
    armadura = new int( kArm );
    vel = new float( kVel );

    rango = new float( kRang );


}


Pajaro::~Pajaro(){
    
    delete vida;
    delete armadura;
    delete vel;
    delete rango;
}

void Pajaro::update(float deltaTime){
    //Mover
    if(deteccion())
        moverse(deltaTime);
}

bool Pajaro::deteccion(){

    float x = 0, y = 0; //Acceder a la posicion de jugador
    float distancia = sqrt(pow(abs(x - this->getPosX()), 2) + pow(abs(y - this->getPosY()), 2));
    
    if(distancia <= getRango()){
        
        this->escalar(-1, 1);

        return true;
    }

    return false;
}

void Pajaro::moverse(float deltaTime){
    AI_Agent ai;
    Vector2f ini = getSprite()->getSprite()->getPosition();
    Vector2f fin;   //Poscion jugador
    list<Vector2f> camino = ai.encontrarCamino(ini, fin);

    //Si el enemigo no esta ya junto al jugador
    if(camino.size() > 1){
        list<Vector2f>::iterator it = camino.begin();
        Vector2f posEnemigo = *it;
        it++;
        Vector2f posSiguiente = *it;

        //Se mueve a la izquierda
        if(posEnemigo.x > posSiguiente.x){
            getSprite()->escalar(-1, 1);

            //Se mueve izquierda
            if(posEnemigo.y == posSiguiente.y)
                getSprite()->mover(-(getVelMovimiento() * deltaTime), 0);
            else{
                //Se mueve arriba izquierda
                if(posEnemigo.y > posSiguiente.y)
                    getSprite()->mover(-(getVelMovimiento() * deltaTime), -(getVelMovimiento() * deltaTime));
                //Se mueve abajo izquierda
                else
                    getSprite()->mover(-(getVelMovimiento() * deltaTime), getVelMovimiento() * deltaTime);
            }
        }
        //Se mueve a la derecha
        if(posEnemigo.x < posSiguiente.x){
            getSprite()->escalar(1, 1);

            //Se mueve derecha
            if(posEnemigo.y == posSiguiente.y)
                getSprite()->mover(getVelMovimiento() * deltaTime, 0);
            else{
                //Se mueve arriba derecha
                if(posEnemigo.y > posSiguiente.y)
                    getSprite()->mover(getVelMovimiento() * deltaTime, -(getVelMovimiento() * deltaTime));
                //Se mueve abajo derecha
                else
                    getSprite()->mover(getVelMovimiento() * deltaTime, getVelMovimiento() * deltaTime);
            }
        }
        //No se mueve en eje x
        if(posEnemigo.x == posSiguiente.x){
            getSprite()->escalar(1, 1);

            //Se mueve arriba
            if(posEnemigo.y > posSiguiente.y)
                getSprite()->mover(0, -(getVelMovimiento() * deltaTime));
            //Se mueve abajo
                getSprite()->mover(0, -(getVelMovimiento() * deltaTime));
        }
    }
}