#include <SFML/Graphics.hpp>
#include "Map.h"
#include <vector>
#include "Motor2D/M_Window.h"
//Para audio
#include <SFML/Audio.hpp>
//Para relojes, creo
#include <SFML/System.hpp>



//Esta es la clase desde donde se empieza a ejecutar todo, por eso contiene los estados.

class CyberPlague; //Clase contexto

class State{ //Clase estado
    protected:
        CyberPlague *contexto;
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
  
  //M_Window* window; Habrá que usar esta digo yo
  sf::RenderWindow *window;
  sf::Event event;
};