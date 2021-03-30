#include <iostream>

#include "include/config.h"
#include "modulos/Motor2D/M_Sprite.h"
#include "modulos/Motor2D/M_Window.h"
#include "modulos/CyberPlague.h"


#define kVel 5

using namespace std;


int main() {

  M_Window* vent = new M_Window(640,480,"Cyber Plague");

  M_Sprite* mi_spr = new M_Sprite("sprites.png", 0*75, 0*75, 75, 75, 640/2, 480/2);

  //int cont = 0;

  //Bucle juego
  while(vent->abierta()){
    vent->keyPressed(mi_spr);
    vent->limpiar();
    vent->render(mi_spr);
    vent->display();
  }
/*
  while(cont < 20000){

    cout << cont << endl;


    cont++;
  }
  
  vent->cerrar();
*/
  delete vent;
  delete mi_spr;
/*
    //Bucle del juego
    while (ventana->abierta()) {
      
      //Bucle de obtención de eventos
      sf::Event event;
      

      window.clear();
      window.draw(*sprite);
      window.display();
    }

    
*/
  //CyberPlague::Instance()->Handle(); -> iniciar el juego desde los estados
  return 0;
}