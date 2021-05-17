#include "CyberPlague.h"

CyberPlague* CyberPlague::pinstance = 0;
CyberPlague* CyberPlague::Instance(){
    
    if(pinstance == 0) pinstance = new CyberPlague();

    return pinstance;
}

void CyberPlague::update(){
  this->estado->Init(); //El init inicia los estados de las otras clases a las que vayamos a instanciar (o algo así)
}

void CyberPlague::cambiarEstado(State* estado){
  this->estado = estado;
  update();
}

void CyberPlague::Handle(){
   

    M_Input::Instanciar(window);

    Menu::Instance(this,window,0)->Handle();
}

Player* CyberPlague::getPlayer(){

  return player;
}

M_Window* CyberPlague::getWindow(){

  return window;
}

CyberPlague::CyberPlague(){
    //Clase por si queremos iniciarlizar variables o clases al iniciar el juego.
    estado = 0;

    //Cargo la imagen donde reside la textura del sprite protagonista
    sf::Texture playerTexture;
    playerTexture.loadFromFile("resources/Union 3e.png");

    window = new M_Window(640, 480,"Cyber Plague");
    player = new Player(&playerTexture, sf::Vector2u(8, 3), 0.15f, 250.0f, 0, 0);
}

CyberPlague::~CyberPlague(){


}