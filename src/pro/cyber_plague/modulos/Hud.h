#include <iostream>
#include <sstream>
#include <Motor2D/M_Window.h>
#include <SFML/Graphics.hpp>
#include <Tools/posInterpolada.h>

class Hud{
    /*
    ---Partes del HUD---
    MaxVida
    Vida Actual
    Balas del arma equipada -> getArmaActual() -> saber las balas
    Arma equipada -> getIntArmaActual()
    Monedas/Puntuacion -> getMonedas()
    */
    protected:

    //sf::Image* healthBar;
    //sf::Image* health;
    //sf::Image* weaponType;
    sf::Text* money;
    sf::Text* ammo;
    sf::Text* totalAmmo;
    sf::Font* fuente;
    float PosX;
    float PosY;
    //Estos dos son para convertir números en string
    stringstream toString;
    string s;
    //

    public:

        Hud();
        ~Hud();

        void setPosHUD(float x, float y);
        void renderHUD(M_Window* vent, View* view);
        void setPosHUDsf();
};