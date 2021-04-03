#include "Zombi.h"

/* STATS */

#define kVida  50
#define kArm  20
#define kVel  200.0f

/*--------------*/

Zombi::Zombi(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(){
    
    spr = new M_Sprite(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY);

    vida = new int( kVida );
    armadura = new int( kArm );
    vel = new float( kVel );
}

Zombi::~Zombi(){
    
    delete spr;
    delete vida;
    delete armadura;
    delete vel;
}

void Zombi::update(float deltaTime){
    //Mover
    //Cambiar direccion del sprite
    if(hayCaida())
        this->escalar(this->getScaleX() * -1, this->getScaleY());

    moverse(deltaTime);
}

void Zombi::moverse(float deltaTime){
    if(this->getScaleX() < 0)
        getSprite()->mover(-(getVelMovimiento() * deltaTime), 0);
    else
        getSprite()->mover(getVelMovimiento() * deltaTime, 0);
}

bool Zombi::hayCaida(){
    //Pasar posicion del sprite a colisiones y comprobar si en el nodo siguiente hay una caida
}