#include "Zombi.h"

Zombi::Zombi(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY, 50.0f, 0.0f){
    
}

Zombi::~Zombi(){
    
}

void Zombi::mover(float deltaTime){
    //Cambiar direccion del sprite
    if(hayCaida())
        getSprite()->escalar(getSprite()->getSprite()->getScale().x * -1, getSprite()->getSprite()->getScale().y);

    if(getSprite()->getSprite()->getScale().x < 0)
        getSprite()->mover(-(getVelMovimiento() * deltaTime), 0);
    else
        getSprite()->mover(getVelMovimiento() * deltaTime, 0);
}

bool Zombi::hayCaida(){
    //Colisiones
}