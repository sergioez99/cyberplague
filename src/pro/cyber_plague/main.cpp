#include <iostream>
#include "CyberPlague.h"

using namespace std;


int main() {

  CyberPlague::Instance()->Handle(); // iniciar el juego desde los estados
  return 0;
}