#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <list>

#include "include/config.h"
#include "ej_modulos/Zombi.h"

#define kVel 55
#define kUpdateTimePS 1000/15

int main() {
  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "IA Enemigo");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Creamos los relojes
  sf::Clock clock;
  sf::Clock clock2;

  //PERSONAJE
  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite personaje(tex);

  //Le pongo el centroide donde corresponde
  personaje.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  personaje.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

  // Lo dispongo en el lado izquierdo de la pantalla
  personaje.setPosition(100, 240);

  //ENEMIGO
  Zombi *zombi = new Zombi(Vector2f(540, 240));

  //Creamos una matriz de colisiones de prueba (se obtiene de un tilemap)
  int matriz[16][12]; //Tiles de 40x40

  for(int i = 0; i < 16; i++){
    for(int j = 0; j < 12; j++){
      matriz[i][j] = 0;
    }
  }

  matriz[8][6] = 1;
  matriz[9][6] = 1;
  matriz[10][6] = 1;
  matriz[11][6] = 1;
  matriz[12][6] = 1;

  //Esto es solo para pintar las colisiones por pantalla
  std::vector<sf::RectangleShape> colisiones;

  for(int i = 0; i < 16; i++){
    for(int j = 0; j < 12; j++){
      if(matriz[i][j] == 1){
        sf::RectangleShape colision(sf::Vector2f(40, 40));
        colision.setPosition(sf::Vector2f(i * 40, j * 40));
        colisiones.push_back(colision);
      }
    }
  }

  sf::Time timeStartUpdate = clock.getElapsedTime();
  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    if(clock.getElapsedTime().asMilliseconds() - timeStartUpdate.asMilliseconds() > kUpdateTimePS){
      float delta = clock2.restart().asSeconds();
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
            personaje.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            //Escala por defecto
            personaje.setScale(1, 1);
            personaje.move(kVel * delta, 0);
            break;

          case sf::Keyboard::Left:
            personaje.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            //Reflejo vertical
            personaje.setScale(-1, 1);
            personaje.move(-(kVel * delta), 0);
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

      //Movimiento Zombi
      zombi->mover(delta, matriz);

      timeStartUpdate = clock.getElapsedTime();
    }

    window.clear();
    for(int i = 0; i < (int)colisiones.size(); i++)
      window.draw(colisiones[i]);
    window.draw(personaje);
    window.draw(zombi->getSprite());
    window.display();
  }

  return 0;
}