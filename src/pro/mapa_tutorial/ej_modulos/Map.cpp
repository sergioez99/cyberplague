#include "Map.h"

Map::Map(int nivel) {
      
    TiXmlDocument doc;

    if(nivel == 1){
        if(!doc.LoadFile("assets/map.tmx")){
        std::cout << "Error al cargar el mapa." << std::endl;
        }
    }else{
        if(!doc.LoadFile("assets/mapaTutorial.tmx")){
        std::cout << "Error al cargar el mapa." << std::endl;
        }
    }

     TiXmlElement* map = doc.FirstChildElement("map");

    
    //Tamanio del mapa y de los tiles
    map->QueryIntAttribute("width",&_width);
    map->QueryIntAttribute("height",&_height);
    map->QueryIntAttribute("tilewidth",&_tilewidth);
    map->QueryIntAttribute("tileheight",&_tileheigth);
    
    //Leemos los tilesets
    TiXmlElement *img = map->FirstChildElement("tileset");//->FirstChildElement("image");  
    const char* filename = img->Attribute("source");
    

    if(nivel == 1){
        if(!_tilesetTexture.loadFromFile("assets/celeste.png")){
            std::cout << "Error al cargar el tileset." << std::endl;
        }
    }else{
         if(!_tilesetTexture.loadFromFile("assets/celeste2.png")){
            std::cout << "Error al cargar el tileset." << std::endl;
        }
    }
    
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
    int l=0;
       
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
                if(gid>=rows*columns){ //Si entra, no lo está haciendo bien
                   
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

Map::~Map() {
}


/* bool Map::checkColision(int tx, int ty){       
    bool hay = false;
    if  (_tilemap[0][ty][tx]!=71 && _tilemap[0][ty][tx]!=2 
        && _tilemap[0][ty][tx]!=3 && _tilemap[0][ty][tx]!=1 
        && _tilemap[0][ty][tx]!=23 && _tilemap[0][ty][tx]!=24){
        hay = true;
    }
    return hay;
}

bool Map::checkPinchos(int tx, int ty){
    bool hay = false;
    if(_tilemap[0][ty][tx]==45){
        hay = true;
    }
    return hay;
}

void Map::colocarEnemigos(){
    for(int l=0; l<_numlayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width;x++){
                // PRUEBA
                if(_tilemap[l][y][x] == 1){       // solo anda
                    coord_enemy1.push_back(sf::Vector2f(x, y));
                }
                if(_tilemap[l][y][x] == 2){        // anda y persigue
                    coord_enemy2.push_back(sf::Vector2f(x, y));
                }   
                if(_tilemap[l][y][x] == 3){        // lanza flechas
                    coord_enemy3.push_back(sf::Vector2f(x, y));
                }
                if(_tilemap[l][y][x] == 23){       // dispara y anda    // 23
                    coord_enemy4.push_back(sf::Vector2f(x, y));
                }
                if(_tilemap[l][y][x] == 24){       // persigue y dispara
                    coord_enemy5.push_back(sf::Vector2f(x, y));
                }
            }
        }
    }
}

*/
