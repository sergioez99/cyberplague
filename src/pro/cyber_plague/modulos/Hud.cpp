#include "Hud.h"


//    width = 640;
//    height = 480;
Hud::Hud(){}
Hud::~Hud(){
    delete money;
    delete life;
    delete armor;
    delete ammo;

    delete fuente;
}

void Hud::renderHUD(M_Window* vent, View* view){
    Vector2D posicion;

    posicion.x = view->getCenter().x;
    posicion.y = view->getCenter().y;

    money->setPosition(posicion.x-280.f,posicion.y+180.f);
    armor->setPosition(posicion.x-280.f, posicion.y-140.f);
    
    ammo->setPosition(posicion.x-250.f,posicion.y-180.f);
    life->setPosition(posicion.x-250.f,posicion.y-220.f);
    ammoType->setPosition(posicion.x-265.f, posicion.y-160.f);
    lifeIcon->setPosition(posicion.x-265.f, posicion.y-200.f);

    vent->escribir(armor);
	vent->escribir(money);
    vent->escribir(ammo);
    vent->escribir(life);
    vent->render(ammoType);
    vent->render(lifeIcon);
}

void Hud::setPosHUD(float x, float y){
    PosX = x;
    PosY = y;
}

void Hud::setPosHUDsf(){
    
    money->setPosition(PosX-280.f,PosY+180.f);
    armor->setPosition(PosX-280.f,PosY-180.f);

    ammo->setPosition(PosX-250.f,PosY-180.f);
    life->setPosition(PosX-250.f,PosY-220.f);
    lifeIcon->setPosition(PosX-265.f,PosY-200.f);
    ammoType->setPosition(PosX-265.f, PosY-160.f);
}