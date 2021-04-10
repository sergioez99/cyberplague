#pragma once
#include <iostream>
#include <list>
#include <cmath>
#include <SFML/Graphics.hpp> //Para acceder a Vector2f (no se si se puede de otra forma)
#include "Map.h"

using namespace std;
using namespace sf;

class Nodo{
    private:
        Nodo *padre;
        int f;
        int g;
        int h;
        int x;
        int y;

    public:
        Nodo(Nodo *p, int coorX, int coorY);
        ~Nodo();

        Nodo* getPadre();
        int getF();
        int getG();
        int getH();
        int getX();
        int getY();

        void setPadre(Nodo *p);
        void setF(int fn);
        void setG(int gn);
        void setH(int hn);

        bool operator==(const Nodo &n);
        bool operator!=(const Nodo &n);
};

class AI_Agent{
    private:
        list<Nodo> listaInterior;
        list<Nodo> listaFrontera;
        int costeRecto;
        int costeDiagonal;

    public:
        AI_Agent();
        ~AI_Agent();

        list<Vector2f> encontrarCamino(Map *m, Vector2f ini, Vector2f fin);
        list<Nodo> nodosAdyacentes(Map *m, Nodo n, Nodo meta);
};