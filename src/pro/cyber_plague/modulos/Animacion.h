#pragma once
#include <SFML/Graphics.hpp>

class Animacion
{
public:
	Animacion(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animacion();

	void Update(int row, float deltaTime, bool faceRight);

public:
	sf::IntRect uvRect;

private: 
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};