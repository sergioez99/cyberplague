#pragma once
#include <iostream>
#include "Motor2D/M_Sprite.h"

using namespace std;

class NPC{
    private:
        M_Sprite* sprite;
        float velMovimiento;
        float rango;

    public:
        NPC(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY, float vel, float rang);
        ~NPC();

        M_Sprite* getSprite();
        float getVelMovimiento();
        float getRango();
};