#include "Player.h"

#define kVida  50
#define kTmpCamb 0.5f


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float posX, float posY) : 
	animacion(texture, imageCount, switchTime)
{	
	this->speed = speed;
	row = 0;
	faceRight = true;
	vida = new int( kVida );
	vidaMax = new int( kVida );

	armadura = new int( 0 );

	monedero = 999;   //ESTA A 999 PARA PROBAR, CUANDO SE VAYA A ENTREGAR PONERLO A 0.

	spr = new M_Sprite("Union 3e.png",0,0,texture->getSize().x / float(imageCount.x),texture->getSize().y / float(imageCount.y),posX,posY);

	pos.setPosition(posX, posY);
	pos.setPosition(posX, posY);

	Rayo* rayo = new Rayo(getPosX(), getPosY(), mirandoDerecha());


	armas.push_back(rayo);

	arma_actual = 0;

	money = new sf::Text();
	armor = new sf::Text();
    ammo = new sf::Text();
    life = new sf::Text();
	fuente = new sf::Font();
    //Conversion de int a string
    toString << getDinero();
   	toString >> s;
    //
	
	//Iniciar HUD de player
	if(!fuente->loadFromFile("./resources/FIGHTT3_.ttf")){
        fuente->loadFromFile("./resources/arial.ttf");
    }
	money->setFont(*fuente);
    money->setString(s);
    money->setPosition(40,400);
	money->setColor(sf::Color::Black);

	s = " INF";
	ammo->setFont(*fuente);
	ammo->setPosition(40,80);
	ammo->setString(s);
	ammo->setColor(sf::Color::Black);

	ammoType = new M_Sprite("spritesheet_otros.png",32,0,16,8,10,10);

	s = "Life: ";
	char* c1 = new char();
	char* c2 = new char();
	sprintf(c1, "%d", getVida());//Convierte int a char*
	sprintf(c2, "%d", getVidaMax());
	s.append(c1); s.append("/"); s.append(c2);
	life->setFont(*fuente);
	life->setPosition(40,40);
	life->setString(s);
	life->setColor(sf::Color::Black);

	lifeIcon = new M_Sprite("vidas_1.png",0,0,80,79,0,0);
	lifeIcon->escalar(0.4,0.4);
	
	char* c = new char();

	sprintf(c, "%d", getArmadura());//Convierte int a char*
	s.append(c);

	armor->setFont(*fuente);
	armor->setPosition(40,120);
	armor->setString(s);
	armor->setColor(sf::Color::Black);

	armorIcon = new M_Sprite("spritesheet_otros.png",70,36,32,32,-80,-80);

	moneyIcon = new M_Sprite("spritesheet_otros.png", 32, 11, 16, 16, 40, 400);

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

	if (M_Input::isKeyPressedLeft())
		movement.x -= speed * deltaTime;

	if (M_Input::isKeyPressedRight())
		movement.x += speed * deltaTime;

	if (M_Input::isKeyPressedUp() && isGrounded() && heSaltado == false){

		salto = 11;
		//movement.y -= 4 * salto * salto * deltaTime;
		heSaltado = true;
		setGrounded(false);
	}

	if(!M_Input::isKeyPressedUp() && isGrounded()){

		heSaltado = false;
	}

	if(armas[arma_actual]->getTipo() != "lanzallamas"){

		if (M_Input::isKeyPressedZ() && heDisparado == false && armas[arma_actual]->puedeDisparar()){

			ataque();
			heDisparado = true;

		}

		if(!M_Input::isKeyPressedZ()){

			heDisparado = false;
		}

	}

	else{

		if (M_Input::isKeyPressedZ() && armas[arma_actual]->puedeDisparar()){

			ataque();
		}

		else{

			armas[arma_actual]->limpiarCargador();
		}
	}

	if(M_Input::isKeyPressedC()){
		
		float tmp = temp_cambioArma.getElapsedTime().asMilliseconds() / 1000;

		if(tmp >= kTmpCamb){

			if(armas.size() != 0){

				if(arma_actual == armas.size() - 1){

					arma_actual = 0;
					temp_cambioArma.restart();
				}

				else{

					arma_actual++;
					temp_cambioArma.restart();
				}
			}

			
		}	
	}
		
	if (movement.x == 0.0f && isGrounded()) {
		row = 0;
	}
	else{
		if(isGrounded())
			row = 1;
		else
			row = 2;

		if (movement.x > 0.0f) {
			faceRight = true;
		}
		else if(movement.x<0.0f){
			faceRight = false;
		}
	}
	spr->mover(movement.x,0);

	if(m->checkCollision(getSprite()->getSprite())){//si es verdadero, se ha chocado con algo en el eje X
		//getSprite()->setPosition(getLastPosition());
		colPos.y = getSprite()->getPosY();
		if(m->getCollision(getSprite()->getSprite())->getGlobalBounds().left+2>getSprite()->getPosX())
			colPos.x = m->getCollision(getSprite()->getSprite())->getGlobalBounds().left-4-getSprite()->getSprite()->getLocalBounds().width/2;
		else
			colPos.x = m->getCollision(getSprite()->getSprite())->getGlobalBounds().left+4+m->getCollision(getSprite()->getSprite())->getLocalBounds().width+getSprite()->getSprite()->getLocalBounds().width/2;
        getSprite()->setPosition(colPos); //Esto se utiliza para que este tocando el suelo, y no flotando.

	}

	if(salto > 0){
		//movement.y -= 4 * salto * salto * deltaTime;
		getSprite()->mover(0, -5 * salto * salto * deltaTime);
		salto -= 2;
		if(m->checkCollision(getSprite()->getSprite())){//Si es verdadero, ha chocado en el eje Y
			salto = 0;
			colPos.x = getSprite()->getPosX();
			colPos.y = m->getCollision(getSprite()->getSprite())->getGlobalBounds().top+m->getCollision(getSprite()->getSprite())->getLocalBounds().height+getSprite()->getSprite()->getLocalBounds().height/2;
        	getSprite()->setPosition(colPos);
		}
	}

	for(unsigned int i = 0; i < armas.size(); i++){

		armas.at(i)->setDatosJugador(getPosX(), getPosY(), mirandoDerecha());
		armas.at(i)->update(deltaTime, m);
	}

	//Evita que pueda salir del mapa
	float posLadoDerecho = getPosX() - getSprite()->getSprite()->getGlobalBounds().width / 2;
	float posLadoIzquierdo = getPosX() + getSprite()->getSprite()->getGlobalBounds().width / 2;

	if(posLadoDerecho < 0)
		getSprite()->setPosition(getLastPosition());

	if(posLadoIzquierdo > m->getWidth() * m->getTileWidth() && next == false)
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

	animacion.Update(row, deltaTime, faceRight);
	spr->cambiarPosTextura(animacion.uvRect.left,animacion.uvRect.top,animacion.uvRect.width,animacion.uvRect.height);
	//Si se cae por un hueco muere
	if(getPosY() > m->getHeight() * m->getTileHeight())
		setVida(0);
	
	pos.setPosition(spr->getPosX(), spr->getPosY());

	//UPDATE HUD
	char* c1 = new char();
	sprintf(c1, "%d", monedero);//Convierte int a char*
	s = c1; //Pasa char* a string
	money->setString(s);

	char* c2 = new char();
	sprintf(c1, "%d", getArmaEquipada()->getMunicionAct());//Convierte int a char*
	sprintf(c2, "%d", getArmaEquipada()->getMunicionMax());
	s = " ";//Pasa char* a string
	if(arma_actual==0){
		s.append("INF");
		ammoType = new M_Sprite("spritesheet_otros.png",32,0,16,8,10,10);
	}
	else{
	s.append(c1); s.append("/"); s.append(c2);
	}
	ammo->setString(s);

	if(armas[arma_actual]->getTipo() == "arco"){//ARCO
		ammoType = new M_Sprite("spritesheet_otros.png",0,0,32,10,10,10);
	}else if(armas[arma_actual]->getTipo() == "laser"){//LASER
		ammoType = new M_Sprite("spritesheet_otros.png",48,0,24,4,10,10);
	}else if(armas[arma_actual]->getTipo() == "lanzallamas"){//LANZALLAMAS
		ammoType = new M_Sprite("spritesheet_otros.png",73,0,28,23,10,10);
	}
	s = " ";
	sprintf(c1, "%d", getVida());//Convierte int a char*
	sprintf(c2, "%d", getVidaMax());
	s.append(c1); s.append("/"); s.append(c2);
	life->setString(s);

	s = " ";
	sprintf(c1, "%d", getArmadura());//Convierte int a char*
	s.append(c1);
	armor->setString(s);
}

int Player::getDmg(){

	return dmg;
}

Arma* Player::getArmaEquipada(){

	return armas.at(arma_actual);
}

int Player::getIntArmaActual(){

	return arma_actual;
}



bool Player::consigoDinero(Moneda* moneda){

	if(this->getSprite()->intersects(moneda->getSprite())){

		monedero += moneda->getValor();

		return true;
	}

	return false;
}

bool Player::consigoMejora(Mejora* mejora){

	if(this->getSprite()->intersects(mejora->getSprite()) && mejora->getObtenible()){

		if(mejora->getTipo() == 0){

			if(*vidaMax == 500){

				aumentarDinero(200);   //Si tienes la caracteristica al maximo, te da dinero.
			}

			else{

				incrementarVida();
			}
		}

		else if(mejora -> getTipo() == 1){

			int arma_mejorar = this->compruebaMunicionArmas();

			if(arma_mejorar == -1 && armas.size() == 4){

				aumentarDinero(200);   //Si tienes la caracteristica al maximo, te da dinero.
			}

			else{

				if(arma_actual == 0 && armas.size() > 1){

					int muncMaxMejorar = armas.at(arma_mejorar) -> getMunicionMax();
					armas.at(arma_mejorar)->setMunicionMax(muncMaxMejorar + 50);	
				}

				else{

					if(arma_actual != 0){

						int muncMaxActual = armas.at(arma_actual) -> getMunicionMax();
						int muncMaxMejorar = armas.at(arma_mejorar) -> getMunicionMax();

						if(muncMaxActual == 300){

							armas.at(arma_mejorar)->setMunicionMax(muncMaxMejorar + 50);
						}

						else{

							armas.at(arma_actual)->setMunicionMax(muncMaxActual + 50);
						}
					}

					else{

						aumentarDinero(50);
					}
				}

			}

		}

		else{

			if(*armadura == 100){

				aumentarDinero(200);   //Si tienes la caracteristica al maximo, te da dinero.
			}

			else{

				incrementarArmadura();
			}
		}

		return true;
	}

	return false;

}

int Player::compruebaMunicionArmas(){

	int indice_arma = 0;
	int munc_menor = 0;

	for(unsigned int i = 1; i < armas.size(); i++){  //Empieza desde 1 porque ignora el rayo.

		if(armas.at(i)->getMunicionMax() < 300){

			if(munc_menor == 0){

				munc_menor = armas.at(i)->getMunicionMax();
				indice_arma = i;
			}

			else{

				if(munc_menor > armas.at(i)->getMunicionMax()){

					munc_menor = armas.at(i)->getMunicionMax();
					indice_arma = i;
				}
			}
		}
	}

	if(munc_menor == 0){

		indice_arma = -1;
	}


	return indice_arma;
}



int Player::getDinero(){

	return monedero;
}

void Player::quitarDinero(int cantidad){

	monedero = monedero - cantidad;
}

void Player::aumentarDinero(int cantidad){

	monedero += cantidad;
}

bool Player::tengoArma(string tipo){

	Arma* arma = devuelvoArma(tipo);

	if(arma != 0){

		return true;
	}

	else{

		return false;
	}

}

void Player::consigoArma(string tipo){

	if(tipo == "arco" && !tengoArma(tipo)){

		Arma* arco = new Arco(getPosX(), getPosY(), mirandoDerecha());
		armas.push_back(arco);
	}

	else if(tipo == "laser" && !tengoArma(tipo)){

		Arma* laser = new Laser(getPosX(), getPosY(), mirandoDerecha());
		armas.push_back(laser);
	}

	else if(tipo == "lanzallamas" && !tengoArma(tipo)){

		Arma* lanzallamas = new Lanzallamas(getPosX(), getPosY(), mirandoDerecha());
		armas.push_back(lanzallamas);
	}
}

void Player::mejoroArma(string tipo){

	Arma* arma = devuelvoArma(tipo);

	if(arma != 0){

		arma->mejorar();
	}
}

Arma* Player::devuelvoArma(string tipo){

	

	for(unsigned int i = 0; i < armas.size(); i++){

		if(armas.at(i)->getTipo() == tipo){

			return armas.at(i);
		}
	}

	return 0;
}

void Player::recargoMunicion(){

	for(unsigned int i = 1; i < armas.size(); i++){

		armas.at(i)->recargaArma();
	}
}

int Player::numArmasEquipadas(){

	return armas.size();
}

bool Player::todasArmasCargadas(){

	for(unsigned int i = 1; i < armas.size(); i++){

		if(armas.at(i)->getMunicionAct() < armas.at(i)->getMunicionMax()){

			return false;
		}
	}

	return true;
}

void Player::incrementarArmadura(){

	*armadura += 5;
}

void Player::incrementarVida(){

	*vidaMax += 50;
	*vida = *vidaMax;
}

bool Player::superado(){
	
	return next;
}

void Player::noSuperado(){

	next = false;
}

void Player::setDmg(int d){

	dmg = d;
}

int Player::mirandoDerecha(){

	if(faceRight) return 1;
	else return -1;
}

void Player::checkEnemyColision(vector<NPC*> enemigos){
	for(int i = 0; i < (int)enemigos.size(); i++){
		if(spr->getSprite()->getGlobalBounds().intersects(enemigos.at(i)->getSprite()->getSprite()->getGlobalBounds())){
			if(enemigos.at(i)->puedoAtacar())
				this->reciboDmg(enemigos.at(i)->getAtaque());
		}

		if(enemigos.at(i)->colisionBala(spr))
			this->reciboDmg(enemigos.at(i)->getAtaque());
	}
}

void Player::ataque(){

	armas[arma_actual]->disparo();
}

void Player::renders(M_Window* vent, float percentTick, Map* mapa){

	Vector2D posicion;

    if(dmgColor!=0)
        dmgColor --;
    if(dmgColor==0)
        getSprite()->setColor(0);

    posicion.x = pos.getLastX()*(1-percentTick) + pos.getX()*percentTick;
    posicion.y = pos.getLastY()*(1-percentTick) + pos.getY()*percentTick;

    spr->setPosition(posicion);

	for(unsigned int  i = 0; i < armas.size(); i++){

		armas[i]->render(vent, percentTick);
	}

	vent->renderPlayer(spr, mapa);
}

