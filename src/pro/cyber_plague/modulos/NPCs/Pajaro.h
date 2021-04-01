#pragma once
#include <iostream>
#include <cmath>
#include <list>
#include "../NPC.h"

using namespace std;

class Pajaro : public NPC{
    private:

    public:
        Pajaro(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Pajaro();

        void update(float deltaTime);
        bool deteccion();
        void mover(float deltaTime);
};