#include "Pathfinding.h"

Pathfinding::Pathfinding(){
    costeRecto = 10;
    costeDiagonal = 14;
}

Pathfinding::~Pathfinding(){
    listaInterior.clear();
    listaFrontera.clear();
}

Nodo* Pathfinding::encontrarCamino(int **matriz, Nodo ini, Nodo fin){
    //Vaciar listas si no lo estan
    if(!listaInterior.empty())
        listaInterior.clear();
    if(!listaFrontera.empty())
        listaFrontera.clear();

    Nodo inicio = ini, meta = fin;

    listaFrontera.push_back(inicio);

    while(!listaFrontera.empty()){
        //Obtener de listaFrontera el nodo con menor f
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

        if(listaFrontera.empty())
            return NULL;
        if(n == meta)
            return &n;  //Reconstruir camino siguiendo los punteros

        //Comprobar nodos adyacentes al actual
        list<Nodo> adyacentes = nodosAdyacentes(matriz, n, meta);

        for(it = adyacentes.begin(); it != adyacentes.end(); it++){
            Nodo m = *it;
            list<Nodo>::iterator it2;

            for(it2 = listaFrontera.begin(); *it2 != m && it2 != listaFrontera.end(); it2++);

            //Hijo m no esta en listaFrontera
            if(it2 == listaFrontera.end() && *it2 != m)
                listaFrontera.push_back(m);
            else{
                Nodo aux = *it2;

                //Coste g del hijo m es menor que el coste g del mismo nodo ya almacenado en listaFrontera
                if(m.getG() < aux.getG()){
                    aux.setPadre(&n);

                    //Recalcular f y g del nodo m
                    if(aux.getX() != n.getX() && aux.getY() != n.getY())    //Diagonal
                        aux.setG(n.getG() + costeDiagonal);
                    else
                        aux.setG(n.getG() + costeRecto);
                        
                    aux.setF(aux.getG() + aux.getH());
                }
            }
        }
    }
}

list<Nodo> Pathfinding::nodosAdyacentes(int **matriz, Nodo n, Nodo meta){
    list<Nodo> adyacentes;
    Nodo *hijo;

    //Direccion arriba izquierda (diagonal)
    if(n.getX() - 1 > -1 && n.getY() - 1 > -1 && matriz[n.getX() - 1][n.getY() - 1] == 0){
        hijo = new Nodo(n);
        hijo->setG(costeDiagonal);
        hijo->setH(abs(n.getX() - meta.getX()) + abs(n.getY() - meta.getY()));
        hijo->setF(hijo->getG() + hijo->getH());
        adyacentes.push_back(*hijo);
    }
    //Direccion izquierda (recto)
    if(n.getX() - 1 > -1 && matriz[n.getX() - 1][n.getY()] == 0){
        hijo = new Nodo(n);
        hijo->setG(costeRecto);
        hijo->setH(abs(n.getX() - meta.getX()) + abs(n.getY() - meta.getY()));
        hijo->setF(hijo->getG() + hijo->getH());
        adyacentes.push_back(*hijo);
    }
    //Direccion arriba derecha (diagonal)
    if(n.getX() + 1 < 16 && n.getY() - 1 > -1 && matriz[n.getX() + 1][n.getY() - 1] == 0){
        hijo = new Nodo(n);
        hijo->setG(costeDiagonal);
        hijo->setH(abs(n.getX() - meta.getX()) + abs(n.getY() - meta.getY()));
        hijo->setF(hijo->getG() + hijo->getH());
        adyacentes.push_back(*hijo);
    }
    //Direccion derecha (recto)
    if(n.getX() + 1 < 16 && matriz[n.getX() + 1][n.getY()] == 0){
        hijo = new Nodo(n);
        hijo->setG(costeRecto);
        hijo->setH(abs(n.getX() - meta.getX()) + abs(n.getY() - meta.getY()));
        hijo->setF(hijo->getG() + hijo->getH());
        adyacentes.push_back(*hijo);
    }

    return adyacentes;
}