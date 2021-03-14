#include "NPC.h"
#include <iostream>

/*  DECLARACIÓN DE MÉTODOS.  */

    //CONSTRUCTOR.
    NPC::NPC(String nom, String tex, Vector2f pos){

        //CARGA DE TEXTURA.
        textura = new Texture();
        if (! textura->loadFromFile("resources/"+tex)) {
            std::cout << "Error cargando la textura";
            exit(0);
        }

        //APLICAR TEXTURA AL SPRITE.
        sprite = new Sprite(*textura);

        //POSICION DEL SPRITE.
        posicion = new Vector2f(pos);
        sprite->setPosition(*posicion);
        

        nombre = new String(nom);
        vida = new int(20);
        armadura = new int(1);
    }

    //DESTRUCTOR.
    NPC::~NPC(){

        delete nombre;
        delete vida;
        delete armadura;
        delete textura;
        delete sprite;
        delete posicion;
    }

    //GETTERS.
    Sprite* NPC::getSprite(){

        return sprite;
    }
    String NPC::getNombre(){

        return *nombre;
    }
    int NPC::getVida(){

        return *vida;
    }
    int NPC::getArmadura(){
        
        return *armadura;
    }

    Vector2f NPC::getPosicion(){

        return *posicion;
    }

    //SETTERS.
    void NPC::setNombre(String nom){

        if(nombre == NULL){nombre = new String(nom);}
        else{
            *nombre = nom;
        }

    }

    void NPC::setVida(int vid){

        if(vida == NULL){vida = new int(vid);}
        else{
            *vida = vid;
        }
    }

    void NPC::setArmadura(int arm){

        if(armadura == NULL){armadura = new int(arm);}
        else{
            *armadura = arm;
        }
    }

    void NPC::setPosicion(Vector2f pos){

        if(posicion == NULL){posicion = new Vector2f(pos);}
        else{
            *posicion = pos;
        }
    }

    void NPC::atacar(){}

    bool NPC::estoyMuerto(){

        if(*vida <= 0){
            return true;
        }

        else{
            return false;
        }
    }
