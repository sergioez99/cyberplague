#pragma once
#include <SFML/Graphics.hpp>
#include <../modulos/Tools/Vector2D.cpp>//Recordar que include es como un cd de terminal. ../ es subir una carpeta.

#include <iostream>

using namespace std;
using namespace sf;

class M_Sprite{
    
    private:
        Sprite* sprite;


    public:

        //Constructor
        M_Sprite(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);

        //Destructor
        ~M_Sprite();

        //Cambiar la posicion de la textura.
        void cambiarPosTextura(int posLeft, int posTop, int width, int height);

        //Rotar el Sprite.
        void rotar(float ang);

        //Mover el Sprite.
        void mover(float x, float y);

        //Escalar el Sprite.
        void escalar(float x, float y);

        //Detectar si el Sprite intersecta con otro Sprite.
        bool intersects(M_Sprite* spr);

        //Metodos Setters y Getters.

        float getPosX();

        float getPosY();

        Vector2D getScale();

        float getRotation();

        void setPosition(Vector2D pos);
        void setPosition(float posX, float posY);

        void setPosition(float x, float y);

        void setColor(int i);

        //Solo las clases de Motor2D deberían usar esto
        Sprite* getSprite();
};