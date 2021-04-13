#pragma once
#include <iostream>
#include "../../Motor2D/M_Sprite.h"
#include "../../Motor2D/M_Window.h"

#include "../Player.h"

using namespace std;

/*
CLASE ABSTRACTA ARMA, NO SE PUEDE INSTANCIAR. TODAS LAS ARMAS DEL PJ, HEREDAN DE ESTA CLASE.
*/

class Arma {

    private:

        


    protected:
        
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

        };

        Player* jugador;

        vector<Bala*> proyectiles;
        int dmg;        
        int cad;        // Cadencia de Disparo del Arma en Segundos. (En el lanzallamas representa cada cuanto tiempo hace daño.)
        float vel;  // Velocidad del proyectil.

        bool mejora;

        Clock contDisparo;
        
        

    public:

        Arma();
        virtual ~Arma() = 0;

        virtual void disparo() = 0;
        virtual void mejorar() = 0;

        virtual void update(float deltaTime) = 0;
        void render(M_Window* vent);

        bool puedeDisparar();

        //GETTERS Y SETTERS
        vector<M_Sprite*> getProyectiles();
        int getDmg();
        int getCad();

        void setDmg(int d);
        void setCad(int c);

};


