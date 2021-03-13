#include "MenuTienda.h"

#include <iostream>

MenuTienda::MenuTienda(float width, float height) {
    if(!font.loadFromFile("arial.ttf")){

    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Armas");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Habilidades");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Volver");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 3));

    

    selectedItemIndex = 0;
}

MenuTienda::~MenuTienda(){

}

void MenuTienda::draw(sf::RenderWindow &window){
    for (int i=0;i<MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }
}

void MenuTienda::MoveUp(){
    if(selectedItemIndex -1 >=0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void MenuTienda::MoveDown(){
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}