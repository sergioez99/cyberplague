#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/mimodulo.h"

#define kVel 5
//Metodo que comprueba si interseccionan dos boundingBoxes. No importa el orden de estos (a o b).
//Se pasa por referencia hit para que se cambie tambien en el main y asi no volver a dibujar el sprite correspondiente.
bool hitboxCollision(int& hit, sf::FloatRect a, sf::FloatRect b){
  if(a.intersects(b)){
    hit = 1;
    return true;
  }
  return false;
}
//Metodo que solo comprueba si dos BoundingBoxes se intersectan.
bool spriteCollides(sf::FloatRect a, sf::FloatRect b){
 if(a.intersects(b)) return true;
 return false;
}
int main() {

  MiModulo *mod = new MiModulo();
  int hit = 0;
  sf::Vector2f sPosition(0,0); //Guardar posicion inicial del sprite, para colisiones.
  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "Hitbox");

  //Cargo la imagen donde reside la textura del sprite
  sf::Texture tex;
  if (!tex.loadFromFile("resources/sprites.png")) {
    std::cerr << "Error cargando la imagen sprites.png";
    exit(0);
  }

  //Y creo el spritesheet a partir de la imagen anterior
  sf::Sprite sprite(tex);
  sf::Sprite bala(tex);
  sf::Sprite muro(tex);
  std::vector<sf::Sprite> * piedras = new std::vector<sf::Sprite>(); //Inicializar puntero vector de sprites.

  for(int i=0; i<3; i++){ //bucle para añadir i sprites al vector
    sf::Sprite v(tex);
    v.setOrigin(75/2, 75/2);
    v.setTextureRect(sf::IntRect(1 * 75, 3 * 75, 75, 75));
    v.setPosition(200, 100+60*i);
    piedras->push_back(v); 
  }

  //Le pongo el centroide donde corresponde
  sprite.setOrigin(75 / 2, 75 / 2);
  bala.setOrigin(75/2, 75/2);
  muro.setOrigin(75/2, 75/2);
  //Cojo el sprite que me interesa por defecto del sheet
  sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
  bala.setTextureRect(sf::IntRect(1 * 75, 0 * 75, 75, 75));
  muro.setTextureRect(sf::IntRect(1 * 75, 3 * 75, 75, 75));

  sprite.setPosition(75, 240);
  bala.setPosition(480, 300);
  muro.setPosition(200, 420);

  //Bucle del juego
  while (window.isOpen()) {
    //Bucle de obtención de eventos
    sPosition = sprite.getPosition();
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
          sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Escala por defecto
          sprite.setScale(1, 1);
          sprite.move(kVel, 0);
          break;

        case sf::Keyboard::Left:
          sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
          //Reflejo vertical
          sprite.setScale(-1, 1);
          sprite.move(-kVel, 0);
          break;

        case sf::Keyboard::Up:
          sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
          sprite.move(0, -kVel);
          break;

        case sf::Keyboard::Down:
          sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
          sprite.move(0, kVel);
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
    //Si intersecta con el muro, no lo puede atravesar, por lo que no se mueve a esa posición.
    if(spriteCollides(sprite.getGlobalBounds(), muro.getGlobalBounds())){ 
      sprite.setPosition(sPosition);
    }
    window.clear();
    window.draw(muro);
    for(int i=0; i<piedras->size();i++){//bucle que recorre todos los sprites del vector
      window.draw(piedras->at(i)); //Pinta todos los sprites del vector

      if(spriteCollides(sprite.getGlobalBounds(), piedras->at(i).getGlobalBounds()))
        sprite.setPosition(sPosition);
    }

    //(Optimización) Añade un int para no volver a calcular las boundingBoxes en cada Update si ya se tocaron
    if(hit==0 && !hitboxCollision(hit, sprite.getGlobalBounds(), bala.getGlobalBounds())) window.draw(bala);
    window.draw(sprite); //El jugador deberia de dibujarse siempre el ultimo para que no tenga "tembleque"
    window.display();
  }

  return 0;
}