#include <iostream>
#include "include/includes.h" //Añadir aqui los includes.

#define kUpdateTimePS 1000/15
#define kVel 200  //Temporal, mientras mago actue como jugador


using namespace std;


int main() {

  M_Window* vent = new M_Window(640,480,"Cyber Plague");
  M_View *camara = new M_View(0, 0, 640, 480);


  //Cargo la imagen donde reside la textura del sprite protagonista
  sf::Texture playerTexture;
  playerTexture.loadFromFile("resources/Union 3.png");
  Player player(&playerTexture, sf::Vector2u(8, 3), 0.15f, 200.0f);

  Clock clock;
  Clock clock2;

  //NPC* mago = new Mago("sprites.png", 0*75, 0*75, 75, 75, 640/4, 480/2);
  //NPC* paj = new Pajaro("sprites.png", 1*75, 0*75, 75, 75, 640/4, 480/4);
  //NPC* sold = new Soldado("sprites.png", 2.3*75, 0*75, 75, 75, 640/6, 480/6);
  NPC* zom = new Zombi("sprites.png", 3.3*75, 0*75, 75, 75, 1216, 352);
  //arc->mejorar();

  vector<NPC*> enemigos;
  //enemigos.push_back(mago);
  //enemigos.push_back(paj);
  //enemigos.push_back(sold);
  enemigos.push_back(zom);
//TODO: Poner al personaje para dejar de controlar al MAGO
  Map *tutorial = new Map(1);

  vector<bool> key;


  Time timeStartUpdate = clock.getElapsedTime();

  //Bucle juego
  while(vent->abierta()){
    if(clock.getElapsedTime().asMilliseconds() - timeStartUpdate.asMilliseconds() > kUpdateTimePS){
      float deltaTime = clock2.restart().asSeconds();

      key = vent->keyPressed();
      //TODO: Cambiar todo este codigo de movimiento y Colisiones a una nueva clase Physics

      //Salto suave.
      //TODO: Hacer salto suave bien.
      /*
      if(salto>0){
        if(salto>12)
          mago->getSprite()->mover(0, 3 *-kVel * deltaTime);
        else{
          mago->getSprite()->mover(0, (float)(salto/4)*-kVel * deltaTime);
        }
        salto--;
      }*/
      //Gravedad
      if(!player.muerto()){
        player.update(deltaTime, tutorial);
        //player.checkEnemyColision(enemigos);
        if(key[4]){

          player.ataque();

        }
        //player.setLastPosition();
      }
      //Updates antes de los renders o el personaje vibra por las colisiones.
      //Mago es personaje por ahora



      for(int i = 0; i < (int)enemigos.size(); i++){
          player.getArmaEquipada()->balaImpactada(enemigos.at(i));
          enemigos.at(i)->update(deltaTime, tutorial);
      }
        


      for(int i = 0; i < (int)enemigos.size(); i++){

        if(enemigos.at(i)->muerto()){
          
          enemigos.erase(enemigos.begin()+i);
        }
      }
    }

    //Mover camara
    if(player.getPosX() < 320.0f)
      camara->reset(0.f, 0.f, 640, 480);
    if(player.getPosX() >= 320.0f && player.getPosX() < tutorial->getWidth() * tutorial->getTileWidth() - 320.0f)
      camara->reset(player.getPosX() - 320.f, 0.f, 640, 480);
    if(player.getPosX() >= tutorial->getWidth() * tutorial->getTileWidth() - 320.0f)
      camara->reset((float)tutorial->getWidth() * tutorial->getTileWidth() - 640.0f, 0.f, 640, 480);

    float percentTick = min(1.f, (float)clock.getElapsedTime().asMilliseconds()/kUpdateTimePS);

    vent->limpiar();
    tutorial->drawTile(vent->getWindow());
    for(unsigned int i = 0; i < enemigos.size(); i++){

      enemigos.at(i)->render(vent, percentTick); //Renderiza todos los personajes por ahora
      
    }
    if(!player.muerto())

      player.renders(vent, percentTick, tutorial);

    vent->setView(camara);
    vent->display();
  }
  delete vent;
  delete camara;

  for(int i = 0; i < (int)enemigos.size(); i++)
    delete enemigos.at(i);

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