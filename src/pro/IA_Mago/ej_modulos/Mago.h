#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

class Mago{
    private:
        Texture textura;
        Sprite* sprite;
        Int32 spawnTime;
        float rango;
    public:
        Mago(Vector2f pos);
        Mago(const Mago &);
        ~Mago();

        Sprite getSprite();
        bool deteccion(Vector2f pos);
};