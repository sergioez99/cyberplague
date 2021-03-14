#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include "tinystr.h"
#include "tinyxml.h"
#include <string>


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
    
    bool checkColision(int tx, int ty);             // nuevo
    bool checkPinchos(int tx, int ty);             // nuevo
    void colocarEnemigos();                         // nuevo
    std::vector<Vector2f> coord_enemy1;             // nuevo
    std::vector<Vector2f> coord_enemy2;             // nuevo
    std::vector<Vector2f> coord_enemy3;             // nuevo
    std::vector<Vector2f> coord_enemy4;             // nuevo
    std::vector<Vector2f> coord_enemy5;             // nuevo

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
        
        

};