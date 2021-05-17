#include <iostream>
#include <cmath>
#include "../NPC.h"

using namespace std;

class Mago : public NPC {
    
    private:
        float spawnTime;
        //Reloj para controlar el tiempo de spawneo de enemigos
        Clock spawnClock;
        Time time;

    public:
        Mago(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY);
        ~Mago();


        /* METODOS HEREDADOS DE ENTIDAD. */
        void ataque();
        bool puedoAtacar();
        void moverse(float deltaTime);
        void update(float deltaTime, Map *m, M_Sprite* player);
        /* ----------------------------- */

        /* METODOS HEREDADOS DE NPC */
        bool deteccion(M_Sprite* player){return false;};
        /* ------------------------ */
};