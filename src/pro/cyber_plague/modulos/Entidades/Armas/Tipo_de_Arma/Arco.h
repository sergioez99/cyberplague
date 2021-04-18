#pragma once
#include <iostream>
#include "../Arma.h"

class Arco : public Arma{

    private:

        class Bala{

            private:

                M_Sprite* sprite_bala;

            public:

                int orientacion;

                Bala(float posX, float posY, int ori);
                ~Bala();

                void moverse(float posX, float posY);
                void rotar(float grad);
                M_Sprite* getSprite();
                bool heColisionado(NPC* enemigo);

        };
        
        vector<Bala*> proyectiles;
 

    public:

        Arco(float posX, float posY, int orie);
       ~Arco();

      bool puedeDisparar();
      void disparo();
      void mejorar();
      void update(float deltaTime);
      void render(M_Window* vent);
      void balaImpactada(NPC* enemigos);

};

