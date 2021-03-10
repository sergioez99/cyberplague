#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Bala {

  private:

    //DECLARACION DE ATRIBUTOS.
    int* dmg;
    String* tipo;
    CircleShape* render;

  public:

    Bala(String t);
    ~Bala();

    String getTipo();
    int getDmg();
};