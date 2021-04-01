#pragma once
#include <iostream>
#include <cmath>
#include "../NPC.h"

using namespace std;
using namespace sf;

class Soldado : public NPC{
    private:
        float cadencia;
        //Reloj para controlar el tiempo de spawneo de balas
        Clock spawnClock;
        Time time;

    public:
        Soldado(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Soldado();

        void update(float deltaTime);
        bool deteccion();
        bool disparar();
        void mover(float deltaTime);
        bool hayCaida();
};