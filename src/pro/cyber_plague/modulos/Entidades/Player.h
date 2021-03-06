#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Animacion.h"
#include "Entidad.h"
#include "NPC.h"
#include "Map.h"
#include "Hud.h"

#include "Armas/Arma.h"
#include "Armas/Tipo_de_Arma/Arco.h"
#include "Armas/Tipo_de_Arma/Laser.h"
#include "Armas/Tipo_de_Arma/Rayo.h"
#include "Armas/Tipo_de_Arma/Lanzallamas.h"


class Player : public Entidad, public Hud
{
public: 
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float posX, float posY);
	~Player();

	void update(float deltaTime, Map *m);
	//void Draw(sf::RenderWindow& window);

	int mirandoDerecha();
	int getDmg();

	Arma* getArmaEquipada();
	int getIntArmaActual();
	

	void setDmg(int d);
	void checkEnemyColision(vector<NPC*> enemigos);
	void ataque();
	bool superado();
	void noSuperado(); //Para controlar el cambio de nivel.

	bool consigoDinero(Moneda* moneda);
	bool consigoMejora(Mejora* mejora);

	int compruebaMunicionArmas(); //Este metodo comprueba la municion de todas las armas y devuelve el indice del arma que menos 										municion tenga. En el caso de que todas las armas tengan la municion al máximo, devuelve -1.

	int getDinero();
	void quitarDinero(int cantidad);
	void aumentarDinero(int cantidad);

	void consigoArma(string tipo);
	bool tengoArma(string tipo);
	void mejoroArma(string tipo);
	Arma* devuelvoArma(string tipo);
	int numArmasEquipadas();
	bool todasArmasCargadas();
	void setDefaultValues();

	void incrementarArmadura();
	void incrementarVida();

	void recargoMunicion();
	
	void renders(M_Window* vent, float percentTick, Map* mapa);

private:
	sf::RectangleShape body;
	Animacion animacion;

	vector<Arma*> armas;
	int arma_actual;

	Clock temp_cambioArma;

	unsigned int row;
	float speed;
	bool faceRight;
	int dmg;

	int monedero;
	
	bool next = false;

	bool heDisparado = false;
	bool heSaltado = false;
	
    virtual bool puedoAtacar(){return false;};
    virtual void moverse(float deltaTime){};

};
