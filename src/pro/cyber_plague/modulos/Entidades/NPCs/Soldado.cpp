#include "Soldado.h"

/* STATS */

#define kVida  15
#define kArm  5
#define kVel  75.0f
#define kRang  150.0f
#define kCad 1.0f
#define kAta 10

/*--------------*/

Soldado::Bala::Bala(float posX, float posY, float vX, float vY, float angulo){
    spr_bala = new M_Sprite("spritesheet_otros.png", 32, 0, 16, 8, posX, posY);
    spr_bala->rotar(angulo);

    pos.setPosition(posX, posY);
	pos.setPosition(posX, posY);

    vx = vX;
    vy = vY;
    vel = 400.0f;

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
    ataq = kAta;

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

        if(puedoDisparar()){
            //Generar bala
            float distX = player->getPosX() - this->getPosX(), distY = player->getPosY() - this->getPosY();
            float distT = sqrt(pow(distX, 2) + pow(distY, 2));
            float vX = distX/distT, vY = distY/distT;
            float angulo = asin(distY/distT) * 180 / M_PI;

            if(vX < 0)
                angulo*= -1;

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

    for(int i = 0; i < (int)balas.size(); i++){
        balas.at(i)->update(deltaTime);

        if(balas.at(i)->getSprite()->getPosX() < 0 || balas.at(i)->getSprite()->getPosX() > m->getWidth() * m->getTileWidth() || balas.at(i)->getSprite()->getPosY() < 0 || balas.at(i)->getSprite()->getPosY() > m->getHeight() * m->getTileHeight())
            balas.erase(balas.begin() + i);
        else{
            if(m->checkCollision(balas.at(i)->getSprite()->getSprite()))
                balas.erase(balas.begin() + i);
        }
    }
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
    if(attackClock.getElapsedTime().asSeconds() >= 2.0f){
        attackClock.restart();

        return true;
    }

    return false;
}

bool Soldado::puedoDisparar(){
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

bool Soldado::colisionBala(M_Sprite* player){
    for(int i = 0; i < (int)balas.size(); i++){
        if(balas.at(i)->getSprite()->getSprite()->getGlobalBounds().intersects(player->getSprite()->getGlobalBounds())){
            balas.erase(balas.begin() + i);

            return true;
        }
    }

    return false;
}