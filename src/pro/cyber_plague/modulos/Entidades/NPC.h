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
        void render(M_Window* vent, float percentTick);
        virtual bool deteccion() = 0;
};