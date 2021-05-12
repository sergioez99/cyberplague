#include "MenuPausa.h"

MenuPausa::MenuPausa(M_Window *w){
    window=w;

    width = 640;
    height = 480;

    if(!font.loadFromFile("./resources/FIGHTT3_.ttf")){
        font.loadFromFile("./resources/arial.ttf");
    }


    menuP[0].setFont(font);
    menuP[0].setColor(sf::Color::Red);
    menuP[0].setString("Continuar");
    menuP[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 1));

    menuP[1].setFont(font);
    menuP[1].setColor(sf::Color::White);
    menuP[1].setString("Reiniciar");
    menuP[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 2));

    menuP[2].setFont(font);
    menuP[2].setColor(sf::Color::White);
    menuP[2].setString("Menu Principal");
    menuP[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 3));

    menuP[3].setFont(font);
    menuP[3].setColor(sf::Color::White);
    menuP[3].setString("Salir");
    menuP[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 4));

    selectedItemIndexP = 0;

}

MenuPausa::~MenuPausa(){

}


void MenuPausa::update(){

}

void MenuPausa::render(){
    window->render(fondo);

    for (int i=0;i<MAX_NUMBER_OF_ITEMS_P;i++){
        window->escribir(&menuP[i]);
    }

    window->display();
}


void MenuPausa::MoveUp(){
   
    if(selectedItemIndexP -1 >=0)
    {
        menuP[selectedItemIndexP].setColor(sf::Color::White);
        selectedItemIndexP--;
        menuP[selectedItemIndexP].setColor(sf::Color::Red);
    }
         
}

void MenuPausa::MoveDown(){
   

    if(selectedItemIndexP + 1 < MAX_NUMBER_OF_ITEMS_P)
    {
        menuP[selectedItemIndexP].setColor(sf::Color::White);
        selectedItemIndexP++;
        menuP[selectedItemIndexP].setColor(sf::Color::Red);
    } 
           
};
