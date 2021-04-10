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
        
        /* METODOS HEREDADOS DE ENTIDAD. */
        void ataque();
        bool puedoAtacar();
        void moverse(float deltaTime);
        void update(float deltaTime, Map *m);
        /* ----------------------------- */

        /* METODOS HEREDADOS DE NPC */
        bool deteccion();
        /* ------------------------ */  
};