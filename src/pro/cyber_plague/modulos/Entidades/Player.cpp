#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : 
	animacion(texture, imageCount, switchTime)
{	
	this->speed = speed;
	row = 0;
	faceRight = true;

	spr = new M_Sprite("Union 3.png",0,0,100,150,206,206);
	//body.setSize(sf::Vector2f(100.0f, 150.0f));
	//body.setPosition(206.f, 206.f);
	//body.setTexture(texture);

}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		movement.x -= speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movement.x += speed * deltaTime;

	if (movement.x == 0.0f) {
		row = 0;
	}
	else {
		row = 1;

		if (movement.x > 0.0f) {
			faceRight = true;
		}
		else {
			faceRight = false;
		}
	}
	animacion.Update(row, deltaTime, faceRight);
	VectorInt4D vect{animacion.uvRect.left,animacion.uvRect.top,animacion.uvRect.width,animacion.uvRect.height};
	spr->setTextureRect(vect);
	spr->mover(movement.x,movement.y);
}

/*void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}*/