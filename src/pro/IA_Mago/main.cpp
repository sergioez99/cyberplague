#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

#include "include/config.h"
#include "ej_modulos/Mago.h"

#define kVel 55
#define kUpdateTimePS 1000/15
#define magoSpawnTime 2

int main() {
  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "IA Mago");

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
  Mago *mago = new Mago(Vector2f(540, 240));
  vector<Sprite> enemigos;
  Clock spawnClock;
  Time time = spawnClock.getElapsedTime();

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

      //Mago
      if(mago->deteccion(personaje.getPosition())){
        //Spawn enemigos cada magoSpawnTime (2s)
        if(spawnClock.getElapsedTime().asSeconds() - time.asSeconds() > magoSpawnTime){
          Sprite enemigo1(tex), enemigo2(tex);

          enemigo1.setOrigin(75 / 2, 75 / 2);
          enemigo1.setTextureRect(sf::IntRect(2 * 85, 2 * 75, 75, 75));
          enemigo1.setPosition(mago->getSprite().getPosition().x - 90, mago->getSprite().getPosition().y - 80);
          enemigo1.setScale(-0.5, 0.5);

          enemigo2.setOrigin(75 / 2, 75 / 2);
          enemigo2.setTextureRect(sf::IntRect(2 * 85, 2 * 75, 75, 75));
          enemigo2.setPosition(mago->getSprite().getPosition().x - 90, mago->getSprite().getPosition().y - 30);
          enemigo2.setScale(-0.5, 0.5);

          enemigos.push_back(enemigo1);
          enemigos.push_back(enemigo2);

          time = spawnClock.getElapsedTime();
        }
      }
      
      //Movimiento enemigos spawneados (posteriormente seguiran Algoritmo A* pathfinding)
      for(int i = 0; i < (int)enemigos.size(); i++){
        enemigos[i].setPosition(enemigos[i].getPosition().x - (delta * 50.0f), enemigos[i].getPosition().y);
      }

      timeStartUpdate = clock.getElapsedTime();
    }

    window.clear();
    window.draw(personaje);
    window.draw(mago->getSprite());
    for(int i = 0; i < (int)enemigos.size(); i++)
      window.draw(enemigos[i]);
    window.display();
  }

  delete mago;

  return 0;
}