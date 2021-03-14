#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

#include "include/config.h"
#include "ej_modulos/Soldado.h"

#define kVel 55
#define kUpdateTimePS 1000/15
#define balaSpawnTime 1

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
  Soldado *soldado = new Soldado(Vector2f(540, 280));
  vector<CircleShape> balas;
  Clock spawnClock;
  Time time = spawnClock.getElapsedTime();

  //Creamos una matriz de colisiones de prueba (se obtiene de un tilemap)
  int matriz[16][12]; //Tiles de 40x40

  for(int i = 0; i < 16; i++){
    for(int j = 0; j < 12; j++){
      matriz[i][j] = 0;
    }
  }

  matriz[8][7] = 1;
  matriz[9][7] = 1;
  matriz[10][7] = 1;
  matriz[11][7] = 1;
  matriz[12][7] = 1;

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

      //Soldado
      //Si detecta al jugador le dispara si no se mueve patrullando una plataforma
      if(soldado->deteccion(personaje.getPosition())){
        //Spawn bala cada balaSpawnTime (1s)
        if(spawnClock.getElapsedTime().asSeconds() - time.asSeconds() > balaSpawnTime){
          CircleShape bala;
          bala.setFillColor(Color::Yellow);
          bala.setRadius(5.f);
          bala.setPosition(soldado->getSprite().getPosition().x, soldado->getSprite().getPosition().y - 30);

          balas.push_back(bala);

          time = spawnClock.getElapsedTime();
        }
      }
      else
        soldado->mover(delta, matriz);

      //Movimiento balas
      for(int i = 0; i < (int)balas.size(); i++){
        balas[i].setPosition(balas[i].getPosition().x - (delta * 150.0f), balas[i].getPosition().y);
      }
        

      timeStartUpdate = clock.getElapsedTime();
    }

    window.clear();
    for(int i = 0; i < (int)colisiones.size(); i++)
      window.draw(colisiones[i]);
    for(int i = 0; i < (int)balas.size(); i++)
      window.draw(balas[i]);
    window.draw(personaje);
    window.draw(soldado->getSprite());
    window.display();
  }

  delete soldado;

  return 0;
}