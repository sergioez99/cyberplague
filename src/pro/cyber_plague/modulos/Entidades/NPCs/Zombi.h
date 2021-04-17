#pragma once
#include <iostream>
#include "../NPC.h"

using namespace std;



class Zombi : public NPC{
    private:
        int attackTime;
        //Reloj para controlar el tiempo de ataque
        Clock attackClock;
    public:
        Zombi(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Zombi();

         /* METODOS HEREDADOS DE ENTIDAD. */
        virtual void ataque(){};
        bool puedoAtacar();
        void moverse(float deltaTime);
        void update(float deltaTime, Map *m);
        /* ----------------------------- */

        /* METODOS HEREDADOS DE NPC */
        bool deteccion(){return false;};
        /* ------------------------ */
};