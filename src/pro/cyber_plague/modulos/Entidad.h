#pragma once
#include <iostream>
#include "Motor2D/M_Sprite.h"
#include "Motor2D/M_Window.h"
#include "Motor2D/M_Input.h"
#include "Map.h"
#include "Tools/posInterpolada.h"


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
        int* vidaMax;
        int* armadura;
        float salto=0;
        int dmgColor=0;
        float* vel;
        int ataq;
        Vector2D lastPosition;
        bool grounded;
        posInterpolada pos;

        Clock invencibilidad;     //Reloj para controlar el tiempo que debe pasar para que la entidad reciba daño.

    public:
        Entidad();
        virtual ~Entidad() = 0;

        /* Metodos Abstractos */
        virtual void ataque() = 0;
        virtual bool puedoAtacar() = 0;
        virtual void moverse(float deltaTime) = 0;
        //virtual void update(float deltaTime, Map *m) = 0;
        /* ------------------------ */

        void escalar(float x, float y);
        
        bool muerto();
        void reciboDmg(int dmg);
        

    

        M_Sprite* getSprite();
        int getVida();
        int getVidaMax();
        int getArmadura();
        float getVelMovimiento();
        float getPosX();
        float getPosY();
        float getScaleX();
        float getScaleY();
        posInterpolada getPosInterpolada()  { return pos;   }
        int getAtaque()                     { return ataq;  }


        void setVida(int vi);
        void setArmadura(int arm);
        void setVelocidad(float velMov);

        Vector2D getLastPosition();
        void setLastPosition();
        void setPosition(Vector2D pos);

        bool isGrounded();
        void setGrounded(bool ground);
        bool isJumping();



};


