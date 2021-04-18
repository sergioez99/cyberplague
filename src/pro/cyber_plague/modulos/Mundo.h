#include "CyberPlague.h"

class Mundo: public State{ //Class ingame
    public:
        static Mundo* Instance(CyberPlague* context, M_Window *w, int nivel);
        Mundo(CyberPlague* context, M_Window *w, int nivel);
        void Handle();
        void Update();
        void Init();
        void Render();
    private:
        M_Window *window;
        CyberPlague* _context;
        static Mundo* pinstance;
};