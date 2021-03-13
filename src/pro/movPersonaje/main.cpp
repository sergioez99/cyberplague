#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/Player.h"

int main() {

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA", sf::Style::Close | sf::Style::Resize);

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture playerTexture;

  playerTexture.loadFromFile("resources/UnionDEFDEF.png");

  /*
  if (!tex.loadFromFile("resources/spritesdef.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }*/
  
  //Y creo el spritesheet a partir de la imagen anterior
  //sf::Sprite sprite(tex);

  //Le pongo el centroide donde corresponde
  //sprite.setOrigin(17 / 2, 44 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  //sprite.setTextureRect(sf::IntRect(0 * 17, 0 * 44, 17, 44));

  // Lo dispongo en el centro de la pantalla
  // sprite.setPosition(320, 240);

  Player player(&playerTexture, sf::Vector2u(6, 2), 0.3f, 200.0f);

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