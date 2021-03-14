#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

class Soldado{
    private:
        Texture textura;
        Sprite* sprite;
        int kVel;               //Velocidad de movimiento
        bool dirIzquierda;      //Se mueve hacia la izquierda
        float rango;
    public:
        Soldado(Vector2f pos);
        Soldado(const Soldado &);
        ~Soldado();

        Sprite getSprite();
        void mover(float delta, int matriz[16][12]);
        bool hayCaida(int matriz[16][12]);
        bool deteccion(Vector2f pos);
};