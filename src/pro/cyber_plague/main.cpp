#include <iostream>
#include "include/includes.h" //Añadir aqui los includes.
#define kUpdateTimePS 1000/15
#define kVel 200  //Temporal, mientras mago actue como jugador

#include "CyberPlague.h"


using namespace std;


int main() {

  CyberPlague::Instance()->Handle(); // iniciar el juego desde los estados
  return 0;
}