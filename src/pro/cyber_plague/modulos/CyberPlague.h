#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <vector>
#include <string> 
#include "Motor2D/M_Window.h"
#include "Motor2D/M_Input.h"
#include "MenuPausa.h"


#define MAX_NUMBER_OF_ITEMS 5
#define MAX_NUMBER_OF_ITEMS_L 5
#define MAX_NUMBER_OF_ITEMS_N 1
#define MAX_NUMBER_OF_ITEMS_T 3
#define MAX_NUMBER_OF_ITEMS_P 4


//Esta es la clase desde donde se empieza a ejecutar todo, por eso contiene los estados.

class CyberPlague; //Clase contexto

class State{ //Clase estado
    protected:
        CyberPlague *contexto;
        bool quit;
        
    public:
        virtual ~State(){ };
        void setContexto(CyberPlague *contexto){ this->contexto = contexto; };
        virtual void Handle() = 0;
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
};

class CyberPlague {

    
private:
  State *estado;
  static CyberPlague* pinstance;

public:
  CyberPlague(); //La función que lo crea todo es esta -> la que se llama en el main y ya
  CyberPlague(State *estado){ this->cambiarEstado(estado); }

  static CyberPlague* Instance();
  void cambiarEstado(State *estado);
  void Handle();
  void update();
  void pausar();
  void despausar();
  
  M_Window* window;
};

class Menu : public State{
    
    
      public:
        ~Menu();

        void Render();
        int run(M_Window *window);
        void MoveUp();
        void MoveDown();
        void Update();
        void Handle();
        void Init();
        CyberPlague* getContexto();
        int GetPressedItem();
        int Eventos(string key);
        static Menu* Instance(CyberPlague* contexto, M_Window *w, int inic);

    protected: 
        Menu(CyberPlague* contexto, M_Window *w, int inic);
        Menu(const Menu &);
        Menu &operator = (const Menu &);   

    private:

        int nivel;
        int menustate = 1;
        int selectedItemIndex;
        int selectedItemIndexL;
        int selectedItemIndexN;
        int selectedItemIndexT;
        int selectedItemIndexP;
        int width;
        int height;
        M_Window* window; 
        M_Sprite* fondo;
        M_Sprite* fondoC;
     //   vector<bool> key;

        static Menu* pinstance;
        CyberPlague *_contexto;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Text menuL[MAX_NUMBER_OF_ITEMS_L];
        sf::Text menuN[MAX_NUMBER_OF_ITEMS_N];
        sf::Text menuT[MAX_NUMBER_OF_ITEMS_T];
        sf::Text menuP[MAX_NUMBER_OF_ITEMS_P];

};

class Mundo: public State{ //Class ingame
    public:
        static Mundo* Instance(CyberPlague* context, M_Window *w, int nivel);
        Mundo(CyberPlague* context, M_Window *w, int nivel);
        void Handle();
        void Update();
        void Init();
        void Render();
    private:
        
        M_Window *vent;
        CyberPlague* _context;
        static Mundo* pinstance;
        int lvl;
        MenuPausa* pmenu;
        bool pausado=false;
        M_Sprite* fondo;
};