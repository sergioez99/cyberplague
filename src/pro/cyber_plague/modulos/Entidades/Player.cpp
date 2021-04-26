#include "Player.h"

#define kVida  50
#define kTmpCamb 0.5f


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : 
	animacion(texture, imageCount, switchTime)
{	
	this->speed = speed;
	row = 0;
	faceRight = true;
	vida = new int( kVida );

	spr = new M_Sprite("Union 3.png",0,0,texture->getSize().x / float(imageCount.x),texture->getSize().y / float(imageCount.y),206,206);

	pos.setPosition(206.f, 206.f);
	pos.setPosition(206.f, 206.f);

	Arco* arco = new Arco(getPosX(), getPosY(), mirandoDerecha());
	Rayo* rayo = new Rayo(getPosX(), getPosY(), mirandoDerecha());
	Laser* laser = new Laser(getPosX(), getPosY(), mirandoDerecha());


	armas.push_back(rayo);
	armas.push_back(arco);
	armas.push_back(laser);

	arma_actual = 0;
}

Player::~Player(){
	delete spr;
	delete vida;
}

void Player::update(float deltaTime, Map* m)
{
	setLastPosition();
	Vector2D colPos{0,0};
	sf::Vector2f movement(0.0f, 0.0f);//En cada frame, esto se pone a 0, por lo que el bucle interpolado no va a ir, tiene que ser de clase.
	//Utilizar Vector2D en vez del sf::Vector2f para no usar SFML
	//Gravedad
	 if(!isJumping()){//Si no salta, aplicar gravedad
	 	salto--;
        getSprite()->mover(0, salto * salto * deltaTime);
        if(m->checkCollision(getSprite()->getSprite())){//si es verdadero, ya estaba en el suelo.
			colPos.x = getSprite()->getPosX();
			colPos.y = m->getCollision(getSprite()->getSprite())->getGlobalBounds().top-getSprite()->getSprite()->getLocalBounds().height/2;
        	getSprite()->setPosition(colPos); //Esto se utiliza para que este tocando el suelo, y no flotando.
          	setGrounded(true);
			salto=0;
        }else{
          	setGrounded(false);//Se puede caer por un agujero y no estar grounded igualmente
        }
      }
	if(salto>0){
		movement.y -= salto * salto * deltaTime;
		salto--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		movement.x -= speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movement.x += speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isGrounded()){//TODO: CD al salto
		salto = 22;
		movement.y -= salto * salto * deltaTime;
		setGrounded(false);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		ataque();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
		
		float tmp = temp_cambioArma.getElapsedTime().asMilliseconds() / 1000;

		if(tmp >= kTmpCamb){

			if(arma_actual == 2){

				arma_actual = 0;
				temp_cambioArma.restart();
			}

			else{

				arma_actual++;
				temp_cambioArma.restart();
			}

			cout << "ARMA CAMBIADA" << endl;
		}	
	}

	//ESTO ES PARA DEBUG. MEJORA EL ARMA EQUIPADA CON UN BOTON.
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
		
		armas[arma_actual]->mejorar();
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

	for(unsigned int i = 0; i < armas.size(); i++){

		armas.at(i)->setDatosJugador(getPosX(), getPosY(), mirandoDerecha());
		armas.at(i)->update(deltaTime);
	}

	

	if(m->checkCollision(getSprite()->getSprite()) )//si es verdadero, no debe de estar en esa posicion
		getSprite()->setPosition(getLastPosition());
		
	pos.setPosition(spr->getPosX(), spr->getPosY());
}

int Player::getDmg(){

	return dmg;
}

Arma* Player::getArmaEquipada(){

	return armas.at(arma_actual);
}

void Player::setDmg(int d){

	dmg = d;
}

int Player::mirandoDerecha(){

	if(faceRight) return 1;
	else return -1;
}

/*void Player::checkEnemyColision(vector<NPC*> enemigos){
	for(unsigned int i = 0; i < enemigos.size(); i++){
		if(spr->getSprite()->getGlobalBounds().intersects(enemigos.at(i)->getSprite()->getSprite()->getGlobalBounds())){
			if(enemigos.at(i)->puedoAtacar())
				setVida(getVida() - enemigos.at(i)->getAtaque());
		}
	}
}*/

void Player::ataque(){

	armas[arma_actual]->disparo();
}

void Player::renders(M_Window* vent, float percentTick){

	this->render(vent, percentTick);

	for(unsigned int  i = 0; i < armas.size(); i++){

		armas[i]->render(vent);
	}

	
}