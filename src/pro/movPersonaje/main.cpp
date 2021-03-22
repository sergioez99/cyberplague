#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/Player.h"

int main() {

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA", sf::Style::Close | sf::Style::Resize);

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture playerTexture;

  playerTexture.loadFromFile("resources/Union.png");

  Player player(&playerTexture, sf::Vector2u(8, 2), 0.3f, 200.0f);

  float deltaTime = 0.0f;
  sf::Clock clock;

  //Bucle del juego
  while (window.isOpen()) {

    deltaTime = clock.restart().asSeconds();

    //Bucle de obtención de eventos
    sf::Event event;
    while (window.pollEvent(event)) {

      switch (event.type) {

      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        window.close();
        break;
      }
    }

    player.Update(deltaTime);

    window.clear(sf::Color(150, 150, 150));
    player.Draw(window);
    window.display();
  }
  return 0;
}