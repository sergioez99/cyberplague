#pragma once
#include <iostream>
#include <cmath>
#include "../NPC.h"

using namespace std;
using namespace sf;

class Soldado : public NPC{
    private:
        class Bala{
            private:
                M_Sprite* spr_bala;
            public:
                int dmg;
                float vel;
                posInterpolada pos;

                /* Ambos valores estaran entre 0 y 1 e indicaran el porcentaje de la velocidad que habra en cada eje */
                float vx;
                float vy;

                Bala(float posX, float posY, float vX, float vY, float ang);
                ~Bala();
                void update(float deltaTime);
                M_Sprite* getSprite(){return spr_bala;};
                posInterpolada getPosInterpolada(){return pos;};
        };

        vector<Bala*> balas;
        float cadencia;
        //Reloj para controlar el tiempo de spawneo de balas
        Clock spawnClock;
        //Animacion
        int currentImage;
        Clock animationClock;

    public:
        Soldado(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Soldado();
        
        /* METODOS HEREDADOS DE ENTIDAD. */
        void ataque();
        bool puedoAtacar();
        void moverse(float deltaTime);
        void update(float deltaTime, Map *m, M_Sprite* player);
        /* ----------------------------- */

        /* METODOS HEREDADOS DE NPC */
        bool deteccion(M_Sprite* player);
        void render(M_Window* vent, float percentTick);
        /* ------------------------ */  
};