#pragma once
#include <SFML/Graphics.hpp>
#include "M_Window.h"


#include <iostream>

using namespace std;
using namespace sf;

class M_Input{

    private:

        static M_Window* ventana;

        static M_Input* instancia;

        static vector<bool>* teclas;

    public:

        static string getKeys();

        //Controlador de Teclas.
        static string InputController();

        //METODO PARA SABER SI UNA TECLA ESTA PULSADA.
        static bool isKeyPressedZ();
        static bool isKeyPressedX();
        static bool isKeyPressedC();
        static bool isKeyPressedLeft();
        static bool isKeyPressedRight();
        static bool isKeyPressedUp();
        static bool isKeyPressedDown();
        static bool isKeyPressedReturn();
        static bool isKeyPressedEscape();

        static M_Input* Instanciar(M_Window* vent);
        static void EliminarInstancia();

    protected:

        M_Input();
        ~M_Input();

};