#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/Map.h"

#define kVel 5

int main() {

  //Creamos una ventana
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  //Bucle del juego
  while (window->isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;
    while (window->pollEvent(event)) {

      switch (event.type) {

      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window->close();
        break;

      //Se pulsó una tecla, imprimo su codigo
      case sf::Event::KeyPressed:

        //Verifico si se pulsa alguna tecla de movimiento
        switch (event.key.code) {


        //Tecla ESC para salir
        case sf::Keyboard::Escape:
          window->close();
          break;

        //Cualquier tecla desconocida se imprime por pantalla su código
        default:
          std::cout << event.key.code << std::endl;
          break;
        }
      }
    }

    Map *map = new Map(2);

    window->clear(sf::Color::Black);
    //window->draw(sprite);
    map-> drawTile (window);
    window->display();
  }

  return 0;
}