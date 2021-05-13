#include "Soldado.h"

/* STATS */

#define kVida  15
#define kArm  5
#define kVel  75.0f
#define kRang  50.0f
#define kCad 1.0f

/*--------------*/

Soldado::Soldado(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(){

    spr = new M_Sprite(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY);

    vida = new int( kVida );
    armadura = new int( kArm );
    vel = new float( kVel );

    rango = new float( kRang );

    cadencia = kCad;

    currentImage = 0;

    time = spawnClock.getElapsedTime();

    pos.setPosition(posX, posY);
    pos.setPosition(posX, posY);
}

Soldado::~Soldado(){
    
    delete spr;
    delete vida;
    delete armadura;
    delete vel;
    delete rango;

}

void Soldado::update(float deltaTime, Map *m){
    //Animacion
    if(animationClock.getElapsedTime().asSeconds() >= 0.15f){
        currentImage++;
        if(currentImage > 3)
            currentImage = 0;

        spr->cambiarPosTextura(currentImage*36, 0, 36, 40);

        animationClock.restart();
    }
    //Disparar
    if(deteccion()){
        if(puedoAtacar()){
            //Generar bala

            ataque();
        }
    }
    //Mover
    else{
        //Cambiar direccion del sprite
        if(m->checkCaida(this->getSprite()->getSprite()))
            this->escalar(-1.0f, 1.0f);

        moverse(deltaTime);
    }
}

bool Soldado::deteccion(){
    float x = 0, y = 0; //Acceder a la posicion de jugador
    float distancia = sqrt(pow(abs(x - this->getPosX()), 2) + pow(abs(y - this->getPosY()), 2));
    
    /*if(distancia <= getRango()){
        this->escalar(-1, 1);

        return true;
    }*/

    return false;
}

void Soldado::ataque(){

    //EL ENEMIGO ATACA.
    cout << "Atacando..." << endl;
}

bool Soldado::puedoAtacar(){
    if(spawnClock.getElapsedTime().asSeconds() - time.asSeconds() > cadencia)
        return true;

    return false;
}

void Soldado::moverse(float deltaTime){
    Vector2D mov;
    mov.y = 0.f;
    
    if(this->getScaleX() < 0)
        mov.x = -deltaTime * getVelMovimiento();
    else
        mov.x = deltaTime * getVelMovimiento();

    pos.setPosition(pos.getX() + mov.x, pos.getY() + mov.y);
}