#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "CyberPlague.h"

#define MAX_NUMBER_OF_ITEMS 6
#define MAX_NUMBER_OF_ITEMS_L 5
#define MAX_NUMBER_OF_ITEMS_N 5
#define MAX_NUMBER_OF_ITEMS_T 3
#define MAX_NUMBER_OF_ITEMS_P 4



class Menu : public State{
    
    public:
        Menu(CyberPlague* contexto, sf::RenderWindow *w);
        ~Menu();

        void Render();
        int run(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        void Update();
        void Handle();
        void Init();
        CyberPlague* getContexto();
        int GetPressedItem();
        int Eventos(sf::Event event);
        static Menu* Instance(CyberPlague* contexto, sf::RenderWindow *w);

    private:

        int menustate;
        int selectedItemIndex;
        int selectedItemIndexL;
        int selectedItemIndexN;
        int selectedItemIndexT;
        int selectedItemIndexP;
        int width;
        int height;

        static Menu* pinstance;
        CyberPlague *_contexto;
      //  sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Text menuL[MAX_NUMBER_OF_ITEMS_L];
        sf::Text menuN[MAX_NUMBER_OF_ITEMS_N];
        sf::Text menuT[MAX_NUMBER_OF_ITEMS_T];
        sf::Text menuP[MAX_NUMBER_OF_ITEMS_P];
        sf::RenderWindow *window;
};