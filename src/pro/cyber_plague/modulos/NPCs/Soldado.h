#pragma once
#include <iostream>
#include <cmath>
#include "../NPC.h"

using namespace std;

class Soldado : public NPC{
    private:
        float velAtaque;

    public:
        Soldado(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Soldado();

        void mover(float deltaTime);
        bool hayCaida();
        bool deteccion(float x, float y);
        bool disparar(float deltaTime);
};