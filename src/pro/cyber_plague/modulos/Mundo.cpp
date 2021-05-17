#include "CyberPlague.h"
#include "../include/includes.h"

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

    // Canciones

    // Canción mapa 1
    mapa1.openFromFile("./audio/Mapa1.ogg");
    mapa1.setVolume(40);
    mapa1.setLoop(true);

    // Canción mapa 2
    mapa2.openFromFile("./audio/Mapa2.ogg");
    mapa2.setVolume(40);
    mapa2.setLoop(true);

    // Canción mapa 3
    mapa3.openFromFile("./audio/Mapa3.ogg");
    mapa3.setVolume(40);
    mapa3.setLoop(true);

    vector<NPC *> enemigos;
    vector<Cofre*> cofres;
    

    if(lvl == 1){
        mapa1.play();

        NPC *zom = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 900, 365);
        NPC* sold = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 1200, 365);
        enemigos.push_back(zom);
        enemigos.push_back(sold);

        Cofre* cofre1 = new Cofre(1000, 365);
        cofres.push_back(cofre1);
    }
    else if(lvl == 2){
        mapa2.play();

        NPC* sold = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 400, 365);
        NPC *zom = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 1200, 236);
        NPC* sold2 = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 1920, 396);
        NPC* sold3 = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 3424, 365);
        NPC *zom2 = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 3424, 236);
        NPC *zom3 = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 3104, 365);
        enemigos.push_back(sold);
        enemigos.push_back(zom);
        enemigos.push_back(sold2);
        enemigos.push_back(sold3);
        enemigos.push_back(zom2);
        enemigos.push_back(zom3);

        Cofre* cofre1 = new Cofre(544, 270);
        Cofre* cofre2 = new Cofre(2916, 333);
        cofres.push_back(cofre1);
        cofres.push_back(cofre2);
    }
    else{
        mapa3.play();

        NPC* sold = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 1000, 333);
        NPC* sold2 = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 1850, 365);
        NPC *zom = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 2050, 204);
        NPC *zom2 = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 2550, 204);
        NPC* sold3 = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 3500, 365);
        NPC *zom3 = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 3732, 365);
        NPC *zom4 = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 4112, 332);
        NPC* sold4 = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 4544, 300);
        NPC *zom5 = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 4832, 332);
        NPC *zom6 = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 5504, 172);
        enemigos.push_back(sold);
        enemigos.push_back(sold2);
        enemigos.push_back(zom);
        enemigos.push_back(zom2);
        enemigos.push_back(sold3);
        enemigos.push_back(zom3);
        enemigos.push_back(zom4);
        enemigos.push_back(sold4);
        enemigos.push_back(zom5);
        enemigos.push_back(zom6);

        Cofre* cofre1 = new Cofre(1300, 333);
        Cofre* cofre2 = new Cofre(3000, 333);
        Cofre* cofre3 = new Cofre(4112, 237);
        Cofre* cofre4 = new Cofre(5136, 365);
        cofres.push_back(cofre1);
        cofres.push_back(cofre2);
        cofres.push_back(cofre3);
        cofres.push_back(cofre4);
    }

    player->setPosition(mapa->getSpawnPoint());
    player->noSuperado();
    player->setPosHUD(camara->getView()->getCenter().x,camara->getView()->getCenter().y);

    Clock clock;
    Clock clock2;
   
    vector<Moneda *> monedasNivel;

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
                    cout << "HE MUERTO" << endl;
                    camara->reset(0.f, 0.f, 640, 480);
                    vent->setView(camara);
                    Menu::Instance(CyberPlague::Instance(), vent, 4)->Handle();
                }

                if(player->superado()){
                    mapa1.stop();
                    mapa2.stop();
                    mapa3.stop();

                    for (int i = 0; i < (int)enemigos.size(); i++){
                        delete enemigos.at(i);
                        enemigos.erase(enemigos.begin() + i);
                    }

                    for (int i = 0; i < (int)cofres.size(); i++){
                        delete cofres.at(i);
                        cofres.erase(cofres.begin() + i);
                    }

                    if(lvl > 3){
                        //Si acaba el juego vuelve al menú principal
                        Menu::Instance(CyberPlague::Instance(), vent, 1);
                    }else{
                        Mundo::Instance(CyberPlague::Instance(), vent, lvl+1)->Handle();
                    }

                   
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
                    case -1:
                        camara->reset(0.f, 0.f, 640, 480);
                        vent->setView(camara);
                        Menu::Instance(CyberPlague::Instance(), vent, 0)->Handle();
                    break;
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
