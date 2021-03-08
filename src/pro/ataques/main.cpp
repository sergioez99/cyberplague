#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/tinyxml2.h"
#include "ej_modulos/NPC.h"

#define kVel 5

using namespace sf;
using namespace std;

int main() {


  NPC *mod = new NPC("CX-44", "sprites.png");

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
  
  /*
  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }
  */


  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite* npc_sprite = mod->getSprite();

  
  //Le pongo el centroide donde corresponde
  npc_sprite->setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  npc_sprite->setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

  // Lo dispongo en el centro de la pantalla
  npc_sprite->setPosition(320, 240);

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
          /*
          case sf::Keyboard::Right:
            npc_sprite->setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            //Escala por defecto
            npc_sprite->setScale(1, 1);
            npc_sprite->move(kVel, 0);
            break;
          */

          /*
          case sf::Keyboard::Left:
            npc_sprite->setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            //Reflejo vertical
            npc_sprite->setScale(-1, 1);
            npc_sprite->move(-kVel, 0);
            break;
          */

          /*
          case sf::Keyboard::Up:
            sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
            sprite.move(0, -kVel);
            break;
          */

          case sf::Keyboard::Z:
            mod->atacar();
            break;

          /*
          case sf::Keyboard::Down:
            npc_sprite->setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
            npc_sprite->move(0, kVel);
            break;
          */

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
    window.draw(*npc_sprite);
    window.display();
  }

  delete mod;

  return 0;
}