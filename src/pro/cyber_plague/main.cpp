#include <iostream>
#include "include/includes.h" //Añadir aqui los includes.

#define kUpdateTimePS 1000/15
#define kVel 200  //Temporal, mientras mago actue como jugador


using namespace std;


int main() {

  M_Window* vent = new M_Window(640,480,"Cyber Plague");

  Clock clock;
  Clock clock2;

  NPC* mago = new Mago("sprites.png", 0*75, 0*75, 75, 75, 640/2, 480/2);
  //NPC* paj = new Pajaro("sprites.png", 1*75, 0*75, 75, 75, 640/4, 480/4);
  //NPC* sold = new Soldado("sprites.png", 2.3*75, 0*75, 75, 75, 640/6, 480/6);
  NPC* zom = new Zombi("sprites.png", 3.3*75, 0*75, 75, 75, 380, 288);

  Arma* arc = new Arco();
  arc->mejorar();

  vector<NPC*> enemigos;
  enemigos.push_back(mago);
  //enemigos.push_back(paj);
  //enemigos.push_back(sold);
  enemigos.push_back(zom);
//TODO: Poner al personaje para dejar de controlar al MAGO
  Map *tutorial = new Map(1);

  vector<bool> key;
  bool dir = false;

  Time timeStartUpdate = clock.getElapsedTime();

  //Bucle juego
  while(vent->abierta()){
    if(clock.getElapsedTime().asMilliseconds() - timeStartUpdate.asMilliseconds() > kUpdateTimePS){
      float deltaTime = clock2.restart().asSeconds();
      cout << deltaTime << endl;

      key = vent->keyPressed();
      //TODO: Cambiar todo este codigo de movimiento y Colisiones a una nueva clase Physics
      if(key[0]){
              mago->getSprite()->cambiarPosTextura(0 * 75, 2 * 75, 75, 75);
              //Escala por defecto
              if(dir==true){
                mago->getSprite()->escalar(-1,1);
                dir=false;
              }
              mago->getSprite()->mover(kVel * deltaTime, 0);
      }if(key[1]){
              mago->getSprite()->cambiarPosTextura(0 * 75, 2 * 75, 75, 75);
              //Reflejo vertical
              if(dir==false){
                mago->getSprite()->escalar(-1, 1);
                dir=true;
              }
              mago->getSprite()->mover(-kVel * deltaTime, 0);
      }if(key[2]){
              mago->getSprite()->cambiarPosTextura(0 * 75, 3 * 75, 75, 75);
              mago->getSprite()->mover(0, -kVel * deltaTime);
      }if(key[3]){
              mago->getSprite()->cambiarPosTextura(0 * 75, 0 * 75, 75, 75);
              mago->getSprite()->mover(0, kVel * deltaTime);
      }if(key[4]){

          arc->disparo();
      }

      if(tutorial->checkCollision(mago->getSprite()->getSprite()))//si es verdadero, no debe de estar en esa posicion
        mago->getSprite()->setPosition(mago->getLastPosition());

      //Updates antes de los renders o el personaje vibra por las colisiones.
      //Mago es personaje por ahora
      for(int i = 0; i < (int)enemigos.size(); i++)
        enemigos.at(i)->update(deltaTime, tutorial);

      arc->update(deltaTime);
    }

    vent->limpiar();
    tutorial->drawTile(vent->getWindow());
    for(unsigned int i = 0; i < enemigos.size(); i++){

      enemigos.at(i)->render(vent); //Renderiza todos los personajes por ahora
    }

    arc->render(vent);

    vent->display();
  }
  delete vent;
  delete zom;
  //delete sold;
  delete mago;
  //delete paj;

  delete arc;
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