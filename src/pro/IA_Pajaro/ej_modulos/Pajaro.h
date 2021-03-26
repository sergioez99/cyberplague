#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Pathfinding.h"

using namespace std;
using namespace sf;

class Pajaro{
    private:
        Texture textura;
        Sprite* sprite;
        int kVel;               //Velocidad de movimiento
        float rango;
    public:
        Pajaro(Vector2f pos);
        Pajaro(const Pajaro &);
        ~Pajaro();

        Sprite getSprite();
        void mover(float delta, int matriz[16][12], Vector2f posJugador);
        bool deteccion(Vector2f pos);
};