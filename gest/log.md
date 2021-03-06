# Log del trabajo realizado por dia
**El log es obligatorio**

## 20210301 JoseSansano @(53min)
Creación de hitbox básico, borra un sprite al tocarlo.

## 20210323 SergioEspinosa @(30m)
Investigación con Ramón sobre los problemas que tenemos en la creación del Algoritmo A*

## 20210323 RamónRodríguez @(30m)
Investigación con Sergio sobre los problemas que tenemos en la creación del Algoritmo A*

## 20210324 JoseSansano @(1h 30m)
Creación básica de Motor2D y inicialización de la rama, cambiando cosas de CMake, como el nombre del juego y workspace.

## 20210325 RamónRodríguez @(45min)
Trabajo realizado sobre un prototipo de experimental: Solucionado error del Algoritmo A*. Ya devuelve el camino correctamente. El error era que nos los nodos se destruían antes de tiempo y al intentar acceder a ellos para reconstruir el camino valían NULL.

## 20210326 RamónRodríguez @(1h30min)
Trabajo realizado sobre un prototipo de experimental: Implementación de la clase Pájaro y del movimiento de este NPC siguiendo el camino encontrado por el Algoritmo A* de pathfinding.

## 20210328 CarlosVillena @(2h)
Creación preliminar de las fachada, clases M_Sprite y M_Window.

## 20210328 RubénHerrera @(2h 15m)
Unido los menús en un mismo archivo e implementado variable para su manejo.

## 20210329 JoseSansano @(2h 20m)
Creación de la fachada Motor2D con el mismo funcionamiento que en el main anterior(con events, poder mover el personaje, etc.)

## 20210329 RamónRodríguez @(2h5min)
Creación preliminar de las clases NPC, Zombi, Soldado, Mago y Pajaro.

## 20210330 SergioEspinosa @(1h)
Añadida la clase Mapa a developer y creada una carpeta para la librería TinyXML usada para el cargador de mapas. Añadida la clase Juego (CyberPlague) la cual creará el juego con el patrón State. Tiene código pero no funciona todavía.

## 20210401 RamónRodríguez @(1h)
Añadidos los métodos update y render a la clase NPC y actualizados los métodos update de cada tipo de NPC.

## 20210403 CarlosVillena @(3h)
Creación de la clase Entidad, ajustes en los NPCs para adaptarlos a la clase Entidad. Creación del deltatime en la clase M_Window.

## 20210406 RamónRodríguez @(1h10min)
Creación de la clase AI_Agent, encargada de obtener un camino a recorrer usando el Algoritmo A*. Falta que tenga en cuenta las colisiones.

## 20210408 JoseSansano @(1h 45m)
Modificación del metodo KeyPresed de ventana e integración de la clase Map al Main del proyecto(antes estaba, pero con errores y no se buildeaba con Cmake).

## 20210408 SergioEspinosa @(3h)
Reunión con el grupo para organizar trabajo, uso de view en el mapa antiguo con el que me he dado cuenta de que dibujaba mal por el uso de dos tileset diferentes que se solapan al bindear la textura con el sprite, se ha intentado arreglar pero decido fusionar los tileset, porque con un tileset el mapa si pinta bien.

## 20210409 SergioEspinosa @(1h 10m)
Nuevo mapa con un tileset que es una fusión de 3 pngs (suelo, arboles y un fondo de cielo), reajuste del mapa para que tenga menos cielo (ya que no vamos a saltar tan alto), creación de capas intermedias para el personaje ya que creo que para las colisiones serán útiles.

## 20210409 JoseSansano @(2h)
Creación de Vector2D para no usar SFML, más getters y setters en M_Sprite/Entidad y prueba de colisiones en el mapa funcional.

## 20210410 CarlosVillena @(3h 30m)
Cambios en los directorios, creación preliminar de las clases de las armas, implementacion de la clase Arco, creación del sprite del proyectil del arco, cambios en los includes, cambio en la clase M_Window para que pueda leer el boton de disparo, el boton de salto y para que detecte que se ha dejado de pulsar el disparo para la futura clase Lanzallamas.

## 20210410 RamónRodríguez @(2h 30m)
Movimiento de Zombi y Soldado por las plataformas sin caerse, ajustes en deltaTime, limitar llamadas a update a 15 veces por segundo y preparar AI_Agent para usar colisiones. He tardado bastante más de lo previsto en hacer esto ya que hice muchas pruebas con el movimiento de Zombi porque no funcionaba correctamente. El problema resultó ser una tonteria y es que la función escalar de M_Sprite no funcionaba como yo esperaba que funcionase, lo que hace es multiplicar el escalado del sprite por los valores que le pases no cambiar su escalado por dichos valores.

## 20210411 RamónRodríguez @(1h 30m)
Añadido a AI_Agent la creación de nodos hijos en función de las colisiones de Map y pseudocódigo de una idea para realizar el movimiento del mapa en función de la posición del jugador (aún le faltan algunos detalles).

## 20210413 JorgeMompe @(2h 20m)
Translado y orden de todo lo desarrollado en la rama experimental a la rama developer. Intento de adaptación de lo hecho a la nueva rama.

## 20210412 JoseSansano @(2h 12m)
Mejora del método KeyInput de M_Window, diferenciando entre pulsaciones de teclas, que es lo que se especializa el sf::Event, de las pulsaciones mantenidas en tiempo real, que es lo que se especializa sf::Keyboard::isKeyPressed. Ahora devuelve un vector de booleanos, siendo cada posición del vector una tecla pulsada, para que se pueda controlar varias teclas pulsadas a la vez en un frame, ya que el juego que estamos haciendo requiere esto.

## 20210412 JoseSansano @(1h)
Físicas básicas. Gravedad aplicada al jugador y salto básico implementado. Ahora Entidad tiene un valor nuevo booleano: Grounded, que indica si esa Entidad esta tocando el suelo o no. El jugador debe estar Grounded para poder saltar. (Y si puede saltar doble, grounded resetearía su contador de saltos disponibles).

## 20210412 RamónRodríguez @(1h 40m)
Añadida clase M_View a la fachada Motor2D para no usar el View de sfml e implementación del movimiento de la cámara. La cámara comenzará a moverse cuando el jugador llegue al centro de la pantalla.

## 20210413 JorgeMompe @(1h)
Intento de cambio del personaje principal por el realizado en la rama experimental en hito anterior.

## 20210413 JoseSansano @(1h 30m)
Actualizado el Player, que ahora hereda de Entidad. Ahora en vez de controlar a un enemigo, el jugador controla la clase Player y todo el input y colision con el mapa que hacia en el main se ha movido a su respectivo update.

## 20210413 CarlosVillena @(3h)
Cambios para que las armas disparen en la posicion del jugador, solucion de un error en la clase Player en donde el tamaño del sprite era mayor al de la animación, eso provocaba que las armas se disparasen muy lejos del jugador.

## 20210414 RamónRodríguez @(2h 30m)
Implementación del render interpolado. Para ello he creado la clase posInterpolada la cual contiene la posición calculada en el update y la posición anterior de cada Entidad. Modificados los métodos update y render de Entidad para que el movimiento del sprite se haga en el render ahora interpolado en vez de en update como estaba antes.

## 20210415 RubénHerrera @(3h)
Añadida las funciones para el patrón state en el menú.

## 20210417 RamónRodríguez @(2h)
Ahora cuando el jugador colisiona con un enemigo, este le ataca y le inflinge daño. También he estado haciendo pruebas con el render interpolado y he comentado todo lo relacionado con él por mal funcionamiento.

## 20210418 RamónRodríguez @(1h 15m)
Los NPC ya colisionan con los proyectiles y cuando lo hacen sufren daño. Si la vida del NPC llega a 0 este muere y ya no aparece en el juego. Si la vida de Player llega 0 muere y de momento no se updatea ni se renderiza, en un futuro aparecerá la típica pantalla indicando que has muerto.

## 20210418 SergioEspinosa @(1h)
Actualizado el log y las tareas, creación de clases Menú y Mundo (estado ingame) con funciones de estado para el patrón state (son clases diferentes a juego ya que heredan de state) 

## 20210418 RubénHerrera @(2h)
Adaptación de la clase menú al patrón fachada para los controles y la vista. He añadido al motor la función para que dibuje texto. Actualizacion de la autoevaliación.

## 20210418 CarlosVillena @(5h)
Creación del resto de armas (excepto Lanzallamas) y ajustes para que funcionen. Creacion preliminar del sistema de municion. He tardado tanto porque habia un problema con la lógica que habia implementada en las armas. En principio ya debería funcionar todo. 

## 20210422 SergioEspinosa @(1h 20m)
He creado una rama aparte para ir implementando los estados. Desde CyberPlague (juego) llamo a Menú y hace el render, pero no pinta nada y lo he dejado ahi hasta que mi compañero Rubén solucione los problemas.

## 20210423 RubenHerrera @(2h 30m)
Arreglado el problema de pintar el texto y añadida nueva función para el control del menú. Ahora se mueve bien pero da saltos de dos en dos.

## 20210426 JoseSansano @(1h 40m)
Mejora del salto para que sea más realista y que no haga el efecto "ascensor". Ahora cuando llega al punto más alto del salto se ralentiza, y cuando llega al suelo no puede saltar inmediatamente, hay un pequeño cooldown entre saltos. Añadidos los porcentajes de notas al master.

## 20210426 SergioEspinosa @(2h 10m)
El personaje ahora se dibuja en su capa, y aparece detrás de los árboles.
Ahora está el menú integrado en develop y se puede jugar el nivel desde nueva partida

## 20210426 RamónRodríguez @(2h 20m)
Render interpolado ya funciona en Player y Zombi, ahora las llamadas a update estan limintadas correctamente, y cambios en el salto para que se ajuste a la limitación de las llamadas a update.
He tardado bastante más de lo previsto ya que he estado como 1h para arreglar el fallo del render interpolado que resultó ser una tonteria. El fallo estaba en el cálculo de percentTick.

## 20210426 RubenHerrera @(1h 30m)
Añadido un nuevo fondo de menu y cambiada la tipografía. Añadida estructura al menú.

## 20210426 RubenHerrera @(1h 30m)
Arreglado bug del fondo (se creaba cada vez que renderizaba) y aparición de bug al pulsar escape en el texto. Lo he arreglado junto a Fidel forzando un exit al pulsar escape.

## 20210427 JoseSansano @(1h 10m)
Arreglado un bug del menu que hacia que la posición X del ratón actuase como "botones" del teclado, activando cosas aunque no pulsases nada, y retocado el salto del personaje.

## 20210428 JoseSansano @(1h 10m)
El personaje ya no se queda flotando en la pared sin caer. Ahora siempre cae. 

## 20210428 RamónRodríguez @(1h 40 m)
Las Armas ya funcionan con el render interpolado y las balas se destruyen al colisionar con el mapa (la función intersects no siempre detecta las colisiones, solo en la parte superior de los obstaculos, no sé por qué).
El personaje ya no puede salir de la pantalla al inicio y al final del mapa y cuando cae por un hueco muere.

## 20210428 SergioEspinosa @(2h 45m)
Solucionados problemas de colision del arma en el mapa 1. He creado un nuevo mapa y lo he implementado, cuando acabe el nivel 1 se pasa directamente y desde la opcion del continuar menú se puede entrar también de momento

## 20210428 CarlosVillena @(3h)
Creacion clase M_Input para manejar la entrada del teclado.

## 20210429 CarlosVillena @(4h)
Cambios en el resto de clases del proyecto para ajustarlos a los inputs. Hacer que el arma se dispare por pulsacion y no por tecla mantenida y el personaje no puede saltar si mantiene la tecla.

## 20210502 CarlosVillena @(2h)
He arreglado un bug en el arco que hacia que la rotacion fallara a veces y no se rotasen las flechas como deberian y ahora las balas de
todas las armas se eliminan cuando pasan cierta distancia.

## 20210503 JoseSansano @(3h 10m)
Retocado el sprite del personaje para que su bounding box no sea tan grande respecto a los pixeles que se ven de él. Animacion cambiada de salto.

## 20210504 JoseSansano @(2h)
El jugador ahora primero comprueba su movimiento en el eje X, y después su movimiento en el eje Y, no todo a la vez. Ahora salta aunque se choque con algo, y si se choca con un techo, pierde la fuerza del salto.

## 20210505 JoseSansano @(2h)
El jugador colisiona perfectamente (sin espacios vacios) siempre, al menos su Bounding Box.

## 20210505 CarlosVillena @(3h)
Lanzallamas creado, y unos pequeños ajustes en el player para mejorar el disparo.

## 20210505 CarlosVillena @(3h)
Sistema de dropeo de monedas creado.

## 20210505 RamónRodríguez @(3h)
Búsqueda de sprite sheets para los NPCs y ajustar los sprites de Soldado con Photoshop.

## 20210506 JoseSansano @(3h)
El jugador poseia un bug que rebotaba en el suelo y mientras andaba iba siempre un frame atrás por el bucle interpolado, ya que este nunca llegaba al final de su posicion(percentTick nunca era 1). Ahora, ese bug esta arreglado con el jugador, forzando antes del player.update, a que su sprite este en la posición que debería estar. Esto también arregla un bug de que cuando saltaba desde una gran altura el personaje, se metía dentro del suelo durante un par de frames. Ahora el jugador funciona perfectamente sin ningún bug de movimiento.

## 20210507 RamónRodríguez @(1h 15m)
Ajuste de los sprites de Zombi con Photoshop.

## 20210509 RubenHerrera @(2h)
Ajustado menú y añadido el menú de pausa. Añadido el escape a los controles y añadido exit al cerrar ya que salía error al limpiar. La pausa no mantiene el estado del juego y hay un bug con la vista del menú cuando mueves el personaje por el mapa.

## 20210510 SergioEspinosa @(1h 20')
Buscando todos los sprites necesarios para el HUD (monedas, armas, vidas), transformando los sprites a png con fondo transparente

## 20210510 RamónRodríguez @(1h 30m)
Animación de los NPCs Zombi y Soldado y pequeños cambios en sus sprite sheets para que se visualicen bien.

## 20210510 JoseSansano @(1h)
Preparar clase Hud

## 20210511 JoseSansano @(3h)
Hud que sigue la View y que muestra por ahora solo las monedas que tiene el personaje.

## 20210511 RubénHerrera @(1h 30m)
Creación con photoshop del fondo para los controles y añadido en el menú.

## 20210512 JoseSansano @(1h)
Ahora hud muestra municion del arma actual y vida del personaje

## 20210512 RubénHerrera @(1h 30m)
Creada clase Menu Pausa. Falta separar los update y render. Aún no funciona.

## 20210513 SergioEspinosa @(1h 40')
Creación del mapa del nivel 3 de temática volcánica. Se puede acceder finalizando el nivel 2 o desde el menú en la opción de nivel 3.

## 20210513 RubénHerrera @(2h 30m)
Añadida pausa. Ahora muestra el menu en la posición correcta y mantiene el estado.

## 20210513 JoseSansano @(2h)
Hud con iconos de vida y municion. Fixeado un bug con las colisiones en las escaleras del sector 2. Al estar chocando seguidamente, subia rápidamente de escalón al entrar dentro de su bounding box. Ahora todas las colisiones en X separan al jugador 4 pixeles para evitar eso.

## 20210513 CarlosVillena @(4h)
Sistema de Cofres Creado.

## 20210513 RamónRodríguez @(1h)
Arreglado un fallo por el que los enemigos se teletransportaban al salir del menú de pausa. Al no ejecutar sus updates mientras estabas en pausa el reloj que controla el deltaTime no se reseteaba por lo que se movían en función del tiempo que estabas en pausa.

## 20210513 RamónRodríguez @(1h)
Colisión entre NPCs.

## 20210514 JoseSansano @(30m)
Icono de moneda en el hud añadido.

## 20210514 RubénHerrera @(1h 15m)
Añadadida la vista de la tienda en el menú.

## 20210514 RubénHerrera @(2h 30m)
Creada la tienda. Falta llamarla con las monedas que tenga el jugador(ahora se llama con 100 para probar si funciona) y añadir las armas al personaje. Todo esto en Mundo en el update de la pausa.

## 20210515 CarlosVillena @(3h 30m)
Tienda Implementada.

## 20210514 RubénHerrera @(30m)
Ya se puede cambiar desde el menu de pausa al menu principal.

## 20210515 RamónRodríguez @(2h 10m)
Ataque de Soldado implementado. Falta rotar el sprite de la bala en función el ángulo con el que se mueve y añadir las colisiones a estas balas.

## 20210515 JorgeMompe @(1h 15m)
Buscar música para los mapas y la intro. Adaptarla y probar meterla en el juego.

## 20210515 JorgeMompe @(3h)
Implementar en el código la música principal del menú inicial, consiguiendo que si elige un sector en el inicio, cada mapa tenga su propia música. También que si le da a jugar sin más tenga se ponga la música del mapa 1. No conseguía que una vez pasara de un mapa a otro cambiara la canción.

## 20210516 JorgeMompe @(1h 20m)
Buscar, adaptar y meter en el código los efectos de sonido para la interacción de subir y bajar en los menús.

## 20210516 JorgeMompe @(1h)
Creación imagen GameOver e investigación de como implementarlo cuando el personaje muera.

## 20210516 JoseSansano @(1h 30m)
Creacion de setup.sh que descarga la carpeta resources del juego desde Google Drive y la descomprime. Se ha borrado un binario antiguo del juego que no servia para nada.

## 20210516 RamónRodríguez @(40m)
Las balas de Soldado ya rotan correctamente y se destruyen al colisionar con el mapa o salirse de él.

## 20210516 RamónRodríguez @(45m)
Player sufre daño cuando recibe un ataque cuerpo a cuerpo de un NPC o cuando colisiona con una bala de Soldado.

## 20210517 SergioEspinosa @(30m)
Actualizados los documentos autoevaluación, log, reparto y tareas.

## 20210517 JoseSansano @(30m)
Actualizados documentos autoevaluación, reparto y tareas. 

## 20210517 JoseSansano @(20m)
Actualizado vida_1.png

## 20210517 SergioEspinosa @(20m)
Ahora se escucha la música de cada nivel independientemente de si se accede a través del menú o pasando de nivel a nivel.

## 20210517 RamónRodríguez @(2h)
Posicionar junto a Sergio los enemigos y cofres en los distintos mapas.

## 20210517 RubénHerrera @(30m)
Cambiada el fondo de los controles del menú y actualizado documentos.

## 20210517 SergioEspinosa @(2h 30')
Posicionar junto con Ramón los enemigos y cofres en el mapa. He actualizado además el mapa del nivel 3 para colocar mejor enemigos, he bajado el daño de los enemigos que era bastante alto y he solucionado un problema del menú de pausa que no cambiaba al menú inicial si le dabas a menú principal.

## 20210517 RubénHerrera @(45m)
Añadida la pantalla de game over.

## 20210517 CarlosVillena @(3h 30m)
Cambios en el mundo, ahora el player no se resetea cuando se cambia de nivel y arreglos para que funcione.
