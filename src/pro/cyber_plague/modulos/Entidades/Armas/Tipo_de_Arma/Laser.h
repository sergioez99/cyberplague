#pragma once
#include <iostream>
#include "../Arma.h"

class Laser : public Arma{

    private:

        class Bala{

            private:

                M_Sprite* sprite_bala;

            public:

                int orientacion;
                posInterpolada pos;

                Bala(float posX, float posY, int ori);
                ~Bala();

                void moverse(float posX, float posY);
                void rotar(float grad);
                M_Sprite* getSprite();
                bool heColisionado(NPC* enemigo);

        };

        vector<Bala*> proyectiles;

    public:

        Laser(float posX, float posY, int orie);
       ~Laser();

      bool puedeDisparar();
      void disparo();
      void mejorar();
      void update(float deltaTime, Map* m);
      void render(M_Window* vent, float percentTick);
      void balaImpactada(NPC* enemigos);
      bool balaEstaLejos(int i, Map* m);

      void limpiarCargador();
};

