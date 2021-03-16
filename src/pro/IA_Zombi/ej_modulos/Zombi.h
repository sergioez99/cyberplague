#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

class Zombi{
    private:
        Texture textura;
        Sprite* sprite;
        int kVel;         //Velocidad de movimiento
        bool dirIzquierda;    //Se mueve hacia la izquierda
    public:
        Zombi(Vector2f pos);
        Zombi(const Zombi &);
        ~Zombi();

        Sprite getSprite();
        void mover(float delta, int matriz[16][12]);
        bool hayCaida(int matriz[16][12]);
};