#include "MenuPausa.h"


MenuPausa::MenuPausa(M_Window *w){
    window=w;

    width = 640;
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

    selectedItemIndexP = 0;

}

MenuPausa::~MenuPausa(){

}


void MenuPausa::update(){
    pausado=true;
    string key;
    key = M_Input::InputController();
    
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
            break;
            case 2:
              //   Menu::Instance(CyberPlague::Instance(), window, 0)->Handle();               
                //aqui al menu
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
}

bool MenuPausa::render(View* view){
    //window->limpiar();
    //window->render(fondo);

 //   for (int i=0;i<MAX_NUMBER_OF_ITEMS_P;i++){
 //       window->escribir(&menuP[i]);
 //   }
    Vector2D posicion;
    posicion.x = view->getCenter().x;


    menuP[0].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_P +1) * 1));
    window->escribir(&menuP[0]);
;
    menuP[1].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_P +1) * 2));
    window->escribir(&menuP[1]);

    menuP[2].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_P +1) * 3));
    window->escribir(&menuP[2]);

    menuP[3].setPosition(sf::Vector2f(posicion.x, height / (MAX_NUMBER_OF_ITEMS_P +1) * 4));
    window->escribir(&menuP[3]);


    window->display();
    return pausado;
}


void MenuPausa::MoveUp(){
   
    if(selectedItemIndexP -1 >=0)
    {
        menuP[selectedItemIndexP].setColor(sf::Color::White);
        selectedItemIndexP--;
        menuP[selectedItemIndexP].setColor(sf::Color::Red);
    }
         
}

void MenuPausa::MoveDown(){
   

    if(selectedItemIndexP + 1 < MAX_NUMBER_OF_ITEMS_P)
    {
        menuP[selectedItemIndexP].setColor(sf::Color::White);
        selectedItemIndexP++;
        menuP[selectedItemIndexP].setColor(sf::Color::Red);
    } 
           
};
