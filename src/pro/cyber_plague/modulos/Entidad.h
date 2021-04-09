#pragma once
#include <iostream>
#include "Motor2D/M_Sprite.h"
#include "Motor2D/M_Window.h"


using namespace std;

/*
CLASE ABSTRACTA ENTIDAD, NO SE PUEDE INSTANCIAR. TODAS LAS ENTIDADES DEL JUEGO (EL PJ Y LOS NPCs), HEREDAN DE ESTA CLASE.

Cualquier método que pueda ser usado tanto por el pj principal como por los enemigos se tiene que crear aqui.
*/


class Entidad{

    //Los atributos se ponen como protegidos para que las clases hijas puedan acceder a ellas.
    protected:   
        M_Sprite* spr;
        int* vida;
        int* armadura;
        float* vel;
        Vector2D lastPosition;

    public:
        Entidad();
        virtual ~Entidad() = 0;

        /* Metodos Abstractos */
        virtual void ataque() = 0;
        virtual bool puedoAtacar() = 0;
        virtual void moverse(float deltaTime) = 0;
        virtual void update(float deltaTime) = 0;   
        /* ------------------------ */

        void escalar(float x, float y);
        
        bool muerto();
        void render(M_Window* vent);

    

        M_Sprite* getSprite();
        int getVida();
        int getArmadura();
        float getVelMovimiento();
        float getPosX();
        float getPosY();
        float getScaleX();
        float getScaleY();


        void setVida(int vi);
        void setArmadura(int arm);
        void setVelocidad(float velMov);

        Vector2D getLastPosition();
        void setLastPosition();
        void setPosition(Vector2D pos);



};


