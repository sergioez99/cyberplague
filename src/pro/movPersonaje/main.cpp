#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/Animacion.h"

int main() {

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA", sf::Style::Close | sf::Style::Resize);

  sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
  player.setPosition(320.0f, 240.0f);

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture playerTexture;

  playerTexture.loadFromFile("resources/spritesdef.png");

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

  player.setTexture(&playerTexture);

  Animacion animacion(&playerTexture, sf::Vector2u(1, 4), 0.5f);

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

      //Se pulsó una tecla, imprimo su codigo
      case sf::Event::KeyPressed:

        //Verifico si se pulsa alguna tecla de movimiento
        switch (event.key.code) {
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

    animacion.Update(0, deltaTime);
    player.setTextureRect(animacion.uvRect);

    window.clear(sf::Color(150, 150, 150));
    window.draw(player);
    window.display();
  }
  return 0;
}