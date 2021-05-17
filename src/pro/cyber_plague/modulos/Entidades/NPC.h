#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include "Moneda.h"

using namespace std;

class NPC : public Entidad{
   
    private:

    protected:
        float* rango;
        Moneda* loot;

    public:
        NPC();
        virtual ~NPC() = 0;

       
        float getRango();
        Moneda* looteoMoneda();
        Moneda* getLoot();
        void colision(float deltaTime, NPC* enemigo);
        virtual void render(M_Window* vent, float percentTick);
        virtual void update(float deltaTime, Map *m, M_Sprite* player) = 0;
        virtual bool deteccion(M_Sprite* player) = 0;
        virtual bool colisionBala(M_Sprite* player) = 0;
};