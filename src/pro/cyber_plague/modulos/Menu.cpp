#include "Menu.h"
#include "../include/includes.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <vector>
#include <string> 

Menu* Menu::pinstance = 0;

Menu* Menu::Instance(CyberPlague* contexto, sf::RenderWindow *w){
    pinstance = new Menu(contexto,w);
    return pinstance;
}

Menu::Menu(CyberPlague* contexto, sf::RenderWindow *w) {
  
    _contexto = contexto;
    window=w;

    width = 800;
    height = 600;
    
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Nueva partida");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 1));


    menu[1].setColor(sf::Color::White);
    menu[1].setString("Continuar");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 2));

  
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Como jugar");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 3));

  
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Opciones");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 4));


    menu[4].setColor(sf::Color::White);
    menu[4].setString("Creditos");
    menu[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 5));

    menu[5].setColor(sf::Color::White);
    menu[5].setString("Salir");
    menu[5].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 6));

///////////////////////////////////////  LOBBY
  
    menuL[0].setColor(sf::Color::Red);
    menuL[0].setString("Sector 1");  
    menuL[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 1));

   
    menuL[1].setColor(sf::Color::White);
    menuL[1].setString("Sector 2");
    menuL[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 2));

   
    menuL[2].setColor(sf::Color::White);
    menuL[2].setString("Sector 3");
    menuL[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 3));

    menuL[3].setColor(sf::Color::White);
    menuL[3].setString("Tienda");
    menuL[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 4));


    menuL[4].setColor(sf::Color::White);
    menuL[4].setString("Volver al menu principal");
    menuL[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 5));

    //////////////////////////  NIVELES

  
    menuN[0].setColor(sf::Color::Red);
    menuN[0].setString("Nivel 1"); 
    menuN[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_N +1) * 1));

 
    menuN[1].setColor(sf::Color::White);
    menuN[1].setString("Nivel 2");
    menuN[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_N +1) * 2));

   
    menuN[2].setColor(sf::Color::White);
    menuN[2].setString("Nivel 3");
    menuN[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_N +1) * 3));

 
    menuN[3].setColor(sf::Color::White);
    menuN[3].setString("Jefe final");
    menuN[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_N +1) * 4));


    menuN[4].setColor(sf::Color::White);
    menuN[4].setString("Volver al lobby");
    menuN[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_N +1) * 5));

    ////////////////////////////   TIENDA

 
    menuT[0].setColor(sf::Color::Red);
    menuT[0].setString("Armas");
    menuT[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_T +1) * 1));

    menuT[1].setColor(sf::Color::White);
    menuT[1].setString("Habilidades");
    menuT[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_T +1) * 2));

    menuT[2].setColor(sf::Color::White);
    menuT[2].setString("Volver");
    menuT[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_T +1) * 3));


    //////////////////////////// PAUSA


    menuP[0].setColor(sf::Color::Red);
    menuP[0].setString("Guardar partida");
    menuP[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 1));


    menuP[1].setColor(sf::Color::White);
    menuP[1].setString("Opciones");
    menuP[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 2));


    menuP[2].setColor(sf::Color::White);
    menuP[2].setString("Volver al menu de niveles");
    menuP[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 3));


    menuP[3].setColor(sf::Color::White);
    menuP[3].setString("Salir");
    menuP[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 4));

    selectedItemIndex = 0;
    selectedItemIndexL = 0;
    selectedItemIndexN = 0;
    selectedItemIndexT = 0;
    selectedItemIndexP = 0;
}

Menu::~Menu(){
    _contexto = 0;
    pinstance = 0;
}

void Menu::Handle(){
    _contexto->cambiarEstado(this); //Al hacer Handle, se activa este estado en el contexto.
}


void Menu::Update(){
    _contexto=_contexto;
}

void Menu::Init(){
    run(*CyberPlague::Instance()->window);
}

int Menu::run(sf::RenderWindow &window){
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){ 
            Eventos( event); //utilizamos la funcion para coger las teclas
        }
        
        Render(); //dibujamos en pantalla el menu
    }
    return 0;
}

int Menu::Eventos(sf::Event event){
            if (event.type == sf::Event::Closed){
                window->close();
            }
            switch(menustate){ //para cada pantalla o estado del menu
                case 1:
                    switch(event.type){
                        case sf::Event::KeyReleased:
                            
                            switch(event.key.code){
                                case sf::Keyboard::Up:
                                    
                                    MoveUp();
                                    break;
                                case sf::Keyboard::Down:
                                    
                                    MoveDown();
                                    break;
                                case sf::Keyboard::Return:
                                    if(selectedItemIndex==1){    // Llamamos al juego
                                       // Ingame::Instance(CyberPlague::Instance(),window, selected2)->Handle();
                                    }
                                    
                                    break;
                                
                        }
                        break;
                    break;
                    }
                    break;
                
            }
  
    return 0;
}


CyberPlague* Menu::getContexto(){
    return _contexto;
}

void Menu::Render(){
    window->clear();
    switch(menustate){
        case 1:
            for (int i=0;i<MAX_NUMBER_OF_ITEMS;i++){
                window->draw(menu[i]);
            }
            break;
        case 2: 
            for (int i=0;i<MAX_NUMBER_OF_ITEMS_L;i++){
                window->draw(menuL[i]);
            }
            break;   
        case 3: 
            for (int i=0;i<MAX_NUMBER_OF_ITEMS_N;i++){
                window->draw(menuN[i]);
            }
            break;  
        case 4: 
            for (int i=0;i<MAX_NUMBER_OF_ITEMS_T;i++){
                window->draw(menuT[i]);
            }
            break;   
        case 5: 
            for (int i=0;i<MAX_NUMBER_OF_ITEMS_P;i++){
                window->draw(menuP[i]);
            }
            break;          
    }

    window->display();
}

int Menu::GetPressedItem(){
    switch(menustate){
        case 1:
            return selectedItemIndex;
        break;
        case 2:
            return selectedItemIndexL;
        break;
        case 3: 
            return selectedItemIndexN;
        break;    
        case 4: 
            return selectedItemIndexT;
        break;   
        case 5: 
            return selectedItemIndexP;
        break;   
    }
    return selectedItemIndex;
}

void Menu::MoveUp(){
    switch(menustate){
        case 1:
            if(selectedItemIndex -1 >=0)
            {
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex--;
                menu[selectedItemIndex].setColor(sf::Color::Red);
            }
            break;
        case 2: 
            if(selectedItemIndexL -1 >=0)
            {
                menuL[selectedItemIndexL].setColor(sf::Color::White);
                selectedItemIndexL--;
                menuL[selectedItemIndexL].setColor(sf::Color::Red);
            }
            break;
        case 3: 
            if(selectedItemIndexN -1 >=0)
            {
                menuN[selectedItemIndexN].setColor(sf::Color::White);
                selectedItemIndexN--;
                menuN[selectedItemIndexN].setColor(sf::Color::Red);
            }
            break;  
        case 4: 
            if(selectedItemIndexT -1 >=0)
            {
                menuT[selectedItemIndexT].setColor(sf::Color::White);
                selectedItemIndexT--;
                menuT[selectedItemIndexT].setColor(sf::Color::Red);
            }
            break;           
        case 5: 
            if(selectedItemIndexP -1 >=0)
            {
                menuP[selectedItemIndexP].setColor(sf::Color::White);
                selectedItemIndexP--;
                menuP[selectedItemIndexP].setColor(sf::Color::Red);
            }
            break;          
    }
    
}

void Menu::MoveDown(){
    switch(menustate){
        case 1:
            if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
            {
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex++;
                menu[selectedItemIndex].setColor(sf::Color::Red);
            }
            break;
        case 2: 
            if(selectedItemIndexL + 1 < MAX_NUMBER_OF_ITEMS_L)
            {
                menuL[selectedItemIndexL].setColor(sf::Color::White);
                selectedItemIndexL++;
                menuL[selectedItemIndexL].setColor(sf::Color::Red);
            } 
            break;
        case 3: 
            if(selectedItemIndexN + 1 < MAX_NUMBER_OF_ITEMS_N)
            {
                menuN[selectedItemIndexN].setColor(sf::Color::White);
                selectedItemIndexN++;
                menuN[selectedItemIndexN].setColor(sf::Color::Red);
            } 
            break;    
        case 4: 
            if(selectedItemIndexT + 1 < MAX_NUMBER_OF_ITEMS_T)
            {
                menuT[selectedItemIndexT].setColor(sf::Color::White);
                selectedItemIndexT++;
                menuT[selectedItemIndexT].setColor(sf::Color::Red);
            } 
            break;
        case 5: 
            if(selectedItemIndexP + 1 < MAX_NUMBER_OF_ITEMS_P)
            {
                menuP[selectedItemIndexP].setColor(sf::Color::White);
                selectedItemIndexP++;
                menuP[selectedItemIndexP].setColor(sf::Color::Red);
            } 
            break;              
    }
    
}