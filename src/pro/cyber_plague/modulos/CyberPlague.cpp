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

    

    window = new M_Window(640, 480,"Cyber Plague");
    
}

CyberPlague::~CyberPlague(){


}