#include "Mago.h"

Mago::Mago(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY, 0.0f, 400.0f){
    spawnTime = 2.0f;
    time = spawnClock.getElapsedTime();
}

Mago::~Mago(){
    
}

void Mago::update(float deltaTime){
    //Spawnear enemigo
    if(deteccion()){
        if(spawnEnemigo()){
            //Generar enemigo
        }
    }
}

bool Mago::deteccion(){
    float x, y; //Acceder a la posicion de jugador
    float distancia = sqrt(pow(abs(x - getSprite()->getSprite()->getPosition().x), 2) + pow(abs(y - getSprite()->getSprite()->getPosition().y), 2));
    
    if(distancia <= getRango()){
        getSprite()->escalar(-1, 1);

        return true;
    }

    return false;
}

bool Mago::spawnEnemigo(){
    if(spawnClock.getElapsedTime().asSeconds() - time.asSeconds() > spawnTime)
        return true;

    return false;
}