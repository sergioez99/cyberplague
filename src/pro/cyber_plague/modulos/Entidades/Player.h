#pragma once
#include <SFML/Graphics.hpp>
#include "Animacion.h"
#include "Entidad.h"
#include "NPC.h"

#include "Armas/Arma.h"
#include "Armas/Tipo_de_Arma/Arco.h"
#include "Armas/Tipo_de_Arma/Laser.h"
#include "Armas/Tipo_de_Arma/Rayo.h"
#include "Armas/Tipo_de_Arma/Lanzallamas.h"


class Player : public Entidad
{
public: 
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

    void update(float deltaTime, Map *m);
	//void Draw(sf::RenderWindow& window);

	int mirandoDerecha();
	int getDmg();
	Arma* getArmaEquipada();

	void setDmg(int d);
	//void checkEnemyColision(vector<NPC*> enemigos);
	void ataque();

	void renders(M_Window* vent, float percentTick);

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
	int saltoCD=0;
	
    virtual bool puedoAtacar(){return false;};
    virtual void moverse(float deltaTime){};


};
