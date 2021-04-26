#include "CyberPlague.h"

Mundo* Mundo::pinstance = 0;
Mundo* Mundo::Instance(CyberPlague* context, M_Window *w, int nivel){
    pinstance = new Mundo(context,w, nivel);
    //lvl = nivel;
    return pinstance;
}

Mundo::Mundo(CyberPlague* context,M_Window *w, int nivel){ 
window = w;
_context = context;

//Aqui hacer un fondo animado a ver (el q hay esta con tiles pero se puede cambiar)

}

void Mundo::Handle(){
    _context->cambiarEstado(this); //Al hacer Handle, se activa este estado en el contexto.
}
void Mundo::Update(){
    _context=_context;
}

void Mundo::Init(){
    
}

void Mundo::Render(){
    //Se tendrá que llamar en bucle para pintar el mapa, y hacer updates y eso (creo)
}

//Habrá que hacer más funciones para el manejo del mundo