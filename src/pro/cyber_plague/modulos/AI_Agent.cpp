#include "AI_Agent.h"

/* COSTE PARA MOVERSE */

#define kRecto 10
#define kDiagonal 14

/*--------------------*/

Nodo::Nodo(Nodo *p, int coorX, int coorY){
    padre = p;
    f = g = h = 0;
    x = coorX;
    y = coorY;
}

Nodo::~Nodo(){
    padre = NULL;
}

Nodo* Nodo::getPadre(){
    return padre;
}

int Nodo::getF(){
    return f;
}

int Nodo::getG(){
    return g;
}

int Nodo::getH(){
    return h;
}

int Nodo::getX(){
    return x;
}

int Nodo::getY(){
    return y;
}

void Nodo::setPadre(Nodo *p){
    padre = p;
}

void Nodo::setF(int fn){
    f = fn;
}

void Nodo::setG(int gn){
    g = gn;
}

void Nodo::setH(int hn){
    h = hn;
}

bool Nodo::operator==(const Nodo &n){
    if(x == n.x && y == n.y)
        return true;

    return false;
}

bool Nodo::operator!=(const Nodo &n){
    if(x != n.x || y != n.y)
        return true;

    return false;
}

AI_Agent::AI_Agent(){
    costeRecto = kRecto;
    costeDiagonal = kDiagonal;
}

AI_Agent::~AI_Agent(){
    listaInterior.clear();
    listaFrontera.clear();
}

list<Vector2f> AI_Agent::encontrarCamino(Vector2f ini, Vector2f fin){
    //Vaciar listas si no lo estan
    if(!listaInterior.empty())
        listaInterior.clear();
    if(!listaFrontera.empty())
        listaFrontera.clear();

    Nodo inicio(NULL, ini.x, ini.y);
    Nodo meta(NULL, fin.x, fin.y);
    list<Vector2f> camino;

    listaFrontera.push_back(inicio);

    while(!listaFrontera.empty()){
        //Obtener nodo de listaFrontera con menor f
        Nodo n = listaFrontera.front();
        list<Nodo>::iterator it;

        //Recorrer listaFrontera
        for(it = listaFrontera.begin(); it != listaFrontera.end(); it++){
            Nodo aux = *it;

            if(aux.getF() < n.getF())
                n = aux;
        }

        listaFrontera.remove(n);
        listaInterior.push_back(n);

        if(n == meta){
            //Reconstruir el camino siguiendo los punteros a nodo padre
            for(Nodo *aux = &n; aux != NULL; aux = aux->getPadre()){
                Vector2f v(aux->getX(), aux->getY());

                camino.push_back(v);
            }

            return camino;
        }

        //Comprobat nodos adyacentes al actual (n)
        list<Nodo> adyacentes = nodosAdyacentes(n, meta);

        for(it = adyacentes.begin(); it != adyacentes.end(); it++){
            Nodo m = *it;
            list<Nodo>::iterator it2 = listaFrontera.begin();

            //Recorrer listaFrontera para ver si el hijo m esta ya incluido
            for(; *it2 != m && it2 != listaFrontera.end(); it2++);

            //Hijo m no esta en listaFrontera
            if(it2 == listaFrontera.end())
                listaFrontera.push_back(m);
            //Hijo m esta en listaFrontera (actualizar padre y costes)
            else{
                Nodo aux = *it2;

                //Coste g del hijo m es menor que el coste g del mismo nodo ya almacenado en listaFrontera
                if(m.getG() < aux.getG()){
                    aux.setPadre(&n);

                    //Recalcular f y g del nodo aux
                    if(aux.getX() != n.getX() && aux.getY() != aux.getY())  //Diagonal
                        aux.setG(n.getG() + costeDiagonal);
                    else
                        aux.setG(n.getG() + costeRecto);

                    aux.setF(aux.getG() + aux.getH());
                }
            }
        }
    }

    return camino;
}

list<Nodo> AI_Agent::nodosAdyacentes(Nodo n, Nodo meta){
    list<Nodo> adyacentes;
    list<Nodo>::iterator it = listaInterior.begin();

    //Recorrer listaInterior para poner como nodo padre al nodo almacenado en esta lista
    //Esto se podria evitar usando listas de punteros a nodo (list<Nodo*>) en vez de las actuales pero cuando lo probe me daba errores y no funcionaba
    for(; *it != n && it != listaInterior.end(); it++);

    //Crear nodos e incluirlos a adyacentes en funcion de la direccion en la que se muevan (colisiones)
}