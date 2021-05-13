#include "Cofre.h"

#define kNomFich "spritesheet_otros.png"

/* SPRITE DEL COFRE CERRADO*/

#define kTexLeftC 0
#define kTexTopC 74
#define kTexWidthC 38
#define kTexHeightC 36

/* ---------------- */

/* SPRITE DEL COFRE ABIERTO */

#define kTexLeftA 40
#define kTexTopA 73
#define kTexWidthA 37
#define kTexHeightA 37

/* ---------------- */

/* SPRITE DEL RECUADRO DE LA MEJORA */

#define kTexLeftRM 0
#define kTexTopRM 33
#define kTexWidthRM 36
#define kTexHeightRM 36

/* ---------------- */


/* SPRITE MEJORA VIDA */

#define kTexLeftMV 102
#define kTexTopMV 36
#define kTexWidthMV 32
#define kTexHeightMV 32

/* ---------------- */

/* SPRITE MEJORA MUNICION */

#define kTexLeftMM 38
#define kTexTopMM 36
#define kTexWidthMM 32
#define kTexHeightMM 32

/* ---------------- */

/* SPRITE MEJORA ARMADURA */

#define kTexLeftMA 70
#define kTexTopMA 36
#define kTexWidthMA 32
#define kTexHeightMA 32

/* ---------------- */

/* CODIGO DE LAS MEJORAS */

Mejora::Mejora(int tipo, float posX, float posY){

    if(tipo == 0){

        sprite_mejora = new M_Sprite(kNomFich, kTexLeftMV, kTexTopMV, kTexWidthMV, kTexHeightMV, posX, posY);

        this->tipo = tipo;
    }

    else if(tipo == 1){

        sprite_mejora = new M_Sprite(kNomFich, kTexLeftMM, kTexTopMM, kTexWidthMM, kTexHeightMM, posX, posY);

        this->tipo = tipo;
    }

    else if(tipo == 2){

        sprite_mejora = new M_Sprite(kNomFich, kTexLeftMA, kTexTopMA, kTexWidthMA, kTexHeightMA, posX, posY);
    
        this->tipo = tipo;
    }

    else{  //SI NO SE RECONOCE EL TIPO SE CREA POR DEFECTO UNA MEJORA DE VIDA.

        sprite_mejora = new M_Sprite(kNomFich, kTexLeftMV, kTexTopMV, kTexWidthMV, kTexHeightMV, posX, posY);

        this->tipo = 0;
    }

    cogido = false;
    obtenible = false;
}

void Mejora::render(M_Window* vent){

    if(cogido == false){

        vent->render(sprite_mejora);
    }
}

Mejora::~Mejora(){

    delete sprite_mejora;
}

int Mejora::getTipo(){

    return tipo;
}

bool Mejora::getCogido(){

    return cogido;
}

void Mejora::setCogido(){

    cogido = true;
}

bool Mejora::getObtenible(){

    return obtenible;
}

void Mejora::setObtenible(){

    obtenible = true;
}

M_Sprite* Mejora::getSprite(){

    return sprite_mejora;
}


/* --------------------------------------------- */


/* CODIGO DE LOS COFRES */

Cofre::Cofre(float posX, float posY){

    sprite_abierto = new M_Sprite(kNomFich, kTexLeftA, kTexTopA, kTexWidthA, kTexHeightA, posX, posY);
    sprite_cerrado = new M_Sprite(kNomFich, kTexLeftC, kTexTopC, kTexWidthC, kTexHeightC, posX, posY);

    float posRecX = posX;
    float posRecY = posY - 40;

    rec_mejora = new M_Sprite(kNomFich, kTexLeftRM, kTexTopRM, kTexWidthRM, kTexHeightRM, posRecX, posRecY);


    Mejora* mejora_Vida = new Mejora(0, posRecX, posRecY);
    Mejora* mejora_Muni = new Mejora(1, posRecX, posRecY); 
    Mejora* mejora_Armad = new Mejora(2, posRecX, posRecY);

    abierto = false;
    mejoraActual = 0;

    mejoras.push_back(mejora_Vida);
    mejoras.push_back(mejora_Armad);
    mejoras.push_back(mejora_Muni);

}

Cofre::~Cofre(){

    for(unsigned int i = 0; i < mejoras.size(); i++){

        delete mejoras.at(i);
    }

    delete sprite_abierto;
    delete sprite_cerrado;
    delete rec_mejora;
}


void Cofre::update(){

    int time = relojCambioMejora.getElapsedTime().asSeconds();

    if(time >= 2){

        if(!isOpen()){

            if(mejoraActual == 2){

                mejoraActual = 0;
            }
        
            else{

                mejoraActual++;
            }

            relojCambioMejora.restart();
            relojTiempoAbierto.restart();
        }
    }

    if(isOpen()){

        float temp = (float) relojTiempoAbierto.getElapsedTime().asMilliseconds() / 1000;

        if(temp > 1.0){

            mejoras.at(mejoraActual)->setObtenible();
        }

        mejoras.at(mejoraActual)->getSprite()->setPosition(sprite_cerrado->getPosX(), sprite_cerrado->getPosY());
    }


}

void Cofre::render(M_Window* vent){

    if(!isOpen()){

        vent->render(sprite_cerrado);
        vent->render(rec_mejora);
        vent->render(mejoras.at(mejoraActual)->getSprite());

        relojTiempoAbierto.restart();
    }

    else{

        float temp = (float) relojTiempoAbierto.getElapsedTime().asMilliseconds() / 1000;

        if(temp <= 1.0){

            vent->render(sprite_abierto);
        }

        else{

            vent->render(mejoras.at(mejoraActual)->getSprite());
        }
    }
    
    
}


void Cofre::abrir(){

    abierto = true;
}

bool Cofre::isOpen(){

    return abierto;
}

M_Sprite* Cofre::getSprite(){

    if(isOpen()){

        return sprite_abierto;
    }

    else{

        return sprite_cerrado;
    }
}

Mejora* Cofre::getMejora(){

    return mejoras.at(mejoraActual);
}

/* --------------------------------------------- */
