#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Motor2D/M_Sprite.h>
#include <sstream>
#include "TinyXML/tinystr.h"
#include "TinyXML/tinyxml.h"
#include <string>
#include <cmath>


using namespace std;
using namespace sf;

class Map {
    
public:
    
    Map(int nivel);
    void drawTile(sf::RenderWindow *window);
    virtual ~Map();
    sf::Sprite**** getTileMap()     { return _tilemapSprite;    };
    int getWidth()                  { return _width;            };
    int getHeight()                 { return _height;           };
    int getTileWidth()              { return _tilewidth;        };
    int getTileHeight()             { return _tileheigth;       };

    bool checkCollision(Sprite* sp); //Utilizar RectShapes de sfml para comprobar colisiones
    Sprite* getCollision(Sprite* sp); //Devuelve la colisión que colisiona con el sprite
    bool checkCollision(int x, int y);  //Utilizar para crear el camino en AI_Agent
    bool checkCaida(Sprite *sp);    //Utilizar para el movimiento de Zombi y Soldado
    
    void drawPersonaje(sf::RenderWindow *window, Sprite* sp);

    Vector2D getSpawnPoint();

private:
    //Tilemap
        int _width;
        int _tilewidth;
        sf::Clock reloj;
        
        int ***_tilemap;
        int _numlayers;
        int _height;
        int _tileheigth;
    
        sf::Sprite ****_tilemapSprite;
        sf::Sprite *_tilesetSprite;
        
    
        sf::Texture _tilesetTexture;
        
        float _spawnPointX;
        float _spawnPointY;
};
