#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class NPC{
    
    private:

        //DECLARACION DE ATRIBUTOS.
        String* nombre;
        int* vida;
        int* armadura;

        Vector2f* posicion;
        Texture* textura;
        Sprite* sprite;

    public:
        NPC(String nom, String tex, Vector2f pos);
        ~NPC();

        Sprite* getSprite();
        String getNombre();
        int getVida();
        int getArmadura();
        Vector2f getPosicion();

        void setPosicion(Vector2f pos);
        void setNombre(String nom);
        void setVida(int vid);
        void setArmadura(int arm);

        void atacar();
        bool estoyMuerto();
};