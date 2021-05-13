#include "Motor2D/M_Sprite.h"
#include "Motor2D/M_Window.h"

class Mejora{

    private:

        M_Sprite* sprite_mejora;
        int tipo;

        bool cogido;
        bool obtenible;

    public:

        Mejora(int tipo, float posX, float posY);
        ~Mejora();

        int getTipo();

        bool getCogido();
        void setCogido();

        bool getObtenible();
        void setObtenible();

        void update();
        void render(M_Window* vent);

        M_Sprite* getSprite();
};


class Cofre{

    private:

        M_Sprite* sprite_abierto;
        M_Sprite* sprite_cerrado;

        M_Sprite* rec_mejora;

        vector<Mejora*> mejoras;

        Clock relojCambioMejora;
        Clock relojTiempoAbierto;

        int mejoraActual;
        bool abierto;

    public:

        Cofre(float posX, float posY);
        ~Cofre();

        bool isOpen();

        void abrir();

        void update();
        void render(M_Window* vent);

        M_Sprite* getSprite();
        Mejora* getMejora();
};