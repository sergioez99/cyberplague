#include "M_Input.h"


#define k_Nkeys 9 //Numero de keys que se van a controlar.

/*

CODIFICACION DE LAS TECLAS:

- Z: 0          - Up: 3             
- X: 1          - Down: 4
- C: 2          - Left: 5
- Enter: 7      - Right: 6              
- Escape: 8
*/



M_Input* M_Input::instancia = 0;
M_Window* M_Input::ventana = 0; 

vector<bool>* M_Input::teclas = new vector<bool>(k_Nkeys, 0);

M_Input* M_Input::Instanciar(M_Window* vent){

    if(instancia == 0){

        instancia = new M_Input();
        ventana = vent;
    }

    return M_Input::instancia;
}

void M_Input::EliminarInstancia(){

    delete instancia;
}



string M_Input::getKeys(){

    string inputs = "[";

    for(unsigned int i = 0; i < teclas->size(); i++){

        if(teclas->at(i) == true){

            inputs = inputs + " true ";
        }

        else{

            inputs = inputs + " false ";
        }
    }

    inputs = inputs + "]";

    return inputs;
}



string M_Input::InputController(){

    Event event;

    while (ventana->pollEvent(&event)) {

        switch (event.type) {

        case Event::Closed:

            ventana->cerrar();
        break;

        case sf::Event::KeyPressed:

            switch (event.key.code) {

                case Keyboard::Z:

                    teclas->at(0) = true;
                    return "Z";
                break;

                case Keyboard::X:
                
                    teclas->at(1) = true;
                    return "X";
                break;

                case Keyboard::C:
                
                    teclas->at(2) = true;
                    return "C";
                break;

                case Keyboard::Up:

                    teclas->at(3) = true;
                    return "UP";
                break;

                case Keyboard::Down:

                    teclas->at(4) = true;
                    return "DOWN";       
                break;

                case Keyboard::Left:

                    teclas->at(5) = true;
                    return "LEFT";
                break;

                case Keyboard::Right:
                
                    teclas->at(6) = true;
                    return "RIGHT";
                break;

                case Keyboard::Return:
                
                    teclas->at(7) = true;
                    return "ENTER";
                break;

                case Keyboard::Escape:

                    teclas->at(8) = true;
                    return "ESCAPE";
                    //ventana->cerrar();
                break;

                default:

                break;
                
            }

        break;

        case Event::KeyReleased:

            switch (event.key.code) {

                case Keyboard::Z:

                    teclas->at(0) = false;
                    //return "NO_Z";
                break;

                case Keyboard::X:
                
                    teclas->at(1) = false;
                    //return "NO_X";
                break;

                case Keyboard::C:
                
                    teclas->at(2) = false;
                    //return "NO_C";
                break;

                case Keyboard::Up:

                    teclas->at(3) = false;
                    //return "NO_UP";
                break;

                case Keyboard::Down:

                    teclas->at(4) = false;
                    //return "NO_DOWN";
                break;

                case Keyboard::Left:

                    teclas->at(5) = false;
                    //return "NO_LEFT";
                break;

                case Keyboard::Right:
                
                    teclas->at(6) = false;
                    //return "NO_RIGHT";
                break;

                case Keyboard::Return:
                
                    teclas->at(7) = false;
                    //return "NO_ENTER";
                break;

                case Keyboard::Escape:
                
                    teclas->at(8) = false;
                    //return "NO_ENTER";
                break;

                default:

                break;
                
            }


        break;
      
        default:
         
        break;
      }   
    }

    return "NADA";
}


bool M_Input::isKeyPressedZ(){

    return teclas->at(0);
}

bool M_Input::isKeyPressedX(){

    return teclas->at(1);
}

bool M_Input::isKeyPressedC(){

    return teclas->at(2);
}

bool M_Input::isKeyPressedUp(){

    return teclas->at(3);
}

bool M_Input::isKeyPressedDown(){

    return teclas->at(4);
}

bool M_Input::isKeyPressedLeft(){

    return teclas->at(5);
}

bool M_Input::isKeyPressedRight(){

    return teclas->at(6);
}

bool M_Input::isKeyPressedReturn(){

    return teclas->at(7);
}

bool M_Input::isKeyPressedEscape(){

    return teclas->at(8);
}


//CONSTRUCTOR Y DESTRUCTOR.
M_Input::M_Input(){}
M_Input::~M_Input(){

    delete teclas;
}