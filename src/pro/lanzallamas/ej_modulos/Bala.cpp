#include "Bala.h"

Bala::Bala(String t) {

  render = new CircleShape();
  render->setFillColor(Color::Yellow);
  render->setRadius(5.f);

  tipo = new String(t);
  dmg = new int(5);

}

Bala::~Bala(){

  delete tipo;
  delete dmg;
  delete render;
}

String Bala::getTipo(){

  return *tipo;

}

int Bala::getDmg(){

  return *dmg;
}