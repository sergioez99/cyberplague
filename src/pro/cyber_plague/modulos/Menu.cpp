#include "CyberPlague.h"
#include <stdio.h>

Menu* Menu::pinstance = 0;

Menu* Menu::Instance(CyberPlague* contexto, M_Window *w, int inic){
    pinstance = new Menu(contexto,w,inic);
    return pinstance;
}

Menu::Menu(CyberPlague* contexto, M_Window *w, int inic) {
  
    _contexto = contexto;
    window=w;

    width = 640;
    height = 480;

    if(!font.loadFromFile("./resources/FIGHTT3_.ttf")){
        font.loadFromFile("./resources/arial.ttf");
    }

   // if(inic != 0){
   //     menustate=5;
   // }

    nivel=inic;  //para guardar la nivel en el que se ha pausado

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Jugar");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Seleccionar nivel");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Controles");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Salir");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS +1) * 4));

///////////////////////////////////////  LOBBY
    menuL[0].setFont(font);
    menuL[0].setColor(sf::Color::Red);
    menuL[0].setString("Sector 1");  
    menuL[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 1));

    menuL[1].setFont(font);
    menuL[1].setColor(sf::Color::White);
    menuL[1].setString("Sector 2");
    menuL[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 2));

    menuL[2].setFont(font);
    menuL[2].setColor(sf::Color::White);
    menuL[2].setString("Sector 3");
    menuL[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 3));



    menuL[3].setFont(font);
    menuL[3].setColor(sf::Color::White);
    menuL[3].setString("Volver");
    menuL[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_L +1) * 4));

    //////////////////////////  CONTROLES

    menuN[0].setFont(font);
    menuN[0].setColor(sf::Color::Red);
    menuN[0].setString("Volver"); 
    menuN[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_N +1) * 1));

    

    ////////////////////////////   TIENDA

    menuT[0].setFont(font);
    menuT[0].setColor(sf::Color::Red);
    menuT[0].setString("Armas");
    menuT[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_T +1) * 1));

    menuT[1].setFont(font);
    menuT[1].setColor(sf::Color::White);
    menuT[1].setString("Habilidades");
    menuT[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_T +1) * 2));

    menuT[2].setFont(font);
    menuT[2].setColor(sf::Color::White);
    menuT[2].setString("Volver");
    menuT[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_T +1) * 3));


    //////////////////////////// PAUSA

    menuP[0].setFont(font);
    menuP[0].setColor(sf::Color::Red);
    menuP[0].setString("Continuar");
    menuP[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 1));

    menuP[1].setFont(font);
    menuP[1].setColor(sf::Color::White);
    menuP[1].setString("Reiniciar");
    menuP[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 2));

    menuP[2].setFont(font);
    menuP[2].setColor(sf::Color::White);
    menuP[2].setString("Menu Principal");
    menuP[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 3));

    menuP[3].setFont(font);
    menuP[3].setColor(sf::Color::White);
    menuP[3].setString("Salir");
    menuP[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 4));

    selectedItemIndex = 0;
    selectedItemIndexL = 0;
    selectedItemIndexN = 0;
    selectedItemIndexT = 0;
    selectedItemIndexP = 0;
}

Menu::~Menu(){
    _contexto = 0;
    pinstance = 0;
}

void Menu::Handle(){
    _contexto->cambiarEstado(this); //Al hacer Handle, se activa este estado en el contexto.
}


void Menu::Update(){
    _contexto=_contexto;
}

void Menu::Init(){
    run(CyberPlague::Instance()->window);
}

int Menu::run(M_Window *window){

   string key;
   fondo = new M_Sprite("Fondo.jpg",0, 0, 640, 480,320, 240);
   fondoC = new M_Sprite("FondoControl.jpg",0, 0, 640, 480,320, 240);

    while(window->abierta()){

        key = M_Input::InputController();

        Eventos(key); //utilizamos la funcion para coger las teclas
        
        
        Render(); //dibujamos en pantalla el menu
    }

    delete fondo;
    delete fondoC;
    return 0;
}

int Menu::Eventos(string key){

            switch(menustate){ //para cada pantalla o estado del menu
                case 1:     //MENU PRINCIPAL
                    if(key == "UP"){
                                    
                        MoveUp();
                        
                                
                    }else if (key == "DOWN")
                                    
                        MoveDown();
                     
                    else if(key == "ENTER"){
                        switch(selectedItemIndex){
                            case 0: // Nueva Partida
                                //menustate = 5;
                                
                                nivel = 1;
                                
                                Mundo::Instance(CyberPlague::Instance(), window, nivel)->Handle();
                            break;
                            case 1:
                                 //lobby
                                menustate = 2;
                            break;
                            case 2:
                                //lobby
                                menustate = 3;
                            break;
                            case 3:
                                window->cerrar();
                                exit(0);
                            break;
                            
                        }    

 
                    }else if(key == "ESCAPE"){
                        window->cerrar();
                        exit(0);
                    }
                break;
                case 2:     //LOBBY
                    if(key == "UP")
                                    
                        MoveUp();
                        
                                
                    else if (key == "DOWN")
                                    
                        MoveDown();
                     
                    else if(key == "ENTER"){
                        switch(selectedItemIndexL){
                            case 0: 
                                //SECTOR O NIVEL 1
                                nivel = 1;
                                
                                Mundo::Instance(CyberPlague::Instance(), window, nivel)->Handle();
                            break;
                            case 1:
                                //SECTOR O NIVEL 2
                                nivel = 2;
                                
                                Mundo::Instance(CyberPlague::Instance(), window, nivel)->Handle();
                            break;
                            case 2:
                                //SECTOR O NIVEL 3
                                //SECTOR O NIVEL 1
                                nivel = 3;
                                
                                Mundo::Instance(CyberPlague::Instance(), window, nivel)->Handle();
                            break;
                            case 3:
  
                                menustate = 1;
                            break;
                          
                            
                        }    

 
                    }else if(key == "ESCAPE"){
                        window->cerrar();
                    }
                break;
                case 3:     //CONTROLES
                    if(key == "UP")
                                    
                        MoveUp();
                        
                                
                    else if (key == "DOWN")
                                    
                        MoveDown();
                     
                    else if(key == "ENTER"){
                        switch(selectedItemIndexN){
                            
                            case 0:
                                menustate = 1;
                            break;
                            
                        }    

 
                    }else if(key == "ESCAPE"){
                        window->cerrar();
                    }
                break;
                 case 4:             //TIENDA  
                    if(key == "UP")
                                    
                        MoveUp();
                                
                    else if (key == "DOWN")
                                    
                        MoveDown();
                     
                    else if(key == "ENTER"){
                        switch(selectedItemIndexT){
                            case 0: 
                                //SECTOR O NIVEL 1
                                //menustate = 5;
                                // Menu::Instance(CyberPlague::Instance(),window)->Handle();
                            break;
                            case 1:
                                //SECTOR O NIVEL 2
                                //menustate = 5;
                                // Menu::Instance(CyberPlague::Instance(),window)->Handle();
                            break;
                            case 2:
                                //SECTOR O NIVEL 3
                                //menustate = 5;
                                // Menu::Instance(CyberPlague::Instance(),window)->Handle();
                                menustate = 2;
                            break;
                            case 3:
                                //MENU PRINCIPAL
                                menustate = 2;
                            break;
                            case 4:

                            break;
                            case 5:
                                menustate = 1;
                            break;
                        }    

 
                    }else if(key == "ESCAPE"){
                        window->cerrar();
                        exit(0);
                    }
                break;
                case 5:             //PAUSA  
                    if(key == "UP")
                                    
                        MoveUp();
                                
                    else if (key == "DOWN")
                                    
                        MoveDown();
                     
                    else if(key == "ENTER"){
                        switch(selectedItemIndexP){
                            case 0: 
                                
                                Mundo::Instance(CyberPlague::Instance(), window, nivel)->Handle();
                            break;
                            case 1:
                                Mundo::Instance(CyberPlague::Instance(), window, nivel)->Handle();
                            break;
                            case 2:
                                
                                menustate = 1;
                            break;
                            case 3:
                                window->cerrar();
                            break;
                            
                        }    

 
                    }else if(key == "ESCAPE"){
                        window->cerrar();
                        exit(0);
                    }
                break;
            }
  
    return 0;
}


CyberPlague* Menu::getContexto(){
    return _contexto;
}

void Menu::Render(){

    window->limpiar();
    
  //  sf::Texture tex;
  //  tex.loadFromFile("./resources/Fondo.jpg");
  //  sf::Sprite fondo1(tex);
  //  window->fondo(fondo1);

    if(menustate==3){
        window->render(fondoC);
    }else{
        window->render(fondo);
    }
    
    
    switch(menustate){
        case 1:
            for (int i=0;i<MAX_NUMBER_OF_ITEMS;i++){
                window->escribir(&menu[i]);
            }
            break;
        case 2: 
            for (int i=0;i<MAX_NUMBER_OF_ITEMS_L;i++){
                window->escribir(&menuL[i]);
            }
            break;   
        case 3: 
            for (int i=0;i<MAX_NUMBER_OF_ITEMS_N;i++){
                window->escribir(&menuN[i]);
            }
            break;  
        case 5: 
            for (int i=0;i<MAX_NUMBER_OF_ITEMS_P;i++){
                window->escribir(&menuP[i]);
            }
            break;          
    }
    
    window->display();
    
}

int Menu::GetPressedItem(){
    switch(menustate){
        case 1:
            return selectedItemIndex;
        break;
        case 2:
            return selectedItemIndexL;
        break;
        case 3: 
            return selectedItemIndexN;
        break;    
        case 4: 
            return selectedItemIndexT;
        break;   
        case 5: 
            return selectedItemIndexP;
        break;   
    }
    return selectedItemIndex;
}

void Menu::MoveUp(){
    switch(menustate){
        case 1:
            if(selectedItemIndex -1 >=0)
            {
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex--;
                menu[selectedItemIndex].setColor(sf::Color::Red);
            }
            break;
        case 2: 
            if(selectedItemIndexL -1 >=0)
            {
                menuL[selectedItemIndexL].setColor(sf::Color::White);
                selectedItemIndexL--;
                menuL[selectedItemIndexL].setColor(sf::Color::Red);
            }
            break;
        case 3: 
            if(selectedItemIndexN -1 >=0)
            {
                menuN[selectedItemIndexN].setColor(sf::Color::White);
                selectedItemIndexN--;
                menuN[selectedItemIndexN].setColor(sf::Color::Red);
            }
            break;  
        case 4: 
            if(selectedItemIndexT -1 >=0)
            {
                menuT[selectedItemIndexT].setColor(sf::Color::White);
                selectedItemIndexT--;
                menuT[selectedItemIndexT].setColor(sf::Color::Red);
            }
            break;           
        case 5: 
            if(selectedItemIndexP -1 >=0)
            {
                menuP[selectedItemIndexP].setColor(sf::Color::White);
                selectedItemIndexP--;
                menuP[selectedItemIndexP].setColor(sf::Color::Red);
            }
            break;          
    }
    
}

void Menu::MoveDown(){
    switch(menustate){
        case 1:
            if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
            {
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex++;
                menu[selectedItemIndex].setColor(sf::Color::Red);
            }
            break;
        case 2: 
            if(selectedItemIndexL + 1 < MAX_NUMBER_OF_ITEMS_L)
            {
                menuL[selectedItemIndexL].setColor(sf::Color::White);
                selectedItemIndexL++;
                menuL[selectedItemIndexL].setColor(sf::Color::Red);
            } 
            break;
        case 3: 
            if(selectedItemIndexN + 1 < MAX_NUMBER_OF_ITEMS_N)
            {
                menuN[selectedItemIndexN].setColor(sf::Color::White);
                selectedItemIndexN++;
                menuN[selectedItemIndexN].setColor(sf::Color::Red);
            } 
            break;    
        case 4: 
            if(selectedItemIndexT + 1 < MAX_NUMBER_OF_ITEMS_T)
            {
                menuT[selectedItemIndexT].setColor(sf::Color::White);
                selectedItemIndexT++;
                menuT[selectedItemIndexT].setColor(sf::Color::Red);
            } 
            break;
        case 5: 
            if(selectedItemIndexP + 1 < MAX_NUMBER_OF_ITEMS_P)
            {
                menuP[selectedItemIndexP].setColor(sf::Color::White);
                selectedItemIndexP++;
                menuP[selectedItemIndexP].setColor(sf::Color::Red);
            } 
            break;              
    }
    
};

