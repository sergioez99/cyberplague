#include <iostream>

#include <SFML/Graphics.hpp>
#include "include/config.h"

#include "modulos/Motor2D/M_Sprite.h"
#include "modulos/Motor2D/M_Window.h"

#include "modulos/CyberPlague.h"
#include "modulos/Map.h"


#include "modulos/NPCs/Mago.h"
#include "modulos/NPCs/Pajaro.h"
#include "modulos/NPCs/Soldado.h"
#include "modulos/NPCs/Zombi.h"
#include "modulos/Map.h"
#include "modulos/Player.h"


using namespace std;


int main() {

  M_Window* vent = new M_Window(640,480,"Cyber Plague");


  Mago* mago = new Mago("sprites.png", 0*75, 0*75, 75, 75, 640/2, 480/2);
  Pajaro* paj = new Pajaro("sprites.png", 1*75, 0*75, 75, 75, 640/4, 480/4);
  Soldado* sold = new Soldado("sprites.png", 2.3*75, 0*75, 75, 75, 640/6, 480/6);
  Zombi* zom = new Zombi("sprites.png", 3.3*75, 0*75, 75, 75, 640/8, 480/8);

  vector<NPC*> enemigos;
  enemigos.push_back(mago);
  enemigos.push_back(paj);
  enemigos.push_back(sold);
  enemigos.push_back(zom);
//TODO: Poner al personaje para dejar de controlar al MAGO
  Map *tutorial = new Map(1);

  int key = 0;
  bool dir = false;

  //Bucle juego
  while(vent->abierta()){
    key = vent->keyPressed();
    if(key == 1){
            mago->getSprite()->cambiarPosTextura(0 * 75, 2 * 75, 75, 75);
            //Escala por defecto
            if(dir==true){
              mago->getSprite()->escalar(-1,1);
              dir=false;
            }
            mago->getSprite()->mover(50 * vent->getDt() * 2, 0);
    }else if(key == 2){
            mago->getSprite()->cambiarPosTextura(0 * 75, 2 * 75, 75, 75);
            //Reflejo vertical
            if(dir==false){
              mago->getSprite()->escalar(-1, 1);
              dir=true;
            }
            mago->getSprite()->mover(-50 * vent->getDt() * 2, 0);
    }else if(key == 3){
            mago->getSprite()->cambiarPosTextura(0 * 75, 3 * 75, 75, 75);
            mago->getSprite()->mover(0, -50 * vent->getDt() * 2);
    }else if(key == 4){
            mago->getSprite()->cambiarPosTextura(0 * 75, 0 * 75, 75, 75);
            mago->getSprite()->mover(0, 50 * vent->getDt() * 2);
    }

    vent->limpiar();

    if(tutorial->checkCollision(mago->getSprite()->getSprite()))//si es verdadero, no debe de estar en esa posicion
      mago->getSprite()->setPosition(mago->getLastPosition());
    //Updates antes de los renders o el personaje vibra por las colisiones.
    mago->update(vent->getDt()); //Mago es personaje por ahora
    paj->update(vent->getDt());
    zom->update(vent->getDt());
    sold->update(vent->getDt());

    tutorial->drawTile(vent->getWindow());
    for(unsigned int i = 0; i < enemigos.size(); i++){

      enemigos.at(i)->render(vent); //Renderiza todos los personajes por ahora
    }


    vent->display();
  }
  delete vent;
  delete zom;
  delete sold;
  delete mago;
  delete paj;
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