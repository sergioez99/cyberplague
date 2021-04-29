#include "M_Window.h"
#include <stdlib.h>

#define fps 60


/* CONSTRUCTOR Y DESTRUCTOR */

M_Window::M_Window(int width, int heigth, string nom) {

  ventana = new RenderWindow(VideoMode(width, heigth), nom);

  ventana->setFramerateLimit( fps );

}


M_Window::~M_Window(){

  delete ventana;
}

/* ---------------------------- */


/* METODOS */

void M_Window::limpiar(){
  ventana->clear();
}


void M_Window::cerrar(){

  ventana->close();
  cout << "Ventana Cerrada." << endl;
}

bool M_Window::abierta(){

  return ventana->isOpen();
}

void M_Window::renderPlayer(M_Sprite* spr, Map* mapa){

  mapa->drawPersonaje(getWindow(), spr->getSprite());

}

void M_Window::render(M_Sprite* spr){
  ventana->draw(*(spr->getSprite()));
}

void M_Window::escribir(sf::Text* text){

  ventana->draw(*text);

}

/*
void M_Window::fondo(sf::Sprite* fon){
  if(ventana)
    ventana->draw(*(fon));
}
*/

void M_Window::display(){

  ventana->display();
}

void M_Window::setView(M_View *camara){

  ventana->setView(*(camara->getView()));
}

bool M_Window::pollEvent(Event* event){

  return ventana->pollEvent(*event);
}

RenderWindow* M_Window::getWindow(){
  return ventana; //No se debería usar esto. Es para DEBUG
}

/* ------------------------------------------- */


