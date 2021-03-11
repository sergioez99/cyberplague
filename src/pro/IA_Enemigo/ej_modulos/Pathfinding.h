#pragma once
#include <iostream>
#include <list>
#include <cmath>
#include "Nodo.h"

using namespace std;

class Pathfinding {
  private:
    list<Nodo> listaInterior;
    list<Nodo> listaFrontera;
    int costeRecto;
    int costeDiagonal;

  public:
    Pathfinding();
    ~Pathfinding();

    Nodo* encontrarCamino(int **matriz, Nodo ini, Nodo fin);
    list<Nodo> nodosAdyacentes(int **matriz, Nodo n, Nodo meta);
};