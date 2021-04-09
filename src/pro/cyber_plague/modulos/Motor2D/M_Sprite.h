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


        //Metodos Setters y Getters.

        float getPosX();

        float getPosY();

        void setPosition(Vector2D pos);
        //NO SE PUEDE USAR ESTO. SOLO DEBUG
        Sprite* getSprite();      
};