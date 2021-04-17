#pragma once
#include <SFML/Graphics.hpp>
#include "Animacion.h"
#include "Entidad.h"
#include "NPC.h"

class Player : public Entidad
{
public: 
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

    void update(float deltaTime, Map *m);
	//void Draw(sf::RenderWindow& window);

	int mirandoDerecha();
	int getDmg();
	void setDmg(int d);
	void checkEnemyColision(vector<NPC*> enemigos);


private:
	sf::RectangleShape body;
	Animacion animacion;
	unsigned int row;
	float speed;
	bool faceRight;
	int dmg;
	
	virtual void ataque(){};
    virtual bool puedoAtacar(){return false;};
    virtual void moverse(float deltaTime){};


};
