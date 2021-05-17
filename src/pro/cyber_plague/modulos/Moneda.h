#include "Motor2D/M_Sprite.h"
#include "Motor2D/M_Window.h"


class Moneda{

    private:

        M_Sprite* spr_moneda;
        int valor;

    public:

        Moneda(int val, float posX, float posY);
        ~Moneda();

        int getValor();
        M_Sprite* getSprite();
        void render(M_Window* vent);
};