#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class M_View{
    private:
        View *camara;
    
    public:
        //Constructor
        M_View(int x, int y, int width, int height);
        //Destructor
        ~M_View();

        //Metodo para mover la vista
        void mover(float x, float y);
        //Metodo para resetear la camara a los valores pasados por parametro
        void reset(float x, float y, int width, int height);

        //DEBUG
        View* getView();
};