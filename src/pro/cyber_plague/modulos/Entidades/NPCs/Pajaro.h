#pragma once
#include <iostream>
#include <cmath>
#include <list>
#include "../NPC.h"
#include "../../AI_Agent.h"

using namespace std;

class Pajaro : public NPC{
    private:

    public:
        Pajaro(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Pajaro();

        /* METODOS HEREDADOS DE ENTIDAD. */
        virtual void ataque(){};
        virtual bool puedoAtacar(){return false;};
        void moverse(float deltaTime, Map *m);
        void update(float deltaTime, Map *m, M_Sprite* player);
        /* ----------------------------- */

        /* METODOS HEREDADOS DE NPC */
        bool deteccion(M_Sprite* player){return false;};
        /* ------------------------ */  
};