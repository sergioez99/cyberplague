#include "Pajaro.h"

Pajaro::Pajaro(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY, 50.0f, 300.0f){
}

Pajaro::~Pajaro(){
    
}

void Pajaro::update(float deltaTime){
    //Mover
    if(deteccion())
        mover(deltaTime);
}

bool Pajaro::deteccion(){
    float x, y; //Acceder a la posicion de jugador
    float distancia = sqrt(pow(abs(x - getSprite()->getSprite()->getPosition().x), 2) + pow(abs(y - getSprite()->getSprite()->getPosition().y), 2));
    
    if(distancia <= getRango()){
        getSprite()->escalar(-1, 1);

        return true;
    }

    return false;
}

void Pajaro::mover(float deltaTime){
    list<Vector2f> camino;  //Incluir nodo y pathfinding a AI_Agent y obtener una lista con el camino a seguir pasandole posEnemigo y posJugador

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