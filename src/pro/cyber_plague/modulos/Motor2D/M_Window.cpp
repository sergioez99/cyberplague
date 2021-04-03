#include "M_Window.h"

#define fps 60


/* CONSTRUCTOR Y DESTRUCTOR */

M_Window::M_Window(int width, int heigth, string nom) {

  ventana = new RenderWindow(VideoMode(width, heigth), nom);

  ventana->setFramerateLimit( fps );
}


M_Window::~M_Window(){

  delete ventana;
}

/* ---------------------------- */


/* METODOS */

void M_Window::limpiar(){
  ventana->clear();
}

void M_Window::keyPressed(M_Sprite* sprite){
  sf::Event event;
  while (ventana->pollEvent(event)) {

        switch (event.type) {

        //Si se recibe el evento de cerrar la ventana la cierro
        case sf::Event::Closed:
          ventana->close();
          break;

        //Se pulsó una tecla, imprimo su codigo
        case sf::Event::KeyPressed:

          //Verifico si se pulsa alguna tecla de movimiento
          switch (event.key.code) {

          //Mapeo del cursor
          case sf::Keyboard::Right:
            sprite->cambiarPosTextura(0 * 75, 2 * 75, 75, 75);
            //Escala por defecto
            if(dir==true){
              sprite->escalar(-1,1);
              dir=false;
            }
            sprite->mover(50 * deltaTime, 0);
            break;

          case sf::Keyboard::Left:
            sprite->cambiarPosTextura(0 * 75, 2 * 75, 75, 75);
            //Reflejo vertical
            if(dir==false){
              sprite->escalar(-1, 1);
              dir=true;
            }
            sprite->mover(-50 * deltaTime, 0);
            break;

          case sf::Keyboard::Up:
            sprite->cambiarPosTextura(0 * 75, 3 * 75, 75, 75);
            sprite->mover(0, -50 * deltaTime);
            break;

          case sf::Keyboard::Down:
            sprite->cambiarPosTextura(0 * 75, 0 * 75, 75, 75);
            sprite->mover(0, 50 * deltaTime);
            break;

          //Tecla ESC para salir
          case sf::Keyboard::Escape:
            ventana->close();
            break;

          //Cualquier tecla desconocida se imprime por pantalla su código
          default:
            std::cout << event.key.code << std::endl;
            break;
          }
        }
      }
}

void M_Window::cerrar(){

  ventana->close();
  cout << "Ventana Cerrada." << endl;
}

bool M_Window::abierta(){

  return ventana->isOpen();
}

void M_Window::render(M_Sprite* spr){

  ventana->draw(*(spr->getSprite()));

}

void M_Window::display(){

  Time dt = reloj.restart();

  deltaTime = dt.asSeconds();

  cout << deltaTime << endl;

  ventana->display();
}

float M_Window::getDt(){

  return deltaTime;
}


/* ------------------------------------------- */


