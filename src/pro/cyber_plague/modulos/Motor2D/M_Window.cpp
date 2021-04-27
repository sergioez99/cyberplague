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

//Antes el Input no controlaba 2 botones a la vez, así si. Código de array por ahora: Arriba, abajo, izquierda, derecha, disparo. 
std::vector<bool> M_Window::keyPressed(){
  std::vector<bool> keys(5,0); //Si no se pulsa alguna de las teclas, es false (0). Si se pulsan, es true(1).
  sf::Event event;

  //Este while es para pulsaciones de teclas, no para teclas mantenidas (Como el movimiento).
  //Es decir, los Event de SFML window solo sirven para pulsaciones rápidas. Hay que utilizar Keyboard:isKeyPressed para las teclas de movimiento, fuera
  //de este while.
  while (ventana->pollEvent(event)) {

     switch (event.type) {

      //Si se recibe el evento de cerrar la ventana la cierro
      case sf::Event::Closed:
        ventana->close();
        break;
              
      case sf::Keyboard::X:
        break;
              
      case sf::Keyboard::P:
        break;
              
      case sf::Keyboard::C:
         break;
         

      default:
        std::cout << event.key.code << std::endl;
      break;        
      }

      
  }
       if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        keys[0] = true;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        keys[1] = true;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        keys[2] = true;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        keys[3] = true;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        keys[4] = true;
      }

    //Pulsar ESC para salir. sf::Event no tiene el botón Escape
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        ventana->close();

    //Tienen que ser ifs sin elses, para ver si el usuario pulsa más de un botón a la vez.

  return keys;
}
  /*sf::Event event;
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
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                  return 10;
                return 1;
                break;

              case sf::Keyboard::Left:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                  return 20;
                return 2;
                break;

              case sf::Keyboard::Up:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                  return 30;
                return 3;
                break;

              case sf::Keyboard::Down:
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                  return 40;
                return 4;
                break;
              
              case sf::Keyboard::Z:
                return 5;
                break;
              
              case sf::Keyboard::X:
                return 6;
                break;
              
              case sf::Keyboard::P:
                return 7;
                break;
              
              case sf::Keyboard::C:
                return 8;
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

              break;


            //Detectar si se ha soltado alguna tecla.
            case sf::Event::KeyReleased:

              switch(event.key.code){

                case sf::Keyboard::Z:
                  return -5;
                  break;

                default:
                  break;
              }

              break;

            default:
              break;
        }

        


      }

  return 0;*/


void M_Window::cerrar(){

  ventana->close();
  cout << "Ventana Cerrada." << endl;
}

bool M_Window::abierta(){

  return ventana->isOpen();
}

void M_Window::renderPlayer(M_Sprite* spr, Map* mapa){

  mapa->drawPersonaje(getWindow(), spr->getSprite());

}

void M_Window::render(M_Sprite* spr){
  ventana->draw(*(spr->getSprite()));
}

void M_Window::escribir(sf::Text text){

  ventana->draw(text);

}

void M_Window::fondo(sf::Sprite fon){
  if(ventana)
    ventana->draw(fon);
}

int M_Window::MenuController(){

    sf::Event event;

    int mov=0;
    while (ventana->pollEvent(event)) {

        switch (event.key.code) {

            case sf::Keyboard::Up:
                mov=1;
            break;

            case sf::Keyboard::Down:
                mov=2;
            break;

            case sf::Keyboard::Return:
                mov=3;
            break;
            case sf::Keyboard::Escape:
                ventana->close();
            break;

            default:
              std::cout << event.key.code << std::endl;
            break;
            
        }
    } 
    return mov;     
}

void M_Window::display(){

  /*Time dt = reloj.restart();

  deltaTime = dt.asSeconds();

  cout << deltaTime << endl;*/

  ventana->display();
}

void M_Window::setView(M_View *camara){
  ventana->setView(*(camara->getView()));
}

/*float M_Window::getDt(){

  return deltaTime;
}*/

RenderWindow* M_Window::getWindow(){
  return ventana; //No se debería usar esto. Es para DEBUG
}

/* ------------------------------------------- */


