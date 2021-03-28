#include "M_Window.h"


void M_Window::cerrar(){

  ventana->close();
  cout << "Ventana Cerrada." << endl;
}


void M_Window::render(M_Sprite* spr){

  ventana->draw(*(spr->getSprite()));
}


bool M_Window::abierta(){

  return ventana->isOpen();
}


void M_Window::display(){

  ventana->display();
}




M_Window::M_Window(int width, int heigth, string nom) {

  ventana = new RenderWindow(VideoMode(width, heigth), nom);

}


M_Window::~M_Window(){

  delete ventana;
}