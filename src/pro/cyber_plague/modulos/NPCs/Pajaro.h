#pragma once
#include <iostream>
#include <cmath>
#include "../NPC.h"

using namespace std;

class Pajaro : public NPC{
    private:

    public:
        Pajaro(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Pajaro();

        void mover(float deltaTime, float x, float y);
        bool deteccion(float x, float y);
};