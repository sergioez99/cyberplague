#include "Soldado.h"

/* STATS */

#define kVida  15
#define kArm  5
#define kVel  75.0f
#define kRang  150.0f
#define kCad 1.0f

/*--------------*/

Soldado::Bala::Bala(float posX, float posY, float vX, float vY, float angulo){
    spr_bala = new M_Sprite("spritesheet_otros.png", 32, 0, 16, 8, posX, posY);
    cout << angulo << endl;
    //spr_bala->rotar(angulo);

    pos.setPosition(posX, posY);
	pos.setPosition(posX, posY);

    vx = vX;
    vy = vY;
    dmg = 10;
    vel = 700.0f;

    if(vx < 0)
        spr_bala->escalar(-1.0f, 1.0f);
}

Soldado::Bala::~Bala(){
    delete spr_bala;
}

void Soldado::Bala::update(float deltaTime){
    spr_bala->mover(vx*deltaTime*vel, vy*deltaTime*vel);

    pos.setPosition(spr_bala->getPosX(), spr_bala->getPosY());
}

Soldado::Soldado(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY) : NPC(){

    spr = new M_Sprite(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY);

    vida = new int( kVida );
    armadura = new int( kArm );
    vel = new float( kVel );

    rango = new float( kRang );

    cadencia = kCad;

    currentImage = 0;

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

void Soldado::update(float deltaTime, Map *m, M_Sprite* player){
    //Animacion
    if(animationClock.getElapsedTime().asSeconds() >= 0.15f){
        currentImage++;
        if(currentImage > 3)
            currentImage = 0;

        spr->cambiarPosTextura(currentImage*36, 0, 36, 40);

        animationClock.restart();
    }
    //Disparar
    if(deteccion(player)){
        pos.setPosition(pos.getX(), pos.getY());
        spr->cambiarPosTextura(0, 40, 36, 40);

        if((player->getPosX() < this->getPosX() && this->getScaleX() > 0) || player->getPosX() > this->getPosX() && this->getScaleX() < 0)
            this->escalar(-1.0f, 1.0f);

        if(puedoAtacar()){
            //Generar bala
            float distX = player->getPosX() - this->getPosX(), distY = player->getPosY() - this->getPosY();
            float distT = sqrt(pow(distX, 2) + pow(distY, 2));
            float vX = distX/distT, vY = distY/distT;
            float angulo = asin(distY/distT);

            Bala* bala = new Bala(this->getPosX(), this->getPosY(), vX, vY, angulo);
            balas.push_back(bala);
        }
    }
    //Mover
    else{
        //Cambiar direccion del sprite
        if(m->checkCaida(this->getSprite()->getSprite()))
            this->escalar(-1.0f, 1.0f);

        moverse(deltaTime);
    }

    for(int i = 0; i < (int)balas.size(); i++)
        balas.at(i)->update(deltaTime);
}

bool Soldado::deteccion(M_Sprite* player){
    float distancia = sqrt(pow(abs(player->getPosX() - this->getPosX()), 2) + pow(abs(player->getPosY() - this->getPosY()), 2));
    
    if(distancia <= getRango()){
        //this->escalar(-1, 1);

        return true;
    }

    return false;
}

void Soldado::ataque(){

    //EL ENEMIGO ATACA.
    cout << "Atacando..." << endl;
}

bool Soldado::puedoAtacar(){
    if(spawnClock.getElapsedTime().asSeconds() >= cadencia){
        spawnClock.restart();

        return true;
    }

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

void Soldado::render(M_Window* vent, float percentTick){
    Vector2D posicion;

    posicion.x = pos.getLastX()*(1-percentTick) + pos.getX()*percentTick;
    posicion.y = pos.getLastY()*(1-percentTick) + pos.getY()*percentTick;

    spr->setPosition(posicion);
 
    vent->render(spr);

    for(int i = 0; i < (int)balas.size(); i++){
        posicion.x = balas.at(i)->getPosInterpolada().getLastX()*(1-percentTick) + balas.at(i)->getPosInterpolada().getX()*percentTick;
        posicion.y = balas.at(i)->getPosInterpolada().getLastY()*(1-percentTick) + balas.at(i)->getPosInterpolada().getY()*percentTick;

        balas.at(i)->getSprite()->setPosition(posicion);
        
        vent->render(balas.at(i)->getSprite());
    }
}