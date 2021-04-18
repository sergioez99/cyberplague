#include "Mundo.h"

Mundo* Mundo::pinstance = 0;
Mundo* Mundo::Instance(CyberPlague* context, M_Window *w, int nivel){
    
    //Instancia de mundo le pasamos el contexto del juego (donde estamos ahora mismo), la ventana para render y el nivel (para el mapa)
    pinstance = new Mundo(context,w, nivel);

    return pinstance;
}

Mundo::Mundo(CyberPlague* context,M_Window *w, int nivel){ 
//Clase constructor (aquí poner como se pintan los menús)

}

void Mundo::Handle(){
    _context->cambiarEstado(this); //Al hacer Handle, se activa este estado en el contexto.
}
void Mundo::Update(){
    _context=_context;
}

void Mundo::Init(){
    //Cada vez que cambiemos de contexto al mundo se llamará a esta función (se puede cambiar)
}

void Mundo::Render(){
    //Se tendrá que llamar en bucle para pintar el mapa, y hacer updates y eso (creo)
}

//Habrá que hacer más funciones para el manejo del mundo