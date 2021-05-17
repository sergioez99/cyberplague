#include "CyberPlague.h"


#define kDistX 80     //Para ajustar del eje -X la posicion de los elementos del menu. A 0, se colocan en el centro de la vista. 

MenuPausa::MenuPausa(M_Window *w){
    window=w;

    width = 680;
    height = 480;

    if(!font.loadFromFile("./resources/FIGHTT3_.ttf")){
        font.loadFromFile("./resources/arial.ttf");
    }


    menuP[0].setFont(font);
    menuP[0].setColor(sf::Color::Red);
    menuP[0].setString("Continuar");
 //   menuP[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 1));

    menuP[1].setFont(font);
    menuP[1].setColor(sf::Color::White);
    menuP[1].setString("Tienda");
 //   menuP[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 2));

    menuP[2].setFont(font);
    menuP[2].setColor(sf::Color::White);
    menuP[2].setString("Menu Principal");
 //   menuP[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 3));

    menuP[3].setFont(font);
    menuP[3].setColor(sf::Color::White);
    menuP[3].setString("Salir");
 //   menuP[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_P +1) * 4));


    ////////////////////////////   TIENDA

    menuT[0].setFont(font);
    menuT[0].setColor(sf::Color::Red);
    

    menuT[1].setFont(font);
    menuT[1].setColor(sf::Color::White);
    

    menuT[2].setFont(font);
    menuT[2].setColor(sf::Color::White);
    
    menuT[3].setFont(font);
    menuT[3].setColor(sf::Color::White);

    menuT[4].setFont(font);
    menuT[4].setColor(sf::Color::White);

    menuT[5].setFont(font);
    menuT[5].setColor(sf::Color::White);

    menuT[6].setFont(font);
    menuT[6].setColor(sf::Color::White);
    menuT[6].setString("Recargar Todas las Armas - 20$");

    menuT[7].setFont(font);
    menuT[7].setColor(sf::Color::White);
    menuT[7].setString("Comprar Armadura - 50$");

    menuT[8].setFont(font);
    menuT[8].setColor(sf::Color::White);
    menuT[8].setString("Comprar Vida - 100$");

    menuT[9].setFont(font);
    menuT[9].setColor(sf::Color::White);
    menuT[9].setString("Volver");


    selectedItemIndexP = 0;
    selectedItemIndexT = 0;

}

MenuPausa::~MenuPausa(){

}


int MenuPausa::update(int mon){
    
    pausado=true;
    string key;
    key = M_Input::InputController();
    int compra=0;

     switch(menustate){
         case 1:
            if(key == "UP")
                                            
                MoveUp();
                                        
            else if (key == "DOWN")
                                            
                MoveDown();
                            
            else if(key == "ENTER"){
                switch(selectedItemIndexP){
                    case 0: 
                        pausado=false;               
                        //Mundo::Instance(CyberPlague::Instance(), window, nivel)->Handle();
                    break;
                    case 1:
                        //tienda
                        menustate = 2;
                    break;
                    case 2:
                       Menu::Instance(CyberPlague::Instance(), window, 0)->Handle();               
                        //aqui al menu
                        compra = -1;
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
        case 2:
            if(key == "UP")
                                            
                MoveUp();
                                        
            else if (key == "DOWN")
                                            
                MoveDown();
                            
            else if(key == "ENTER"){
                switch(selectedItemIndexT){
                    case 0: 
                        //comprar arco
                        if(mon>=50 && arco==false){
                            compra = 1;
                            arco=true;
                        }    
                    break;
                    case 1:
                        //comprar laser
                        if(mon>=100 && laser==false){
                            compra = 2;
                            laser=true;
                        }    
                    break;
                    case 2:
                        if(mon>=200 && lanza==false){
                            compra = 3;
                            lanza=true;
                        }    
                        //comprar lanzallamas
                    break;

                    case 3:

                        if(mon>=200 && arco == true){

                            compra = 4;
                            arco_mej = true;
                        }

                    break;

                    case 4:
                    
                        if(mon>=200 && laser == true){

                            compra = 5;
                            laser_mej = true;
                        }

                    break;

                    case 5:
                    
                        if(mon>=200 && lanza == true){

                            compra = 6;
                            lanza_mej = true;
                        }

                    break;

                    case 6:
                        if(mon>=20)
                            compra = 7;
                        //recargar municion
                    break;    

                    case 7:
                        //aumentar escudo
                        if(mon>=50)
                            compra = 8;
                    break; 

                    case 8:
                        //Aumentar VidaMax
                        if(mon>=100)
                            compra = 9;
                    break;

                    case 9:
                        //volver
                        menustate=1;
                    break;        
                }    
            }else if(key == "ESCAPE"){
                menustate = 1;
            }
        break;

     }       
     return compra; 
}

bool MenuPausa::render(View* view){
    //window->limpiar();
    //window->render(fondo);

 //   for (int i=0;i<MAX_NUMBER_OF_ITEMS_P;i++){
 //       window->escribir(&menuP[i]);
 //   }
    Vector2D posicion;
    posicion.x = view->getCenter().x - kDistX;

    switch(menustate){
        case 1:
            menuP[0].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_P +1) * 1));
            window->escribir(&menuP[0]);
        
            menuP[1].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_P +1) * 2));
            window->escribir(&menuP[1]);

            menuP[2].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_P +1) * 3));
            window->escribir(&menuP[2]);

            menuP[3].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_P +1) * 4));
            window->escribir(&menuP[3]);
        break;
    
        case 2:
            if(arco==false) menuT[0].setString("Comprar Arco - 50$");
            else menuT[0].setString("Arco - Comprado");
            menuT[0].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 1));
            window->escribir(&menuT[0]);

            if(laser==false) menuT[1].setString("Comprar Laser - 100$");
            else menuT[1].setString("Laser - Comprado");
            menuT[1].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 2));
            window->escribir(&menuT[1]);

            if(lanza==false) menuT[2].setString("Comprar Lanzallamas - 200$");
            else menuT[2].setString("Lanzallamas - Comprado");
            menuT[2].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 3));
            window->escribir(&menuT[2]);

            if(arco == true){

                if(arco_mej==false) menuT[3].setString("Mejora del Arco - 200$");
                else menuT[3].setString("Arco - Mejorado");
                menuT[3].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 4));
                window->escribir(&menuT[3]);
            }

            else{

                menuT[3].setString("Mejora del Arco - Sin Arma");
                menuT[3].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 4));
                window->escribir(&menuT[3]);
            }

            if(laser == true){

                if(laser_mej==false) menuT[4].setString("Mejora del Laser - 200$");
                else menuT[4].setString("Laser - Mejorado");
                menuT[4].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 5));
                window->escribir(&menuT[4]);
            }

            else{

                menuT[4].setString("Mejora del Laser - Sin Arma");
                menuT[4].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 5));
                window->escribir(&menuT[4]);
            }
            
            if(lanza == true){

                if(lanza_mej==false) menuT[5].setString("Mejora del Lanzallamas - 200$");
                else menuT[5].setString("Lanzallamas - Mejorado");
                menuT[5].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 6));
                window->escribir(&menuT[5]);
            }

            else{

                menuT[5].setString("Mejora del Lanzallamas - Sin Arma");
                menuT[5].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 6));
                window->escribir(&menuT[5]);
            }

            menuT[6].setString("Recargar Todas las Armas - 20$");
            menuT[6].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 7));
            window->escribir(&menuT[6]);

            menuT[7].setString("Comprar Armadura - 50$");
            menuT[7].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 8));
            window->escribir(&menuT[7]);

            menuT[8].setString("Comprar Vida - 100$");
            menuT[8].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 9));
            window->escribir(&menuT[8]);

            menuT[9].setString("Salir");
            menuT[9].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_T +1) * 10));
            window->escribir(&menuT[9]);
        break;    

    }
    window->display();
    return pausado;
}


void MenuPausa::MoveUp(){
   switch(menustate){
        case 1:
            if(selectedItemIndexP -1 >=0)
            {
                menuP[selectedItemIndexP].setColor(sf::Color::White);
                selectedItemIndexP--;
                menuP[selectedItemIndexP].setColor(sf::Color::Red);
            }
        break;
        case 2:
            if(selectedItemIndexT -1 >=0)
            {
                menuT[selectedItemIndexT].setColor(sf::Color::White);
                selectedItemIndexT--;
                menuT[selectedItemIndexT].setColor(sf::Color::Red);
            }
        break;
   }        
         
}

void MenuPausa::MoveDown(){

    switch(menustate){
        case 1:
            if(selectedItemIndexP + 1 < MAX_NUMBER_OF_ITEMS_P)
            {
                menuP[selectedItemIndexP].setColor(sf::Color::White);
                selectedItemIndexP++;
                menuP[selectedItemIndexP].setColor(sf::Color::Red);
            } 
        break;
        case 2:    
           if(selectedItemIndexT + 1 < MAX_NUMBER_OF_ITEMS_T)
            {
                menuT[selectedItemIndexT].setColor(sf::Color::White);
                selectedItemIndexT++;
                menuT[selectedItemIndexT].setColor(sf::Color::Red);
            } 
        break;
    }        
};
