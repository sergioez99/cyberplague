#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/config.h"
#include "ej_modulos/tinyxml2.h"
#include "ej_modulos/NPC.h"

#define kVel 150
#define kVelBala 800
#define fps 60
#define cad 1   //Cadencia: Cada "cad" frames, el pj dispara.
#define dmg 5


using namespace sf;
using namespace std;

int main() {

  //Creamos una ventana
  sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
  window.setFramerateLimit(fps);
  
  //Relojes
  Clock reloj1;
  Clock reloj2;

  /* PERSONAJE PRINCIPAL */
  NPC *pj = new NPC("CX-44", "sprites.png", Vector2f(37, 240));

    //Copiamos el sprite.
    Sprite* pj_sprite = pj->getSprite();

    //Le pongo el centroide donde corresponde
    pj_sprite->setOrigin(75 / 2, 75 / 2);

    //Cojo el sprite que me interesa por defecto del sheet
    pj_sprite->setTextureRect(sf::IntRect(0 * 84, 2 * 76, 84, 76));

  /* ---------------------------------------------------------------------- */

  /* NPC */
  NPC *en = new NPC("Enemigo", "sprites.png", Vector2f(600, 240));

    //Copiamos el sprite.
    Sprite* en_sprite = en->getSprite();

    //Le pongo el centroide donde corresponde
    en_sprite->setOrigin(75 / 2, 75 / 2);

    //Cojo el sprite que me interesa por defecto del sheet
    en_sprite->setTextureRect(sf::IntRect(5 * 84, 2 * 76, 84, 76));
  
  /* ------------------------------------------------------------------------ */

  /* PROYECTILES */
  RectangleShape lanzallamas(Vector2f(0,0));
  lanzallamas.setPosition(pj->getPosicion());
  lanzallamas.setFillColor(Color::Red);

  /* --------------------------- */


  Time timeStartUpdate = reloj1.getElapsedTime();
  int frameCount = 0; //Contador de Frames.
  bool disparo = false;

  //Bucle del juego
  while (window.isOpen()) {

    if(timeStartUpdate.asSeconds() > (float) 1/fps){

      float delta = reloj1.restart().asSeconds();
      
      /* EVENTOS */

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
              
              //Tecla Z para disparar.
              case sf::Keyboard::Right:

                pj_sprite->move(kVel * delta, 0);


                break;


              //Tecla Z para disparar.
              case sf::Keyboard::Z:

                if(frameCount > cad - 1){
                
                  disparo = true;

                  lanzallamas.setSize(Vector2f(150, 20));
                  lanzallamas.setPosition(pj->getPosicion());
                }

                break;

              //Tecla ESC para salir.
              case sf::Keyboard::Escape:

                window.close();
                break;

              //Cualquier tecla desconocida se imprime por pantalla su código
              default:
                std::cout << event.key.code << std::endl;
                break;
              }

          break;

          case sf::Event::KeyReleased:

            switch(event.key.code){

              case sf::Keyboard::Z:

                disparo = false;
                lanzallamas.setPosition(Vector2f(0,0));

              break;
            }
        }
      }

      /* ------------------------------------------------------- */

      /* UPDATE */

      if(lanzallamas.getGlobalBounds().intersects(en_sprite->getGlobalBounds()) && frameCount > 10 && !en->estoyMuerto()){

        if(dmg - en->getArmadura() <= 0){en->setVida(en->getVida() - 1);}
        else{

          en->setVida(en->getVida() - (dmg - en->getArmadura()));
          cout << en->getVida() << endl;
        }

        frameCount = 0;
      }

      frameCount ++;
      if(frameCount ==  INT_MAX){frameCount=0;}
      //cout << frameCount << endl;

      /* ------------------------------------------------------- */

      /* RENDER */

      window.clear();

      if(disparo == true){

        window.draw(lanzallamas);
      }

      if(en != NULL && !en->estoyMuerto()){
        
        window.draw(*en_sprite);
      }

      if(pj != NULL){window.draw(*pj_sprite);}

      
      
      window.display();

      /* -------------------------------------------------------- */

      reloj1.restart();
    }

    //cout << timeStartUpdate.asSeconds() << endl;
    timeStartUpdate = reloj1.getElapsedTime();
  }

  delete pj;
  delete en;

  return 0;
}