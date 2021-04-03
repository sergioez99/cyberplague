#pragma once
#include <iostream>

#include "Entidad.h"

using namespace std;

class NPC : public Entidad{
   
    private:

    protected:
        float* rango;

    public:
        NPC();
        virtual ~NPC() = 0;

       
        float getRango();
        virtual bool deteccion() = 0;
};