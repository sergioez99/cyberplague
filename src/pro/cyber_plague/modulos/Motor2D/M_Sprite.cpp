#include "M_Sprite.h"


//Constructor
M_Sprite::M_Sprite(string nomFichero, int texLeft, int texTop, int tex_width, int tex_height, float posX, float posY){

    Texture *tex = new Texture();

    if (!tex->loadFromFile("resources/" + nomFichero)) {
      std::cerr << "Error cargando la imagen sprites.png";
      exit(0);
    }

    sprite = new Sprite(*tex);

    sprite->setOrigin(tex_width / 2, tex_height / 2);
    sprite->setTextureRect(IntRect(texLeft, texTop, tex_width, tex_height));
    sprite->setPosition(posX, posY);
}

//Destructor
M_Sprite::~M_Sprite(){

    delete sprite;
}

void M_Sprite::cambiarPosTextura(int posLeft, int posTop, int width, int height){

    sprite->setTextureRect(IntRect(posLeft, posTop, width, height));
}

void M_Sprite::rotar(float ang){

    sprite->rotate(ang);
}

void M_Sprite::mover(float x, float y){

    sprite->move(x, y);
}

void M_Sprite::escalar(float x, float y){

    sprite->scale(x, y);
}

bool M_Sprite::intersects(M_Sprite* spr){

    return sprite->getGlobalBounds().intersects(spr->getSprite()->getGlobalBounds());
}

void M_Sprite::setColor(int i){
    switch (i)
    {
    case 1:
        sprite->setColor(sf::Color::Red);
        break;
    
    
    default:
        sprite->setColor(sf::Color::White);
        break;
    }
}

//Metodos Setters y Getters
//NO USAR ESTO. DEBUG.
Sprite* M_Sprite::getSprite(){

    return sprite;
}

float M_Sprite::getPosX(){
    return sprite->getPosition().x;
}

float M_Sprite::getPosY(){
    return sprite->getPosition().y;
}

Vector2D M_Sprite::getScale(){

    Vector2D escala;

    escala.x = sprite->getScale().x;
    escala.y = sprite->getScale().y;

    return escala;
}

float M_Sprite::getRotation(){

    return sprite->getRotation();
}

void M_Sprite::setPosition(Vector2D pos){
    sprite->setPosition(pos.x,pos.y);
}