#include "M_Window.h"

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

int M_Window::keyPressed(){
  sf::Event event;
  while (ventana->pollEvent(event)) {

        switch (event.type) {

        //Si se recibe el evento de cerrar la ventana la cierro
        case sf::Event::Closed:
          ventana->close();
          break;

        //Se pulsó una tecla, imprimo su codigo
        case sf::Event::KeyPressed:

          //Verifico si se pulsa alguna tecla de movimiento
          switch (event.key.code) {

          //Mapeo del cursor
          case sf::Keyboard::Right:
            return 1;
            break;

          case sf::Keyboard::Left:
            return 2;
            break;

          case sf::Keyboard::Up:
            return 3;
            break;

          case sf::Keyboard::Down:
            return 4;
            break;

          //Tecla ESC para salir
          case sf::Keyboard::Escape:
            ventana->close();
            break;

          //Cualquier tecla desconocida se imprime por pantalla su código
          default:
            std::cout << event.key.code << std::endl;
            break;
          }
        }
      }

  return 0;
}

void M_Window::cerrar(){

  ventana->close();
  cout << "Ventana Cerrada." << endl;
}

bool M_Window::abierta(){

  return ventana->isOpen();
}

void M_Window::render(M_Sprite* spr){

  ventana->draw(*(spr->getSprite()));

}

void M_Window::display(){

  Time dt = reloj.restart();

  deltaTime = dt.asSeconds();

  cout << deltaTime << endl;

  ventana->display();
}

float M_Window::getDt(){

  return deltaTime;
}

RenderWindow* M_Window::getWindow(){
  return ventana; //No se debería usar esto. Es para DEBUG
}

/* ------------------------------------------- */


