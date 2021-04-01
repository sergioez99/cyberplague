#include "NPC.h"

NPC::NPC(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY, float vel, float rang){
    sprite = new M_Sprite(nomFichero, texLeft, texTop, tex_width, tex_height, posX, posY);
    velMovimiento = vel;
    rango = rang;
}

NPC::~NPC(){
    delete sprite;
}

M_Sprite* NPC::getSprite(){
    return sprite;
}

float NPC::getVelMovimiento(){
    return velMovimiento;
}

float NPC::getRango(){
    return rango;
}

void NPC::render(M_Window *ventana){
    ventana->render(sprite);
}