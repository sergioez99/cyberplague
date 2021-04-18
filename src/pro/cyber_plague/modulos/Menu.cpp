#include "Menu.h"

Menu* Menu::pinstance = 0;
Menu* Menu::Instance(CyberPlague* context, M_Window *w){
    
    //Instancia de menu le pasamos el contexto del juego (donde estamos ahora mismo) y la ventana para render
    pinstance = new Menu(context,w);

    return pinstance;
}

Menu::Menu(CyberPlague* context,M_Window *w){ 
//Clase constructor (aquí poner como se pintan los menús)

}

void Menu::Handle(){
    _context->cambiarEstado(this); //Al hacer Handle, se activa este estado en el contexto.
}
void Menu::Update(){
    _context=_context;
}

void Menu::Init(){
    //Cada vez que cambiemos de contexto al menú se llamará a esta función (se puede cambiar)
}

void Menu::Render(){
    //Se tendrá que llamar en bucle para pintar los menús
}

//Habrá que hacer más funciones para el manejo de los menús