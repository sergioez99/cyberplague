#pragma once
#include <iostream>
#include "../NPC.h"

using namespace std;

class Zombi : public NPC{
    private:

    public:
        Zombi(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Zombi();

        void update(float deltaTime);
        void mover(float deltaTime);
        bool hayCaida();
};