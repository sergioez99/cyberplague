#pragma once
#include <SFML/Graphics.hpp>
#include "Animacion.h"

class Player
{
public: 
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	Animacion animacion;
	unsigned int row;
	float speed;
	bool faceRight;
};
