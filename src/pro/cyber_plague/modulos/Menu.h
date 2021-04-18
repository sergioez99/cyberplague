#include "CyberPlague.h"

class Menu: public State{

//Funciones de estado
    void Handle();
    void Init();
    void Update();
    CyberPlague* getContext();
    static Menu* Instance(CyberPlague* context, M_Window *w);
    void Render();
    
    ~Menu();
    
    
    protected:
        
    Menu(CyberPlague* context,M_Window *w);
    Menu(const Menu &);
    Menu &operator = (const Menu &);
    
    
private:
    M_Window* window;
    static Menu* pinstance;
    CyberPlague* _context;
};