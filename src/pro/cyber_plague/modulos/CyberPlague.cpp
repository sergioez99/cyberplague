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
    window = new sf::RenderWindow(sf::VideoMode(800,600),"CyberPlague");
    window->setFramerateLimit(60);

    //Menu::Instance(this,window,false)->Handle(); Aquí se llamaría por ejemplo al menú -> la primera cosa que se mostraría al iniciar el juego

    while(window->isOpen()){
        //Bucle de obtención de eventos
        while(window->pollEvent(event)){
            switch(event.type){   
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window->close();
                    break;
            }
        }
        update();
    }
}

CyberPlague::CyberPlague(){
    //Clase por si queremos iniciarlizar variables o clases al iniciar el juego.
}