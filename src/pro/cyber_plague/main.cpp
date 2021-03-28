#include <iostream>

#include "include/config.h"
#include "modulos/Motor2D/M_Sprite.h"
#include "modulos/Motor2D/M_Window.h"


#define kVel 5

using namespace std;


int main() {

  M_Window* vent = new M_Window(640,480,"Cyber Plague");

  M_Sprite* mi_spr = new M_Sprite("sprites.png", 0*75, 0*75, 75, 75, 640/2, 480/2);

  int cont = 0;

  mi_spr->rotar(70);
  mi_spr->escalar(0.5, 0.5);

  while(cont < 20000){

    cout << cont << endl;

    vent->render(mi_spr);
    vent->display();
    cont++;
  }
  
  vent->cerrar();

  delete vent;
  delete mi_spr;
/*
    //Bucle del juego
    while (ventana->abierta()) {
      
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
          case sf::Keyboard::Right:
            sprite->setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            //Escala por defecto
            sprite->setScale(1, 1);
            sprite->move(kVel, 0);
            break;

          case sf::Keyboard::Left:
            sprite->setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            //Reflejo vertical
            sprite->setScale(-1, 1);
            sprite->move(-kVel, 0);
            break;

          case sf::Keyboard::Up:
            sprite->setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
            sprite->move(0, -kVel);
            break;

          case sf::Keyboard::Down:
            sprite->setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
            sprite->move(0, kVel);
            break;

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
      window.draw(*sprite);
      window.display();
    }

    
*/
  return 0;
}