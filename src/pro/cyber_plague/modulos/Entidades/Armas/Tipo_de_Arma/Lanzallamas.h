#pragma once
#include <iostream>
#include "../Arma.h"

class Lanzallamas : public Arma{

    private:

        class Bala{

            private:

                M_Sprite* sprite_bala;

            public:

                int orientacion;
                posInterpolada pos;

                Bala(float posX, float posY, int ori);
                ~Bala();

                void moverse(float posX, float posY, int i, int orie);
                void rotar(float grad);
                M_Sprite* getSprite();
                bool heColisionado(NPC* enemigo);
                bool heColisionado(Cofre* cofre);

        };

        vector<Bala*> proyectiles;

    public:

        Lanzallamas(float posX, float posY, int orie);
       ~Lanzallamas();

      bool puedeDisparar();
      void disparo();
      void mejorar();
      void update(float deltaTime, Map* m);
      void render(M_Window* vent, float percentTick);
      void balaImpactada(NPC* enemigos);
      void balaImpactada(Cofre* cofre);

      void limpiarCargador();
};

