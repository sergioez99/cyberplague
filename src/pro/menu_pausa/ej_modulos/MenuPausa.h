#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4
class MenuPausa{
    
    public:
     MenuPausa(float width, float height);
     ~MenuPausa();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){
        return selectedItemIndex;
    }

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menupausa[MAX_NUMBER_OF_ITEMS];

};