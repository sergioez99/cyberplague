#include <iostream>
#include <sstream>
#include <Motor2D/M_Window.h>
#include <SFML/Graphics.hpp>
#include "Motor2D/M_Input.h"

#define MAX_NUMBER_OF_ITEMS_P 4


class MenuPausa{
 
    private:
        M_Window* window; 
        M_Sprite* fondo;
        int selectedItemIndexP;
        int width;
        int height;
        sf::Font font;
        sf::Text menuP[MAX_NUMBER_OF_ITEMS_P];
        bool pausado;
    public:

        MenuPausa(M_Window *w);
        ~MenuPausa();

        void update();
        bool render(View* view);

        void MoveUp();
        void MoveDown();

};