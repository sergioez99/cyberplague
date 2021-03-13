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
    Pathfinding(const Pathfinding &);
    ~Pathfinding();
    Pathfinding & operator=(const Pathfinding &);

    list<Nodo> encontrarCamino(int matriz[16][12], Nodo ini, Nodo fin);
    list<Nodo> nodosAdyacentes(int matriz[16][12], Nodo n, Nodo meta);
};