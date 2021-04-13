#pragma once
#include <SFML/Graphics.hpp>
#include "Animacion.h"
#include "Entidad.h"

class Player : public Entidad
{
public: 
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

    void update(float deltaTime, Map *m);
	//void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	Animacion animacion;
	unsigned int row;
	float speed;
	bool faceRight;
	
	virtual void ataque(){};
    virtual bool puedoAtacar(){return false;};
    virtual void moverse(float deltaTime){};

};
