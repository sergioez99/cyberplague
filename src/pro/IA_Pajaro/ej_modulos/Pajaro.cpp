#include "Pajaro.h"

Pajaro::Pajaro(Vector2f pos) {
    if (!textura.loadFromFile("resources/sprites.png")) {
        std::cerr << "Error cargando la textura";
        exit(0);
    }

    sprite = new Sprite(textura);
    sprite->setOrigin(75 / 2, 75 / 2);
    sprite->setTextureRect(sf::IntRect(5 * 85, 0 * 75, 75, 75));
    sprite->setPosition(pos);
    kVel = 50;
    rango = 300.0;
}

Pajaro::Pajaro(const Pajaro &p){
    sprite = p.sprite;
    kVel = p.kVel;
    rango = p.rango;
}

Pajaro::~Pajaro(){
    delete sprite;
}

Sprite Pajaro::getSprite(){
    return *sprite;
}

void Pajaro::mover(float delta, int matriz[16][12], Vector2f posJugador){
    Pathfinding path;

    //Crear nodo inicio (enemigo) y calculamos donde esta en la matriz de colisiones
    int xEnemigo = ceil(sprite->getPosition().x / 40) - 1;
    int yEnemigo = ceil(sprite->getPosition().y / 40) - 1;
    Nodo inicio(NULL, xEnemigo, yEnemigo);

    //Crear nodo meta (jugador) y calculamos donde esta en la matriz de colisiones
    int xJugador = ceil(posJugador.x / 40) - 1;
    int yJugador = ceil(posJugador.y / 40) - 1;
    Nodo meta(NULL, xJugador, yJugador);

    if(inicio != meta){
        list<Nodo> camino = path.encontrarCamino(matriz, inicio, meta);
        list<Nodo>::iterator it = camino.begin();
        it++;
        Nodo siguiente = *it;

        //Se mueve hacia la izquierda
        if(xEnemigo > siguiente.getX()){
            sprite->setScale(-1,1);

            //Se mueve recto
            if(yEnemigo == siguiente.getY())
                sprite->move(-(kVel * delta), 0);
            //Se mueve en una diagonal
            else{
                //Se mueve hacia arriba
                if(yEnemigo > siguiente.getY())
                    sprite->move(-(kVel * delta), - (kVel * delta));
                //Se mueve hacia abajo
                else
                    sprite->move(-(kVel * delta), kVel * delta);
            }
        }
        //Se mueve hacia la derecha
        if(xEnemigo < siguiente.getX()){
            sprite->setScale(1,1);

            //Se mueve recto
            if(yEnemigo == siguiente.getY())
                sprite->move(kVel * delta, 0);
            //Se mueve en una diagonal
            else{
                //Se mueve hacia arriba
                if(yEnemigo > siguiente.getY())
                    sprite->move(kVel * delta, - (kVel * delta));
                //Se mueve hacia abajo
                else
                    sprite->move(kVel * delta, kVel * delta);
            }
        }
    }
    else{
        sprite->setTextureRect(sf::IntRect(5 * 85, 0 * 75, 75, 75));
        sprite->setScale(1,1);
    }
}

bool Pajaro::deteccion(Vector2f pos){
    float distancia = sqrt(pow(abs(pos.x - sprite->getPosition().x), 2) + pow(abs(pos.y - sprite->getPosition().y), 2));

    //Jugador detecctado
    if(distancia <= rango){
        sprite->setTextureRect(sf::IntRect(2 * 85, 2 * 75, 75, 75));

        return true;
    }
    else{
        sprite->setTextureRect(sf::IntRect(5 * 85, 0 * 75, 75, 75));
        sprite->setScale(1,1);

        return false;
    }
}