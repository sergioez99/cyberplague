#include "Hud.h"


//    width = 640;
//    height = 480;
Hud::Hud(){}
Hud::~Hud(){}

void Hud::renderHUD(M_Window* vent, View* view){
    Vector2D posicion;
    posicion.x = view->getCenter().x;
    posicion.y = view->getCenter().y;
    money->setPosition(posicion.x-280.f,posicion.y+180.f);
    ammo->setPosition(posicion.x-280.f,posicion.y-180.f);
    life->setPosition(posicion.x-280.f,posicion.y-220.f);
	vent->escribir(money);
    vent->escribir(ammo);
    vent->escribir(life);
}

void Hud::setPosHUD(float x, float y){
    PosX = x;
    PosY = y;
}

void Hud::setPosHUDsf(){
    money->setPosition(PosX-280.f,PosY+180.f);
    ammo->setPosition(PosX-280.f,PosY-180.f);
    life->setPosition(PosX-280.f,PosY-220.f);
}