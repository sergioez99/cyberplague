#include "Soldado.h"

Soldado::Soldado(Vector2f pos) {
    if (!textura.loadFromFile("resources/sprites.png")) {
        std::cerr << "Error cargando la textura";
        exit(0);
    }

    sprite = new Sprite(textura);
    sprite->setOrigin(75 / 2, 75);
    sprite->setTextureRect(sf::IntRect(2 * 85, 2 * 75, 75, 75));
    sprite->setPosition(pos);
    dirIzquierda = true;
    kVel = 50;
    rango = 200.0;
}

Soldado::Soldado(const Soldado &s){
    sprite = s.sprite;
    kVel = s.kVel;
    dirIzquierda = s.dirIzquierda;
    rango = s.rango;
}

Soldado::~Soldado(){
    delete sprite;
}

Sprite Soldado::getSprite(){
    return *sprite;
}

void Soldado::mover(float delta, int matriz[16][12]){
    if(hayCaida(matriz)){
        if(dirIzquierda)
            dirIzquierda = false;
        else
            dirIzquierda = true;
    }

    //El soldado se mueve hacia el lado izquierdo
    if(dirIzquierda){
        sprite->setScale(-1,1);
        sprite->move(-(kVel * delta), 0);
    }
    //Se mueve hacia el derecho
    else{
        sprite->setScale(1,1);
        sprite->move(kVel * delta, 0);
    }
}

bool Soldado::hayCaida(int matriz[16][12]){
    int x = ceil(sprite->getPosition().x / 40) - 1, y = ceil(sprite->getPosition().y / 40) - 1; //Suponiendo Tiles de 40x40

    if(dirIzquierda){
        if(matriz[x - 1][y + 1] != 1)   //Si no hay colision
            return true;

        return false;
    }
    else{
        if(matriz[x + 1][y + 1] != 1)   //Si no hay colision
            return true;
            
        return false;
    }
}

bool Soldado::deteccion(Vector2f pos){
    float distancia = sqrt(pow(abs(pos.x - sprite->getPosition().x), 2) + pow(abs(pos.y - sprite->getPosition().y), 2));

    //Jugador detecctado
    if(distancia <= rango){
        sprite->setScale(-1,1);

        return true;
    }
    else
        return false;
}