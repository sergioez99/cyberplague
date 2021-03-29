#include "Pajaro.h"

Pajaro::Pajaro(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY, 50.0f, 300.0f){
}

Pajaro::~Pajaro(){
    
}

void mover(float deltaTime, float x, float y){
    //Incluir nodo y pathfinding y con la matriz de colisiones obtener el camino a seguir
}

bool Pajaro::deteccion(float x, float y){
    float distancia = sqrt(pow(abs(x - getSprite()->getSprite()->getPosition().x), 2) + pow(abs(y - getSprite()->getSprite()->getPosition().y), 2));
    
    if(distancia <= getRango()){
        getSprite()->escalar(-1, 1);

        return true;
    }

    return false;
}