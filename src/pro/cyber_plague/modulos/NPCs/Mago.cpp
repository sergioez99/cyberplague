#include "Mago.h"

Mago::Mago(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY, 0.0f, 400.0f){
    spawnTime = 2.0f;
}

Mago::~Mago(){
    
}

bool Mago::deteccion(float x, float y){
    float distancia = sqrt(pow(abs(x - getSprite()->getSprite()->getPosition().x), 2) + pow(abs(y - getSprite()->getSprite()->getPosition().y), 2));
    
    if(distancia <= getRango()){
        getSprite()->escalar(-1, 1);

        return true;
    }

    return false;
}

bool Mago::generarEnemigo(float deltaTime){
    if(deltaTime > spawnTime)
        return true;
    
    return false;
}