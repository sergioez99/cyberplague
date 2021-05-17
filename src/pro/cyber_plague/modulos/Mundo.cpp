#include "CyberPlague.h"
#include "../include/includes.h"
#include <SFML/Audio.hpp>

#define kUpdateTimePS 1000/15

Mundo *Mundo::pinstance = 0;
Mundo *Mundo::Instance(CyberPlague *context, M_Window *w, int nivel)
{
    pinstance = new Mundo(context, w, nivel);
    return pinstance;
}

Mundo::Mundo(CyberPlague *context, M_Window *w, int nivel)
{
    vent = w;
    _context = context;
    lvl = nivel;

    player = _context->getPlayer();

    pmenu = new MenuPausa(w);
}

void Mundo::Handle()
{
    _context->cambiarEstado(this); //Al hacer Handle, se activa este estado en el contexto.
}
void Mundo::Update()
{
    _context = _context;
}

void Mundo::Init()
{
    M_View *camara = new M_View(0, 0, 640, 480);
    mapa = new Map(lvl);

    pausado = false;
    fondo = new M_Sprite("Fondo.jpg",0, 0, 640, 480,320, 240);


    player->setPosition(mapa->getSpawnPoint());
    player->noSuperado();
    player->setPosHUD(camara->getView()->getCenter().x,camara->getView()->getCenter().y);

    Clock clock;
    Clock clock2;

    NPC *zom = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 890, 364);
    NPC* sold = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 1200, 365);

    vector<NPC *> enemigos;
    vector<Moneda *> monedasNivel;


    enemigos.push_back(zom);
    enemigos.push_back(sold);

    vector<Cofre*> cofres;
    Cofre* cofre1 = new Cofre(1000, 365);

    cofres.push_back(cofre1);
    
    vector<bool> key;

    Time timeStartUpdate = clock.getElapsedTime();

    //Bucle juego
    while (vent->abierta())
    {

        //cout << M_Input::getKeys() << endl;

        if(pausado==false){
            string key = M_Input::InputController();

            if(key == "ESCAPE"){            
            // Menu::Instance(CyberPlague::Instance(), vent, lvl)->Handle();
                pausado=true;        
            }
        }

        if(pausado==false){
            if (clock.getElapsedTime().asMilliseconds() - timeStartUpdate.asMilliseconds() > kUpdateTimePS)
            {
                Vector2D playerPos;

                float deltaTime = clock2.restart().asSeconds();

                playerPos.x=player->getPosInterpolada().getX();
                playerPos.y=player->getPosInterpolada().getY();
                player->setPosition(playerPos);//Fuerza a la posicion donde deberia estar ya.

                //Gravedad
                player->update(deltaTime, mapa);

                //Aqui habra que cambiar de State
                if(player->muerto()){

                   /* player->vivo();       ESTO HABRIA QUE ARREGLARLO UN POCO MAS, DA PROBLEMAS.
                    Menu::Instance(CyberPlague::Instance(), vent, lvl)->Handle();*/
                }
                

                if(player->superado()){
                    Mundo::Instance(CyberPlague::Instance(), vent, lvl+1)->Handle();
                }

                //Colisiones entre NPCs
                for(int i = 0; i < (int)enemigos.size(); i++){
                    for(int j = i + 1; j < (int)enemigos.size(); j++)
                        enemigos.at(i)->colision(deltaTime, enemigos.at(j));
                }

                //Updates antes de los renders o el personaje vibra por las colisiones.

                for (int i = 0; i < (int)enemigos.size(); i++)
                {
                    player->getArmaEquipada()->balaImpactada(enemigos.at(i));
                    enemigos.at(i)->update(deltaTime, mapa, player->getSprite());

                    if (enemigos.at(i)->muerto())
                    {

                        Moneda* coin = enemigos.at(i)->looteoMoneda();
                        
                        if(coin != 0){

                            monedasNivel.push_back(enemigos.at(i)->looteoMoneda());
                        }

                        enemigos.erase(enemigos.begin() + i);
                    }

                }

                for(unsigned int i = 0; i < monedasNivel.size(); i++){

                    if(player->consigoDinero(monedasNivel.at(i))){

                        monedasNivel.erase(monedasNivel.begin() + i);
                    }

                }


                for(unsigned int i = 0; i < cofres.size(); i++){

                    player->getArmaEquipada()->balaImpactada(cofres.at(i));
                    cofres.at(i)->update();
                    
                    if(player->consigoMejora(cofres.at(i)->getMejora())){

                        cofres.erase(cofres.begin() + i);
                    }
                }

                player->checkEnemyColision(enemigos);

                timeStartUpdate = clock.getElapsedTime();
            }           
        } else {
            int compra = pmenu->update(player->getDinero());
            if(compra!=0){
                switch(compra){
                    case 1:
                        
                        player->quitarDinero(50);
                        player->consigoArma("arco");
                    break;
                    case 2:

                        player->quitarDinero(100);
                        player->consigoArma("laser");
                    break;
                    case 3:
                        
                        player->quitarDinero(200);
                        player->consigoArma("lanzallamas");
                    break;

                    case 4:

                        player->quitarDinero(200);
                        player->mejoroArma("arco");
                    break;

                    case 5:

                        player->quitarDinero(200);
                        player->mejoroArma("laser");
                    break;

                        
                    case 6:

                        player->quitarDinero(200);
                        player->mejoroArma("lanzallamas");
                    break;

                    case 7:

                        //SI EL JUGADOR TIENE SOLO EL RAYO O TIENE TODAS LAS ARMAS CARGADAS, NO LO COMPRA.
                        if(player->numArmasEquipadas() > 1 || !player->todasArmasCargadas()){ 

                            player->quitarDinero(20);
                            player->recargoMunicion();
                        }
 
                    break;
                    case 8:

                        if(player->getArmadura() < 100){  //SI EL JUGADOR TIENE 100 (EL MAXIMO) DE ARMADURA, NO LA COMPRA.

                            player->quitarDinero(50);
                            player->incrementarArmadura();
                        }

                    break;

                    case 9:

                        if(player->getVidaMax() < 500){ //SI EL JUGADOR TIENE 500 (EL MAXIMO) DE VIDA, NO LA COMPRA.

                            player->quitarDinero(100);
                            player->incrementarVida();
                        }
                        
                    break;        
                }
            }
        }

        if(pausado==true){
            clock2.restart();
            vent->limpiar();
            Vector2D posicion;
            posicion.x = camara->getView()->getCenter().x;
            posicion.y = 240;
            fondo->setPosition(posicion);
            vent->render(fondo);
            pausado = pmenu->render(camara->getView());
        }else{

        float percentTick = min(1.f, clock2.getElapsedTime().asMilliseconds() / (float)(kUpdateTimePS));
        vent->limpiar();
        mapa->drawTile(vent->getWindow());

        for(unsigned int i = 0; i < cofres.size(); i++){

            cofres.at(i)->render(vent);
        }

        for (unsigned int i = 0; i < enemigos.size(); i++)
        {
            enemigos.at(i)->render(vent, percentTick);
        }

        for(unsigned int i = 0; i < monedasNivel.size(); i++){

            monedasNivel.at(i)->render(vent);
        }
            
            player->renders(vent, percentTick, mapa);
            player->renderHUD(vent, camara->getView());

            //Mover camara
            if (player->getPosX() < 320.0f)
                camara->reset(0.f, 0.f, 640, 480);
            if (player->getPosX() >= 320.0f && player->getPosX() < mapa->getWidth() * mapa->getTileWidth() - 320.0f)
                camara->reset(player->getPosX() - 320.f, 0.f, 640, 480);
            if (player->getPosX() >= mapa->getWidth() * mapa->getTileWidth() - 320.0f)
                camara->reset((float)mapa->getWidth() * mapa->getTileWidth() - 640.0f, 0.f, 640, 480);

            vent->setView(camara);
            vent->display();
        }     
    }

    delete fondo;

    delete vent;
    delete camara;

    for (int i = 0; i < (int)enemigos.size(); i++)
        delete enemigos.at(i);
}

void Mundo::Render()
{
    //Podemos trasladar los renders y updates que se vean convenientes aquí.
}
