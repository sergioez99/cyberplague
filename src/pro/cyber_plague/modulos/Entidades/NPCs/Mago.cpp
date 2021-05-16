#include "Mago.h"

/* STATS */

#define kVida  20
#define kArm  10
#define kVel  400.0f
#define kRang  0.0f
#define kSt  2.0f

/*--------------*/


Mago::Mago(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(){

    spr = new M_Sprite(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY);

    vida = new int( kVida );
    armadura = new int( kArm );
    vel = new float( kVel );

    rango = new float( kRang );

    spawnTime = kSt;
    time = spawnClock.getElapsedTime();
}

Mago::~Mago(){

    delete spr;
    delete vida;
    delete armadura;
    delete vel;
    delete rango;

}

void Mago::ataque(){

    //ATAQUE DEL ENEMIGO
    cout << "Ataque" << endl;

}

void Mago::moverse(float deltaTime){

    //PATRON DE MOVIMIENTO DEL ENEMIGO
    cout << "Movimiento" << endl;
}

void Mago::update(float deltaTime, Map *m, M_Sprite* player){
    //Spawnear enemigo
    if(deteccion(player)){
        if(puedoAtacar()){
            //Generar enemigo

            ataque(); // Su ataque sera el de invocar enemigos. 
        }
    }
    //setLastPosition();//Ultima posicion buena del sprite
}

/*bool Mago::deteccion(M_Sprite* player){
    float x = 0, y = 0; //Acceder a la posicion de jugador
    float distancia = sqrt(pow(abs(x - this->getPosX()), 2) + pow(abs(y - this->getPosY()), 2));
    
    if(distancia <= getRango()){
        this->escalar(-1, 1);

        return true;
    }

    return false;
}*/

bool Mago::puedoAtacar(){
    if(spawnClock.getElapsedTime().asSeconds() - time.asSeconds() > spawnTime)
        return true;

    return false;
}