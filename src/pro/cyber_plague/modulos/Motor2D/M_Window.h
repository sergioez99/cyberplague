#pragma once
#include <SFML/Graphics.hpp>
#include "M_Sprite.h"
#include "M_View.h"
#include "Map.h"
#include <iostream>

using namespace std;
using namespace sf;

class M_Window{
    
    private:

        //RenderWindow* ventana;
        Clock reloj;
        bool dir=false;
        //float deltaTime = 0;

    
    public:

        RenderWindow* ventana;
        //Constructor
        M_Window(int width, int heigth, string nom);

        //Destructor
        ~M_Window();

        //Metodo para renderizar un Sprite.
        void render(M_Sprite* spr);
        void renderPlayer(M_Sprite* spr, Map* mapa);

        std::vector<bool> keyPressed();

        void limpiar();

        //Metodo para devolver el deltaTime.
        //float getDt();
        
        //Metodo para comprobar si la ventana esta abierta.
        bool abierta();

        //Metodo para mostrar en la ventana todos los elementos renderizados.
        void display();

        //Metodo para cerrar la ventana.
        void cerrar();

        //Metodo para cambiar la vista a mostrar
        void setView(M_View *camara);

        //Metodo para escribir el menu
        void escribir(sf::Text text);

        RenderWindow* getWindow();
};