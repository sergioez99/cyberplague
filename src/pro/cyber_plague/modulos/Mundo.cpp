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

    pausado=false;
    fondo = new M_Sprite("Fondo.jpg",0, 0, 640, 480,320, 240);

    //Cargo la imagen donde reside la textura del sprite protagonista
    sf::Texture playerTexture;
    playerTexture.loadFromFile("resources/Union 3e.png");

    Player player(&playerTexture, sf::Vector2u(8, 3), 0.15f, 250.0f);

    player.setPosHUD(camara->getView()->getCenter().x,camara->getView()->getCenter().y);

    Clock clock;
    Clock clock2;

    //NPC* mago = new Mago("sprites.png", 0*75, 0*75, 75, 75, 640/4, 480/2);
    //NPC* paj = new Pajaro("sprites.png", 1*75, 0*75, 75, 75, 640/4, 480/4);
    //NPC* sold = new Soldado("sprites.png", 2.3*75, 0*75, 75, 75, 640/6, 480/6);
    NPC *zom = new Zombi("Zombie24x40.png", 0, 0, 24, 40, 900, 365);
    NPC* sold = new Soldado("Soldier36x40.png", 0, 0, 36, 40, 1200, 365);
    //arc->mejorar();

    vector<NPC *> enemigos;
    vector<Moneda *> monedasNivel;
    //enemigos.push_back(mago);
    //enemigos.push_back(paj);
    //enemigos.push_back(sold);
    enemigos.push_back(zom);
    enemigos.push_back(sold);

    vector<Cofre*> cofres;
    Cofre* cofre1 = new Cofre(1000, 365);

    cofres.push_back(cofre1);


    Map *tutorial = new Map(lvl);

    vector<bool> key;

    Time timeStartUpdate = clock.getElapsedTime();

    //Bucle juego
    while (vent->abierta())
    {

        cout << M_Input::getKeys() << endl;

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
                playerPos.x=player.getPosInterpolada().getX();
                playerPos.y=player.getPosInterpolada().getY();
                player.getSprite()->setPosition(playerPos);//Fuerza a la posicion donde deberia estar ya.
                //Gravedad
                player.update(deltaTime, tutorial);

                //Aqui habra que cambiar de State
                if(player.muerto())
                    cout << "HE MUERTO" << endl;

                if(player.superado()){
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
                    player.getArmaEquipada()->balaImpactada(enemigos.at(i));
                    enemigos.at(i)->update(deltaTime, tutorial);

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

                    if(player.consigoDinero(monedasNivel.at(i))){

                        monedasNivel.erase(monedasNivel.begin() + i);
                    }

                }


                for(unsigned int i = 0; i < cofres.size(); i++){

                    player.getArmaEquipada()->balaImpactada(cofres.at(i));
                    cofres.at(i)->update();
                    
                    if(player.consigoMejora(cofres.at(i)->getMejora())){

                        cofres.erase(cofres.begin() + i);
                    }
                }

                timeStartUpdate = clock.getElapsedTime();
            }           
        } else {
            int compra = pmenu->update(player.getDinero());  //Entra a la tienda con 100, aqui hay que poner la cantidad de monedas
            if(compra!=0){
                switch(compra){
                    case 1:
                        
                        player.quitarDinero(50);
                        player.consigoArma("arco");
                    break;
                    case 2:

                        player.quitarDinero(100);
                        player.consigoArma("laser");
                    break;
                    case 3:
                        
                        player.quitarDinero(200);
                        player.consigoArma("lanzallamas");
                    break;

                    case 4:

                        player.quitarDinero(200);
                        player.mejoroArma("arco");
                    break;

                    case 5:

                        player.quitarDinero(200);
                        player.mejoroArma("laser");
                    break;

                        
                    case 6:

                        player.quitarDinero(200);
                        player.mejoroArma("lanzallamas");
                    break;

                    case 7:

                        //SI EL JUGADOR TIENE SOLO EL RAYO O TIENE TODAS LAS ARMAS CARGADAS, NO LO COMPRA.
                        if(player.numArmasEquipadas() > 1 || !player.todasArmasCargadas()){ 

                            player.quitarDinero(20);
                            player.recargoMunicion();
                        }
 
                    break;
                    case 8:

                        if(player.getArmadura() < 100){  //SI EL JUGADOR TIENE 100 (EL MAXIMO) DE ARMADURA, NO LA COMPRA.

                            player.quitarDinero(50);
                            player.incrementarArmadura();
                        }

                    break;

                    case 9:

                        if(player.getVidaMax() < 500){ //SI EL JUGADOR TIENE 500 (EL MAXIMO) DE VIDA, NO LA COMPRA.

                            player.quitarDinero(100);
                            player.incrementarVida();
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
        tutorial->drawTile(vent->getWindow());

        for(unsigned int i = 0; i < cofres.size(); i++){

            cofres.at(i)->render(vent);
        }

        for (unsigned int i = 0; i < enemigos.size(); i++)
        {
                enemigos.at(i)->render(vent, percentTick); //Renderiza todos los personajes por ahora
            }

            for(unsigned int i = 0; i < monedasNivel.size(); i++){

                monedasNivel.at(i)->render(vent);
            }
            
            player.renders(vent, percentTick, tutorial);
            player.renderHUD(vent, camara->getView());

            //Mover camara
            if (player.getPosX() < 320.0f)
                camara->reset(0.f, 0.f, 640, 480);
            if (player.getPosX() >= 320.0f && player.getPosX() < tutorial->getWidth() * tutorial->getTileWidth() - 320.0f)
                camara->reset(player.getPosX() - 320.f, 0.f, 640, 480);
            if (player.getPosX() >= tutorial->getWidth() * tutorial->getTileWidth() - 320.0f)
                camara->reset((float)tutorial->getWidth() * tutorial->getTileWidth() - 640.0f, 0.f, 640, 480);

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
