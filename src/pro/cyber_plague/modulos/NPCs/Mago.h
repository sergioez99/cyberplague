#pragma once
#include <iostream>
#include <cmath>
#include "../NPC.h"

using namespace std;

class Mago : public NPC{
    private:
        float spawnTime;

    public:
        Mago(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Mago();

        bool deteccion(float x, float y);
        bool generarEnemigo(float deltaTime);
};