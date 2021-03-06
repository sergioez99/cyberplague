#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string> 
#include "Motor2D/M_Window.h"
#include "Motor2D/M_Input.h"
#include "MenuPausa.h"
#include "Entidades/Player.h"
#include <SFML/Audio.hpp>

#define MAX_NUMBER_OF_ITEMS 4
#define MAX_NUMBER_OF_ITEMS_L 4
#define MAX_NUMBER_OF_ITEMS_N 1

#define MAX_NUMBER_OF_ITEMS_P 4
#define MAX_NUMBER_OF_ITEMS_T 10


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
  Player* player;
  M_Window* window;

public:
  CyberPlague(); //La función que lo crea todo es esta -> la que se llama en el main y ya
  CyberPlague(State *estado){ this->cambiarEstado(estado); }
  ~CyberPlague();

  static CyberPlague* Instance();
  void cambiarEstado(State *estado);
  void Handle();
  void update();
  void pausar();
  void despausar();
  Player* getPlayer();
  M_Window* getWindow();
  
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
        M_Sprite* fondoM;
     //   vector<bool> key;

        static Menu* pinstance;
        CyberPlague *_contexto;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
        sf::Text menuL[MAX_NUMBER_OF_ITEMS_L];
        sf::Text menuN[MAX_NUMBER_OF_ITEMS_N];
        sf::Text menuT[MAX_NUMBER_OF_ITEMS_T];
        sf::Text menuP[MAX_NUMBER_OF_ITEMS_P];
        sf::Music intro, mapa1, mapa2, mapa3, menu1;

};


//Menu pausa q está dentro de mundo
class MenuPausa{
 
    private:
        M_Window* window; 
        M_Sprite* fondo;
        int selectedItemIndexP;
        int selectedItemIndexT;
        int width;
        int height;
        sf::Font font;
        sf::Text menuP[MAX_NUMBER_OF_ITEMS_P];
        sf::Text menuT[MAX_NUMBER_OF_ITEMS_T];
        bool pausado;
        int menustate=1;
        bool arco=false;
        bool laser=false;
        bool lanza=false;

        bool arco_mej = false;
        bool laser_mej = false;
        bool lanza_mej = false;

    public:

        MenuPausa(M_Window *w);
        ~MenuPausa();

        int update(int mon);
        bool render(View* view);

        void MoveUp();
        void MoveDown();

};

class Mundo: public State{ //Class ingame
    public:
        static Mundo* Instance(CyberPlague* context, M_Window *w, int nivel);
        static void EliminarInstancia();

        Mundo(CyberPlague* context, M_Window *w, int nivel);
        ~Mundo();
        void Handle();
        void Update();
        void Init();
        void Render();
        static bool instanced();
        void cambiarLvl(int lvl);
    private:
        
        M_Window *vent;
        CyberPlague* _context;
        Player* player;

        static Mundo* pinstance;
        int lvl;
        MenuPausa* pmenu;
        bool pausado=false;
        M_Sprite* fondo;
        sf::Music mapa1, mapa2, mapa3;
};



