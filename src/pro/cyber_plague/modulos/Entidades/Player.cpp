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

	spr = new M_Sprite("Union 3e.png",0,0,texture->getSize().x / float(imageCount.x),texture->getSize().y / float(imageCount.y),206,206);

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
	Vector2D movement{0.0f, 0.0f};
	//Utilizar Vector2D en vez del sf::Vector2f para no usar SFML

	if(salto > 0){

		movement.y -= 5 * salto * salto * deltaTime;
		salto -= 2;
	}
	if (M_Input::isKeyPressedLeft())
		movement.x -= speed * deltaTime;

	if (M_Input::isKeyPressedRight())
		movement.x += speed * deltaTime;

	if (M_Input::isKeyPressedUp() && isGrounded() && heSaltado == false){

		salto = 10;
		movement.y -= 4 * salto * salto * deltaTime;
		heSaltado = true;
		setGrounded(false);
	}

	if(!M_Input::isKeyPressedUp() && isGrounded()){

		heSaltado = false;
	}

	if(arma_actual != 3){

		if (M_Input::isKeyPressedZ() && heDisparado == false){

			ataque();
			heDisparado = true;

		}

		if(!M_Input::isKeyPressedZ()){

			heDisparado = false;
		}

	}

	

	if(M_Input::isKeyPressedC()){
		
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
		armas.at(i)->update(deltaTime, m);
	}

	if(m->checkCollision(getSprite()->getSprite()))//si es verdadero, no debe de estar en esa posicion
		getSprite()->setPosition(getLastPosition());

	//Evita que pueda salir del mapa
	float posLadoDerecho = getPosX() - getSprite()->getSprite()->getGlobalBounds().width / 2;
	float posLadoIzquierdo = getPosX() + getSprite()->getSprite()->getGlobalBounds().width / 2;

	if(posLadoDerecho < 0)
		getSprite()->setPosition(getLastPosition());

	if(posLadoIzquierdo > m->getWidth() * m->getTileWidth())
		next = true;

	//Gravedad
	if(!isJumping()){//Si no salta, aplicar gravedad
	 	salto -= 2;
        getSprite()->mover(0, 4 * salto * salto * deltaTime);
        if(m->checkCollision(getSprite()->getSprite())){//si es verdadero, ya estaba en el suelo.
			colPos.x = getSprite()->getPosX();
			colPos.y = m->getCollision(getSprite()->getSprite())->getGlobalBounds().top-getSprite()->getSprite()->getLocalBounds().height/2;
        	getSprite()->setPosition(colPos); //Esto se utiliza para que este tocando el suelo, y no flotando.
          	setGrounded(true);
			salto=0;
			/*if(saltoCD>0)
				saltoCD--;*/
        }else{
          	setGrounded(false);//Se puede caer por un agujero y no estar grounded igualmente
        }
    }

	//Si se cae por un hueco muere
	if(getPosY() > m->getHeight() * m->getTileHeight())
		setVida(0);
	
	pos.setPosition(spr->getPosX(), spr->getPosY());

	//cout << M_Input::getKeys() << endl;
}

int Player::getDmg(){

	return dmg;
}

Arma* Player::getArmaEquipada(){

	return armas.at(arma_actual);
}

bool Player::superado(){
	return next;
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

void Player::renders(M_Window* vent, float percentTick, Map* mapa){

	this->renderPlayer(vent, percentTick, mapa);

	for(unsigned int  i = 0; i < armas.size(); i++){

		armas[i]->render(vent, percentTick);
	}

	
}

