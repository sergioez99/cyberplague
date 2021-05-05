#pragma once
#include <iostream>
#include "../../Motor2D/M_Sprite.h"
#include "../../Motor2D/M_Window.h"

#include "../NPC.h"

using namespace std;

/*
CLASE ABSTRACTA ARMA, NO SE PUEDE INSTANCIAR. TODAS LAS ARMAS DEL PJ, HEREDAN DE ESTA CLASE.
*/

class Arma {

    private:

    protected:

        /* DATOS JUGADOR */

        float pX;
        float pY;

        int ori;

        /* ------------- */

        int dmg;        
        float cad;        // Cadencia de Disparo del Arma en Segundos. (En el lanzallamas representa cada cuanto tiempo hace daño.)
        float vel;  // Velocidad del proyectil.
        int municionMax; //Municion Maxima del arma.
        int municionActual; //Municion que le queda al arma.

        bool mejora;

        Clock contDisparo;
        
        

    public:

        Arma();
        virtual ~Arma() = 0;

        virtual void disparo() = 0;
        virtual void mejorar() = 0;

        virtual void render(M_Window* vent, float percentTick) = 0;
        virtual void update(float deltaTime, Map* m) = 0;
        virtual void balaImpactada(NPC* enemigos) = 0;

        virtual bool puedeDisparar() = 0;
        virtual void limpiarCargador() = 0;

        //GETTERS Y SETTERS
        int getDmg();
        int getCad();
        int getMunicionMax();
        int getMunicionAct();

        void setDmg(int d);
        void setCad(int c);
        void setMunicionMax(int cant);
        void setMunicionAct(int cant);

        void setDatosJugador(float posX, float posY, int orie);

};


