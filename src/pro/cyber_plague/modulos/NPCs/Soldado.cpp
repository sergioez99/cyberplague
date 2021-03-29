#include "Soldado.h"

Soldado::Soldado(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY, 50.0f, 200.0f){
    velAtaque = 1.0f;
}

Soldado::~Soldado(){
    
}

void Soldado::mover(float deltaTime){
    //Cambiar direccion del sprite
    if(hayCaida())
        getSprite()->escalar(getSprite()->getSprite()->getScale().x * -1, getSprite()->getSprite()->getScale().y);

    if(getSprite()->getSprite()->getScale().x < 0)
        getSprite()->mover(-(getVelMovimiento() * deltaTime), 0);
    else
        getSprite()->mover(getVelMovimiento() * deltaTime, 0);
}

bool Soldado::hayCaida(){
    //Colisiones
}

bool Soldado::deteccion(float x, float y){
    float distancia = sqrt(pow(abs(x - getSprite()->getSprite()->getPosition().x), 2) + pow(abs(y - getSprite()->getSprite()->getPosition().y), 2));
    
    if(distancia <= getRango()){
        getSprite()->escalar(-1, 1);

        return true;
    }

    return false;
}

bool Soldado::disparar(float deltaTime){
    if(deltaTime > velAtaque)
        return true;

    return false;
}