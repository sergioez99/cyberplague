#include "MenuPausa.h";

#include <iostream>

MenuPausa::MenuPausa(float width, float height) {
    if(!font.loadFromFile("arial.ttf")){

    }

    menupausa[0].setFont(font);
    menupausa[0].setColor(sf::Color::Red);
    menupausa[0].setString("Guardar partida");
    menupausa[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 1));

    menupausa[1].setFont(font);
    menupausa[1].setColor(sf::Color::White);
    menupausa[1].setString("Opciones");
    menupausa[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 2));

    menupausa[2].setFont(font);
    menupausa[2].setColor(sf::Color::White);
    menupausa[2].setString("Volver al menu de niveles");
    menupausa[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 3));

    menupausa[3].setFont(font);
    menupausa[3].setColor(sf::Color::White);
    menupausa[3].setString("Salir");
    menupausa[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 4));

    

    selectedItemIndex = 0;
}

MenuPausa::~MenuPausa(){

}

void MenuPausa::draw(sf::RenderWindow &window){
    for (int i=0;i<MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menupausa[i]);
    }
}

void MenuPausa::MoveUp(){
    if(selectedItemIndex -1 >=0)
    {
        menupausa[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menupausa[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void MenuPausa::MoveDown(){
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menupausa[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menupausa[selectedItemIndex].setColor(sf::Color::Red);
    }
}