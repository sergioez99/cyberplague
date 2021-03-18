#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/Menu_niveles.h"

#define kVel 5

int main() {

  

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

  MenuN menu(window.getSize().x, window.getSize().y);


  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sf::Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {

      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window.close();
        break;

      //Se pulsó una tecla, imprimo su codigo
      case sf::Event::KeyPressed:

        //Verifico si se pulsa alguna tecla de movimiento
        switch (event.key.code) {

        //Mapeo del cursor
        

        case sf::Keyboard::Up:
          menu.MoveUp();
          break;

        case sf::Keyboard::Down:
          menu.MoveDown();
          break;

        case sf::Keyboard::Return:
          switch (menu.GetPressedItem())
          {
            case 0:
              std::cout << "Nivel 1 seleccionada" << std::endl;
              break;
            case 1:
              std::cout << "Nivel 2 seleccionado" << std::endl;
              break;
            case 2:
              std::cout << "NIvel 3 seleccionado" << std::endl;
              break;
            case 3:
              std::cout << "Boss seleccionado" << std::endl;
              break;
            case 4:
              std::cout << "Volver al menu lobby seleccionado" << std::endl;
              break;
        
          }

        //Tecla ESC para salir
        case sf::Keyboard::Escape:
          window.close();
          break;

        //Cualquier tecla desconocida se imprime por pantalla su código
        default:
          std::cout << event.key.code << std::endl;
          break;
        }
      }
    }

    window.clear();
    menu.draw(window);
    window.display();
  }

  return 0;
}