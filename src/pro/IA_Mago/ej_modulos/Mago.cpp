#include "Mago.h"

Mago::Mago(Vector2f pos) {
    if (!textura.loadFromFile("resources/sprites.png")) {
        std::cerr << "Error cargando la textura";
        exit(0);
    }

    sprite = new Sprite(textura);
    sprite->setOrigin(75 / 2, 75);
    sprite->setTextureRect(sf::IntRect(5 * 85, 0 * 75, 75, 75));
    sprite->setPosition(pos);

    kUpdateTime = 2;
    rango = 200.0;
}

Mago::Mago(const Mago &m){
    sprite = m.sprite;
    kUpdateTime = m.kUpdateTime;
    rango = m.rango;
}

Mago::~Mago(){
    delete sprite;
}

Sprite Mago::getSprite(){
    return *sprite;
}

bool Mago::deteccion(Vector2f pos){
    float distancia = sqrt(pow(abs(pos.x - sprite->getPosition().x), 2) + pow(abs(pos.y - sprite->getPosition().y), 2));

    //Jugador detecctado
    if(distancia <= rango){
        sprite->setTextureRect(sf::IntRect(2 * 85, 2 * 75, 75, 75));
        sprite->setScale(-1,1);

        return true;
    }
    else{
        sprite->setTextureRect(sf::IntRect(5 * 85, 0 * 75, 75, 75));

        return false;
    }
}

void Mago::spawnEnemigo(){
    
}