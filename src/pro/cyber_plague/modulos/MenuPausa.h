#include <iostream>
#include <sstream>
#include <Motor2D/M_Window.h>
#include <SFML/Graphics.hpp>
#include "Motor2D/M_Input.h"

#define MAX_NUMBER_OF_ITEMS_P 4
#define MAX_NUMBER_OF_ITEMS_T 10


class MenuPausa{
 
    private:
        M_Window* window; 
        M_Sprite* fondo;
        int selectedItemIndexP;
        int selectedItemIndexT;
        int width;
        int height;
        sf::Font font;
        sf::Text menuP[MAX_NUMBER_OF_ITEMS_P];
        sf::Text menuT[MAX_NUMBER_OF_ITEMS_T];
        bool pausado;
        int menustate=1;
        bool arco=false;
        bool laser=false;
        bool lanza=false;

        bool arco_mej = false;
        bool laser_mej = false;
        bool lanza_mej = false;

    public:

        MenuPausa(M_Window *w);
        ~MenuPausa();

        int update(int mon);
        bool render(View* view);

        void MoveUp();
        void MoveDown();

};