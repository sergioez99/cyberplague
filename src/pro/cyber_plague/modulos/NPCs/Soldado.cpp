#include "Soldado.h"

/* STATS */

#define kVida  50
#define kArm  20
#define kVel  200.0f
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

    time = spawnClock.getElapsedTime();
}

Soldado::~Soldado(){
    
    delete spr;
    delete vida;
    delete armadura;
    delete vel;
    delete rango;

}

void Soldado::update(float deltaTime){
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
        if(hayCaida())
            this->escalar(this->getScaleX() * - 1, this->getScaleY());

        moverse(deltaTime);
    }
}

bool Soldado::deteccion(){
    float x = 0, y = 0; //Acceder a la posicion de jugador
    float distancia = sqrt(pow(abs(x - this->getPosX()), 2) + pow(abs(y - this->getPosY()), 2));
    
    if(distancia <= getRango()){
        this->escalar(-1, 1);

        return true;
    }

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
    if(this->getScaleX() < 0)
        getSprite()->mover(-(getVelMovimiento() * deltaTime), 0);
    else
        getSprite()->mover(getVelMovimiento() * deltaTime, 0);
}

bool Soldado::hayCaida(){
    //Pasar posicion del sprite a colisiones y comprobar si en el nodo siguiente hay una caida

    return false;
}