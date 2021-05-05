#include "Moneda.h"

/* DATOS DE LA MONEDA */

#define kFich "spritesheet_otros.png"

/* -------------- */


Moneda::Moneda(int val, float posX, float posY){

    switch (val)

    {
    case 10:

        spr_moneda = new M_Sprite(kFich, 32, 11, 16, 16, posX, posY);

        valor = val;
        break;
    
    case 50:

        spr_moneda = new M_Sprite(kFich, 16, 11, 16, 16, posX, posY);

        valor = val;
        break;

    case 100:
    
        spr_moneda = new M_Sprite(kFich, 0, 11, 16, 16, posX, posY);

        valor = val;
        break;

    default:

        spr_moneda = new M_Sprite(kFich, 1, 11, 16, 16, posX, posY);

        valor = 10;
        break;
    }

    spr_moneda->escalar(1.5, 1.5);
    spr_moneda->mover(0, 10);
}

Moneda::~Moneda(){

    delete spr_moneda;
}

int Moneda::getValor(){

    return valor;
}

M_Sprite* Moneda::getSprite(){

    return spr_moneda;
}

void Moneda::render(M_Window* vent){

    vent->render(spr_moneda);
}