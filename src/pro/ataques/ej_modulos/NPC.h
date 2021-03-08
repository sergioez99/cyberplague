#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class NPC{
    
    private:

        //DECLARACION DE ATRIBUTOS.
        String* nombre;
        int* vida;
        int* armadura;

        Texture* textura;
        Sprite* sprite;

    public:
        NPC(String nom, String tex);
        ~NPC();

        Sprite* getSprite();
        String getNombre();
        int getVida();
        int getArmadura();

        void setNombre(String nom);
        void setVida(int vid);
        void setArmadura(int arm);

        void atacar();

};