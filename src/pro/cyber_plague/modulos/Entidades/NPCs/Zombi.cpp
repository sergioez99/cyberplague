#include "Zombi.h"

/* STATS */

#define kVida  15
#define kArm  2
#define kVel  55.0f
#define kAta  20
#define kAtTime  2

/*--------------*/

Zombi::Zombi(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(){
    
    spr = new M_Sprite(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY);

    vida = new int( kVida );
    armadura = new int( kArm );
    vel = new float( kVel );
    ataq = kAta;

    attackTime = kAtTime;

    currentImage = 0;

    pos.setPosition(posX, posY);
    pos.setPosition(posX, posY);
}

Zombi::~Zombi(){
    
    delete spr;
    delete vida;
    delete armadura;
    delete vel;
}

void Zombi::update(float deltaTime, Map *m, M_Sprite* player){
    //Animacion
    if(animationClock.getElapsedTime().asSeconds() >= 0.15f){
        currentImage++;
        if(currentImage > 5)
            currentImage = 0;

        spr->cambiarPosTextura(currentImage*24, 0, 24, 40);

        animationClock.restart();
    }
    //Mover
    //Cambiar direccion del sprite
    if(m->checkCaida(this->getSprite()->getSprite()))
        this->escalar(-1.0f, 1.0f);

    moverse(deltaTime);
}

void Zombi::moverse(float deltaTime){
    Vector2D mov;
    mov.y = 0.f;
    
    if(this->getScaleX() < 0)
        mov.x = -deltaTime * getVelMovimiento();
    else
        mov.x = deltaTime * getVelMovimiento();

    pos.setPosition(pos.getX() + mov.x, pos.getY() + mov.y);
}

bool Zombi::puedoAtacar(){
    int tmp = attackClock.getElapsedTime().asSeconds();

    if(tmp >= attackTime){
        attackClock.restart();

        return true;
    }

    return false;
}