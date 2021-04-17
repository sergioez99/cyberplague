#include "Player.h"

#define kVida  50


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : 
	animacion(texture, imageCount, switchTime)
{	
	this->speed = speed;
	row = 0;
	faceRight = true;
	dmg = 0;
	vida = new int( kVida );

	spr = new M_Sprite("Union 3.png",0,0,texture->getSize().x / float(imageCount.x),texture->getSize().y / float(imageCount.y),206,206);

	pos.setPosition(206.f, 206.f);
	pos.setPosition(206.f, 206.f);
}

Player::~Player(){
	delete spr;
	delete vida;
}

void Player::update(float deltaTime, Map* m)
{
	//setLastPosition();

	sf::Vector2f movement(0.0f, 0.0f);
	//Gravedad
	 if(!isJumping()){//Si no salta, aplicar gravedad
        getSprite()->mover(0, 2 * speed * deltaTime);
		//movement.y += 2*speed*deltaTime;
        if(m->checkCollision(getSprite()->getSprite())){//si es verdadero, ya estaba en el suelo.
          getSprite()->mover(0, -2 * speed * deltaTime);
		  //movement.y -= 2*speed*deltaTime;
          setGrounded(true);
        }else{
          setGrounded(false);//Se puede caer por un agujero y no estar grounded igualmente
        }
      }
	if(salto>0){
		movement.y -= 2 * speed * deltaTime;
		salto--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		movement.x -= speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movement.x += speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isGrounded()){
		movement.y -= 2 * speed * deltaTime;
		salto = 15;
		setGrounded(false);
	}
		

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
	spr->cambiarPosTextura(animacion.uvRect.left,animacion.uvRect.top,animacion.uvRect.width,animacion.uvRect.height);
	spr->mover(movement.x,movement.y);
	if(m->checkCollision(getSprite()->getSprite()))//si es verdadero, no debe de estar en esa posicion
		getSprite()->setPosition(getLastPosition());
		
	pos.setPosition(spr->getPosX(), spr->getPosY());
}

int Player::getDmg(){

	return dmg;
}

void Player::setDmg(int d){

	dmg = d;
}

int Player::mirandoDerecha(){

	if(faceRight) return 1;
	else return -1;
}

void Player::checkEnemyColision(vector<NPC*> enemigos){
	for(unsigned int i = 0; i < enemigos.size(); i++){
		if(spr->getSprite()->getGlobalBounds().intersects(enemigos.at(i)->getSprite()->getSprite()->getGlobalBounds())){
			if(enemigos.at(i)->puedoAtacar())
				setVida(getVida() - enemigos.at(i)->getAtaque());
		}
	}
}