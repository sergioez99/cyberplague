#pragma once
#include <iostream>
#include <cmath>
#include "../NPC.h"

using namespace std;

class Mago : public NPC{
    private:
        float spawnTime;
        //Reloj para controlar el tiempo de spawneo de enemigos
        Clock spawnClock;
        Time time;

    public:
        Mago(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Mago();

        void update(float deltaTime);
        bool deteccion();
        bool spawnEnemigo();
};