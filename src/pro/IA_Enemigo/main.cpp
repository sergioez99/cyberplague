#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

#define kVel 55
#define kVelEnemigo 50
#define rangoEnemigo 200.0f
#define kUpdateTimePS 1000/15

int main() {

  MiModulo *mod = new MiModulo();

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
  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite enemigo(tex);

  //Le pongo el centroide donde corresponde
  enemigo.setOrigin(75 / 2, 75 / 2);
  //Cojo el sprite que me interesa por defecto del sheet
  enemigo.setTextureRect(sf::IntRect(5 * 85, 0 * 75, 75, 75));

  // Lo dispongo en el lado izquierdo de la pantalla
  enemigo.setPosition(540, 240);

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

          case sf::Keyboard::Up:
            personaje.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
            personaje.move(0, -(kVel * delta));
            break;

          case sf::Keyboard::Down:
            personaje.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
            personaje.move(0, kVel * delta);
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

      //Enemigo: Deteccion del personaje
      float distancia = sqrt(pow(abs(personaje.getPosition().x - enemigo.getPosition().x), 2) + pow(abs(personaje.getPosition().y - enemigo.getPosition().y), 2));
      
      if(distancia <= rangoEnemigo){
        enemigo.setTextureRect(sf::IntRect(2 * 85, 2 * 75, 75, 75));
        enemigo.setScale(-1,1);
        
        //El enemigo se mueve hasta el jugador
        if(enemigo.getPosition().x > personaje.getPosition().x + 50.0f)
          enemigo.move(-(kVelEnemigo * delta), 0);
      }
      else{
        enemigo.setScale(1,1);

        //El enemigo vuelve a su posicion inicial
        if(enemigo.getPosition().x < 540.0f)
          enemigo.move(kVelEnemigo * delta, 0);
        else
          enemigo.setTextureRect(sf::IntRect(5 * 85, 0 * 75, 75, 75));
      }

      timeStartUpdate = clock.getElapsedTime();
    }

    window.clear();
    window.draw(personaje);
    window.draw(enemigo);
    window.display();
  }

  return 0;
}