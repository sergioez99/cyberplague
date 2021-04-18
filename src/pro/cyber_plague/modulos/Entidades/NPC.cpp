#include "NPC.h"

/*
CLASE ABSTRACTA NPC, NO SE PUEDE INSTANCIAR. TODAS LOS ENEMIGOS DEL JUEGO, HEREDAN DE ESTA CLASE.

Cualquier método que pueda ser usado solo por los enemigos se tiene que crear aqui.
*/

NPC::NPC(){}

NPC::~NPC(){}

float NPC::getRango(){
    return *rango;
}

