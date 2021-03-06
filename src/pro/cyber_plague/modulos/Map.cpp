#include "Map.h"

Map::Map(int nivel) {
      
    TiXmlDocument doc;

    if(nivel == 1){
        if(!doc.LoadFile("resources/MapaNivel1.tmx")){
            std::cout << "Error al cargar el mapa." << std::endl;
        }

        if(!_tilesetTexture.loadFromFile("resources/mapa_1.png")){
            std::cout << "Error al cargar el tileset." << std::endl;
        }
    }
    if(nivel == 2){
        if(!doc.LoadFile("resources/Mapa2.tmx")){
            std::cout << "Error al cargar el mapa." << std::endl;
        }

        if(!_tilesetTexture.loadFromFile("resources/citytiles2.png")){
            std::cout << "Error al cargar el tileset." << std::endl;
        }
    }
    if(nivel == 3){
        if(!doc.LoadFile("resources/Mapa3.tmx")){
            std::cout << "Error al cargar el mapa." << std::endl;
        }

        if(!_tilesetTexture.loadFromFile("resources/mapa3.jpg")){
            std::cout << "Error al cargar el tileset." << std::endl;
        }
    }
    

    TiXmlElement* map = doc.FirstChildElement("map");

    
    //Tamanio del mapa y de los tiles
    map->QueryIntAttribute("width",&_width);
    map->QueryIntAttribute("height",&_height);
    map->QueryIntAttribute("tilewidth",&_tilewidth);
    map->QueryIntAttribute("tileheight",&_tileheigth);

    //Cogemos el punto de Spawn del Jugador.
    map->QueryFloatAttribute("spawnPointX",&_spawnPointX);
    map->QueryFloatAttribute("spawnPointY",&_spawnPointY);
    
    //Leemos los tilesets
    TiXmlElement *img = map->FirstChildElement("tileset");//->FirstChildElement("image");  
    const char* filename = img->Attribute("source");
   
    
    //Leemos diferentes capas
    map->FirstChildElement("layer");
    TiXmlElement *layer = map->FirstChildElement("layer");
    _numlayers=0;
    while(layer){
        _numlayers++;
        layer= layer->NextSiblingElement("layer");
    } 
    
    
    //Reserva de memoria
    _tilemap=new int**[_numlayers];
    for(int i=0; i<_numlayers; i++){
        _tilemap[i]=new int*[_height];
    }
    
    for(int l=0; l<_numlayers; l++){
        for(int y=0; y<_height; y++){
            _tilemap[l][y]=new int[_width];
        }
    }

    layer = map->FirstChildElement("layer");
    string *name=new string[_numlayers];
    int j=0;
       
    //Leo los tiles
            for(int l=0;l<_numlayers;l++){
                TiXmlElement *data= layer->FirstChildElement("data")->FirstChildElement("tile");
                name[j]= (string)layer->Attribute("name");
                for(int y=0; y<_height; y++){
                    for(int x=0; x<_width;x++){
                        data->QueryIntAttribute("gid",&_tilemap[l][y][x]);
                        data=data->NextSiblingElement("tile");
                    }
                }
            layer= layer->NextSiblingElement("layer");    
            j++;

            }
      
    //Reserva de memoria para los sprites
    _tilemapSprite=new sf::Sprite***[_numlayers];
      
    for(int l=0; l<_numlayers; l++){
        _tilemapSprite[l]=new sf::Sprite**[_height];
    }
    
      
    for(int l=0; l<_numlayers; l++){
        for(int y=0; y<_height; y++){
            _tilemapSprite[l][y]= new sf::Sprite*[_width];
            for(int x=0; x<_width; x++){
                _tilemapSprite[l][y][x]=new sf::Sprite();
            }
        }
    } 
    
    int columns = _tilesetTexture.getSize().x / _tilewidth;
    int rows = _tilesetTexture.getSize().y / _tileheigth;
    
    
    _tilesetSprite =new sf::Sprite[columns*rows];     
    int t=0;
    for(int y=0; y<rows; y++){
        for(int x=0; x<columns;x++){
              _tilesetSprite[t].setTexture(_tilesetTexture);
              _tilesetSprite[t].setTextureRect(sf::IntRect(x*_tilewidth,y*_tileheigth,_tilewidth,_tileheigth));
              t++;
        }
    }
    
    //Carga de Sprites 
    for(int l=0; l<_numlayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width;x++){
                int gid=_tilemap[l][y][x]-1;
                if(gid>=rows*columns){ //Si entra, no lo est?? haciendo bien
                   
                }
                else if(gid>0){ //Todo correcto
                    _tilemapSprite[l][y][x]=new sf::Sprite(_tilesetTexture,_tilesetSprite[gid].getTextureRect());
                    _tilemapSprite[l][y][x]->setPosition(x*_tilewidth,y*_tileheigth);
                }
                else{
                    _tilemapSprite[l][y][x]=NULL;
                }
            }
        }
    }
}

void Map::drawTile(sf::RenderWindow *window){

    for(int t=0; t<_numlayers; t++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[t][y][x]!=NULL){
                    window->draw(*(_tilemapSprite[t][y][x]));
                }
            }
        }
    }  
}

void Map::drawPersonaje(sf::RenderWindow *window, Sprite* sp){
    window->draw(*sp);
    for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[3][y][x]!=NULL){
                    window->draw(*(_tilemapSprite[3][y][x]));
                }
            }
        }
}

bool Map::checkCollision(Sprite* sp){
    for(int y=0; y<_height; y++)
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[0][y][x]!=NULL && sp->getGlobalBounds().intersects(_tilemapSprite[0][y][x]->getGlobalBounds()))
                    return true;//Colisiona con algo no atravesable
            }
    return false;
}

Sprite* Map::getCollision(Sprite* sp){
    for(int y=0; y<_height; y++)
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[0][y][x]!=NULL && sp->getGlobalBounds().intersects(_tilemapSprite[0][y][x]->getGlobalBounds()))
                    return _tilemapSprite[0][y][x];//Sprite que colisiona con player
            }
    return NULL;//Devuelve null en caso contrario
}

bool Map::checkCollision(int x, int y){
    if(x > -1 && x < _width && y > - 1 && y < _height && _tilemapSprite[0][y][x] == NULL)
        return false;

    return true;
}

bool Map::checkCaida(Sprite *sp){
    //Posicion del npc en la matriz de tiles
    int x = ceil(sp->getPosition().x / _tilewidth) - 1;
    int y = ceil(sp->getPosition().y / _tileheigth) - 1;

    if(sp->getScale().x > 0){
        if(x + 1 >= _width || _tilemapSprite[0][y + 1][x] == NULL || _tilemapSprite[0][y][x + 1] != NULL || _tilemapSprite[0][y - 1][x + 1] != NULL)
            return true;
    }
    else{
        if(x - 1 < 0 || _tilemapSprite[0][y + 1][x] == NULL || _tilemapSprite[0][y][x - 1] != NULL || _tilemapSprite[0][y - 1][x - 1] != NULL)
            return true;
    }

    return false;
}

Map::~Map() {
}

Vector2D Map::getSpawnPoint(){

    Vector2D spawn;
    spawn.x = _spawnPointX * _tilewidth;
    spawn.y = _spawnPointY * _tileheigth;

    return spawn;
}
