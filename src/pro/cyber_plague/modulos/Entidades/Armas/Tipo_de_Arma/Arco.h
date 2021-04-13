#pragma once
#include <iostream>
#include "../Arma.h"


class Arco : public Arma{

    private:

        


    public:

        Arco(Player* p);
       ~Arco();

      void disparo();
      void mejorar();
      void update(float deltaTime);

};

