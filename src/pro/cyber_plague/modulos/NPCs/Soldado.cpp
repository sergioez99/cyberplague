#include "Soldado.h"

Soldado::Soldado(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY, 50.0f, 200.0f){
    cadencia = 1.0f;
    time = spawnClock.getElapsedTime();
}

Soldado::~Soldado(){
    
}

void Soldado::update(float deltaTime){
    //Disparar
    if(deteccion()){
        if(disparar()){
            //Generar bala
        }
    }
    //Mover
    else{
        //Cambiar direccion del sprite
        if(hayCaida())
            getSprite()->escalar(getSprite()->getSprite()->getScale().x * -1, getSprite()->getSprite()->getScale().y);

        mover(deltaTime);
    }
}

bool Soldado::deteccion(){
    float x, y; //Acceder a la posicion de jugador
    float distancia = sqrt(pow(abs(x - getSprite()->getSprite()->getPosition().x), 2) + pow(abs(y - getSprite()->getSprite()->getPosition().y), 2));
    
    if(distancia <= getRango()){
        getSprite()->escalar(-1, 1);

        return true;
    }

    return false;
}

bool Soldado::disparar(){
    if(spawnClock.getElapsedTime().asSeconds() - time.asSeconds() > cadencia)
        return true;

    return false;
}

void Soldado::mover(float deltaTime){
    if(getSprite()->getSprite()->getScale().x < 0)
        getSprite()->mover(-(getVelMovimiento() * deltaTime), 0);
    else
        getSprite()->mover(getVelMovimiento() * deltaTime, 0);
}

bool Soldado::hayCaida(){
    //Pasar posicion del sprite a colisiones y comprobar si en el nodo siguiente hay una caida
}