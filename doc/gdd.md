# Game Design Document

## Ficha del Juego

### Título

Cyber Plague

### Sistema de juego

El juego estará basado en una mezcla de géneros, los cuales son “Aventura”, “Plataforma” y “Run and gun”.
Hay un lobby en el que aparecen los diferentes mundos. Cuando seleccionas uno pasas a un nivel 2d de scroll lateral en el que tienes un arma y tienes que eliminar a los diferentes enemigos. Cada mundo tiene un boss final que al derrotarlo nos dará un nuevo arma o habilidad. El jugador además, tendrá acceso en todo momento a una tienda en la que poder comprar armas/habilidades y mejoras.
Por el mapa, se irá encontrando una serie de cofres, que le dará a su elección munición, dinero o vida, y para abrirlos harán falta un arma específica.

### Público al que va dirigido

El videojuego estará dirigido para todos los públicos, independientemente de la edad. (PEGI 7)

### Resumen de la historia del juego orientada a la jugabilidad

CX-44, es un cyber agente que ha tenido que viajar al planeta Kepler, ya que ha habido un descontrol con un agente biológico que amenaza con expandirse por toda la galaxia. Él debe eliminar la amenaza a través de los diferentes sectores que conforman el planeta.

Para poder completar su misión, nuestro cyber agente utilizará todo su arsenal de armas y recursos que disponga. Además dentro de las profundidades de este planetas encontrará una gran variedad de equipamiento que le ayudará en su misión.

### Distintos modos de juego

El jugador, podrá elegir entre diversos modos de juego, que todos siguen la historia original pero con diferentes dificultades:

- **Modo Historia:** El jugador tiene tiempo libre para pasarse todo el juego con una dificultad estándar.
- **Modo Speedrun**: Los niveles tienen un tiempo límite para que el jugador se lo pase.
- **Modo Hardcore:** El jugador cuenta con una única vida por nivel, en el cual si muere tiene que empezar todo el juego de nuevo.
- **Modo Speedrun & Hardcore:** Mezcla de ambas dificultades anteriores.

### Puntos únicos de vuestro juego: cinco mínimo que destacan a vuestro juego del resto

1. Adquirir un arma al derrotar un boss final.
2. Posibilidad de jugar los niveles de cada sector en el orden que se desee.
3. Historia única independientemente de la dificultad.
4. Compra de mejoras para el personaje y las armas en la tienda.
5. Variedad de modos de juego.

### Juegos parecidos

Super Mario Bros.
Celeste.
Megaman.
Metroid.

## Ámbito y Jugabilidad

### Jugabilidad

#### Cómo se progresa en el juego

El personaje va de forma secuencial de un sector a otro, dentro de cada sector hay unos niveles que puede elegir libremente más un boss final bloqueado.
En estos niveles va consiguiendo armas, monedas e incluso habilidades. Y para pasar de un sector a otro necesita haber pasado antes todos los niveles y derrotado al boss, el cual le dará una llave para pasar al siguiente sector. 

#### Misiones y estructura de retos

Al comenzar, el jugador tendrá que hacer un tutorial básico de controles. Al final del tutorial habrá un jefe que el jugador debe vencer. Cuando el jugador derrote al jefe, la zona en donde se encuentra actuará como un lobby principal y tendrá desbloqueado el primer sector y la tienda donde puede comprar equipamiento. El jugador debe ir venciendo a los jefes de cada sector para desbloquear los siguientes.

Cada sector tendrá varios niveles diferentes, donde el jugador deberá encontrar una llave, por nivel, para desbloquear el nivel final donde deberá enfrentarse al jefe del sector.

El orden de los niveles no es secuencial por lo que el jugador puede hacer los niveles en el orden que quiera, pero debe hacerlos todos para poder avanzar. 

#### Objetivos del juego

El objetivo principal del juego es completar todos los niveles y derrotar al boss final de cada sector. Como objetivo secundario encontramos el mejorar el personaje al máximo.

### Cuantificación

#### Lugares en los que se desarrolla el juego

- Estación de Llegada.
- El gran bosque.
- La ciudad futurista.
- El sector infernal.

#### Número de niveles

Se compone de 3 sectores, en el que cada sector estará compuesto por 3 niveles. Donde en cada nivel necesitará conseguir una especie de llave que le permitirá enfrentarse al boss final y así pasar de sector.

#### Número de NPC’s 

- **Zombies:** Personas contaminadas que deambulan de un lado a otro. 

- **Guerrero:** Soldado con armadura y escudo, el cual solo se le puede matar por la espalda. Será un enemigo estático y atacará a melee cuando el personaje esté en frente.

- **Mago:** Spawnea enemigos como pájaros o robots hasta que lo matamos.

- **Pájaros/Insectos:** Enemigos voladores que irán hacia el personaje, atacandote si dejas que se acerquen.

- **Robots/Soldados:** Enemigos a ras de suelo que te disparan.

- **Tendero:** El único superviviente del ataque de la plaga, fue el que mandó a la FEI la petición de socorro. Su función en el juego es la de proporcionar equipamiento al agente CX-44.

En cuanto a los jefes finales, serán enemigos de un tamaño superior al normal, dotado de un conjunto de habilidades.

- **Boss del Tutorial:** Enemigo grande que se moverá y disparará al jugador. Será un enemigo sencillo para enseñarle al jugador las mecánicas básicas.

- **Boss del bosque:** Árbol mutante que se compone de dos ataques, uno en el que te atrapa con sus raíces, por lo que se debe saltar para evitar el ataque. Spawnea pájaros de sus hojas.

- **Boss de la ciudad:** Robot gigante que sólo puedes hacerle daño disparando en su punto débil que se encuentra en cada lado a una altura en la que habrá que coordinar el momento del salto con el disparo para poder alcanzarlo. Una vez que lo destrozas, el robot salta hacia el otro lado, teniéndolo ahora a la izquierda. El robot ataca con un láser, que se tendrá que esquivar saltando o quedándote en el suelo.

- **Boss de fuego:** Dragón que te ataca desde el aire, lanzando fuego que tendrás que esquivar moviéndote a cada lado. El dragón bajará a cargar un ataque por lo que tendrás que disparar en la cabeza para realizarle más daño mientras carga su ataque.

#### Número de armas

Habrá 4 armas, el arma principal del personaje y una con la temática de cada sector.

- **Rayo Básico:** Arma principal del protagonista. Poco daño y cadencia media. Munición Infinita.

- **Arco de Hojas:** Se obtiene tras vencer al jefe final del primer sector. El arma tendrá menos cadencia que el arma principal pero hará más daño que el ésta. Atraviesa enemigos. Gasta bastante munición. Su mejora hace que se puedan lanzar tres flechas en vez de una.

- **Rayo Láser:** Se obtiene tras vencer al jefe final del segundo sector. El arma tendrá mucha cadencia pero poco daño. Atraviesa enemigos. Gasta poca munición. Su mejora aumenta el daño base del arma.

- **Lanzallamas:** Se obtiene tras vencer al jefe final del tercer sector. El arma será de daño constante. Bastante daño. Gasta bastante munición. Su mejora aumenta el rango y el daño.

Para cambiar de arma, el jugador deberá pulsar el botón de cambio de arma (Apartado Controles) y se cambiará de arma de forma secuencial. Por ejemplo si el jugador tiene el arma básica, al pulsar el botón se cambiará al arco de hojas, y si se pulsa otra vez pasará al rayo láser.

### Flujos del juego

Empieza el juego -> Menú de selección de dificultad -> Tutorial -> Bucle (Estación de Llegada -> Seleccionar sector -> Seleccionar nivel -> Resultados) -> Fin

## Interfaz

### Sistema visual

#### HUD

Tan solo se encontrará en la parte superior izquierda la vida del personaje, debajo el arma y la munición que tenga en ese momento y debajo de ésta, la cantidad de mejoras que tendrá el jugador, divididas por el tipo de mejora.

#### Menús

Habrá un Menú inicial, donde pondrá:
- Nueva Partida.
- Cargar Partida (si ya tiene una empezada).
- Como jugar (Menú ayuda)
- Opciones: Aquí dentro habrá lo siguiente:
    - Sonido.
    - Video.
- Créditos.
- Salir (cierra el juego).

Lobby:
- Imagen Sector 1.
- Imagen Sector 2.
- Imagen Sector 3.
- Tienda.
- Una flecha para volver al menú inicial.

Menú tienda: 
- Armas.
- Habilidades.
- Una flecha para volver al Lobby.

Menú de niveles, dentro de cada sector:
- Imagen del Nivel 1.
- Imagen del Nivel 2.
- Imagen del Nivel 3.
- Imagen del posible Boss Final en gris (bloqueado).
- Una flecha para volver al Lobby.

El menú de pausa contendrá:
- Guardar partida.
- Opciones: Mismas elecciones que en el anterior.
- Volver al menú de niveles.

#### Cámara

La cámara seguirá al personaje en cada momento, situándose en el centro del escenario.

### Controles

**TECLADO**
- **Saltar:** Z
- **Disparar:** X
- **Moverse hacia la derecha:** Flecha Derecha
- **Moverse hacia la izquierda:** Flecha Izquierda
- **Interactuar:** Flecha Arriba
- **Aceleración:** Dos veces seguidas la tecla de dirección
- **Pausa:** P
- **Cambiar arma:** C
        
**MANDO (XBOX)**
- **Saltar:** A
- **Disparar:** X
- **Moverse hacia la derecha:** Joystick Derecha // Flecha Dirección Derecha
- **Moverse hacia la izquierda:**  Joystick Izquierda // Flecha Dirección Izquierda
- **Interactuar:** Joystick Arriba // Flecha Dirección Arriba
- **Aceleración:** Dos veces seguidas el botón de dirección
- **Pausa:** Start
- **Cambiar arma:** Y

### Sonido

El juego tendrá una banda sonora acorde a cada tipo de nivel y de ambientación. Ya que el juego es de corte arcade, la banda sonora será de tipo arcade.

### Sistema de ayuda

Este juego está basado en juegos con una dificultad alta, por lo que la forma de facilitar la experiencia será el farmeo de monedas que al comprar nivel con ellas aumentará el nivel del personaje.

## Mecánica

### Reglas del juego

#### Física

Las físicas del juego, corresponderá en similitud a las de la vida real. El protagonista podrá andar, saltar y correr como lo harían personas físicamente normales, tal y como ocurre en la realidad, del mismo modo ocurriría con los NPCs pero con sus limitaciones.

Por lo tanto, se tendrá en cuenta la fuerza de la gravedad hacia el suelo en función del tamaño y de la interacción que tenga con el entorno.

#### Movimiento

El jugador podrá moverse hacia la derecha e izquierda y saltar, también podrá hacer un dash en cualquiera de esas direcciones después de un breve tiempo de recarga.

Los NPCs terrestres podrán moverse hacia la derecha e izquierda pero solo podrán saltar para subir de plataforma.

Los NPCs aéreos podrán moverse en cualquier dirección (derecha, izquierda, arriba y abajo).

#### Objetos

- **Moneda:** Después de derrotar a un enemigo, este soltará una moneda que caerá al suelo y que el jugador podrá recoger pasando por encima de ella.
- **Cofres:** Por los niveles habrán unos cofres ocultos, éstos solamente se podrán abrir si le disparamos con el arma adecuada:

    - **Cofre Amarillo:** Se abre con el arma básica del personaje.
    - **Cofre Verde:** Se abre con el arco de hojas.
    - **Cofre Rojo:** Se abre con el rayo láser.
    - **Cofre Naranja:** Se abre con el lanzallamas.

    Arriba del cofre habrá un indicador sobre la recompensa que dará el cofre, el indicador irá cambiando de forma aleatoria. El jugador deberá abrirlo cuando aparezca la recompensa que quiera para obtenerla. En el caso de que el jugador tenga la característica al máximo, los cofres podrán dar solo las que le falten.

- **Munición:** Se encontrará por el escenario, al recogerlo el jugador recuperará parte de la barra de munición dependiendo del arma que tenga equipada.
- **Salud:** Se encontrará por el escenario, al recogerlo el jugador recuperará parte de la salud dependiendo del arma que tenga equipada.

#### Acciones

- **Disparar:** El jugador podrá disparar siempre que se encuentre dentro de un nivel.
- **Interactuar:** El jugador podrá interactuar con el entorno (tienda, entrada a los distintos sectores) de la Estación de Llegada una vez completado (tutorial).
- **Moverse:** El jugador podrá moverse tanto hacia adelante como hacia atrás para poder explorar y completar el nivel.
- **Saltar:** El jugador podrá hacer saltos para superar los obstáculos y explorar los niveles.
- **Cambiar arma:** El jugador podrá cambiar de arma dentro del nivel.

#### Economía

En el juego, derrotando enemigos obtendremos una moneda, llamada “créditos”. Cada enemigo, acorde a la dificultad del mismo y del sector donde se encuentre dará más dinero o menos. Además, los jefes de cada sector darán una gran cantidad de dinero.

Con este dinero, el jugador podrá comprar en la tienda diferentes mejoras para el personaje (Aumentar Salud Máxima, Aumentar Munición Máxima, Mejorar Resistencia).

Cada mejora del mismo tipo será más cara que la anterior y se puede mejorar cada característica hasta un máximo de 5 veces. (15 Mejoras en total)

También se podrán mejorar las armas que se obtengan de los jefes finales.

- **Precios:**
    - **Mejora de estadística:** 10 / 25 / 50 / 150 / 300 créditos. 
    - **Mejora de armas:** 300 créditos.

### Transición de pantallas

#### Diagrama de transición de pantallas

![](/otros/img/transicion_pantallas.png)

#### Descripción de las pantallas

- **Menú principal:** Primer menú que visualiza el jugador. En este está el título de juego con una lista de opciones. Utilizando la lista, el jugador puede acceder a diferentes pantallas: Ayuda, créditos y Jugar. El jugador podrá salir del juego y, si ya ha jugado, podrá cargar su partida. Al seleccionar jugar, deberá elegir la dificultad con la que quiere jugar.

- **Menú Créditos:** En este menú se puede ver el nombre de los desarrolladores del juego. Desde este menú solo se puede acceder al menú principal

- **Elegir nivel:** Al acceder a esta pantalla, el jugador podrá elegir a qué sector jugar de los ya desbloqueados o comprar mejoras en la tienda. Al elegir un sector, tendrá que elegir que nivel va a jugar de ese sector antes de poder jugar.

- **Nivel Ingame:** En esta pantalla el jugador controla a su personaje e interactúa con el entorno y enemigos que haya. Si muere el jugador volverá al principio del nivel. Si completa el nivel, volverá a la pantalla de Elegir nivel. También podrá parar el juego en cualquier momento cambiando al menú de pausa.

- **Menú de pausa:** Pantalla que para el tiempo de juego. El usuario podrá guardar la partida, acceder a las opciones, volver al juego o salir al menú de elegir nivel.

- **Menú de ayuda:** Menú que muestra los controles del juego. Desde aquí solo puede volver al menú principal.

- **Nivel Completado:** Pantalla que aparecerá al completar un nivel satisfactoriamente. Saldrá del nivel y volverá a la pantalla de Elegir nivel.

###  Opciones del juego

- **Modo Speedrun**: El jugador dispondrá de un tiempo limitado para completar el nivel.
- **Modo Hardcore:** El jugador dispondrá de menos vida, si recibe un golpe muere y deberá empezar el juego desde el principio.
- **Modo Speedrun & Hardcore:** Mezcla de ambos modos.

### Rejugar y salvar

El juego tendrá la función de autoguardado. El juego guardará siempre que se cambie de sector o acceda a algún nivel o a alguna zona.

Cuando el jugador salga del juego volverá siempre a la entrada del sector en donde esté.
Si es el lobby principal, el jugador aparecerá en su nave.

Como adicional, si vamos bien de tiempo, el juego incluirá un modo NG+, donde el jugador podrá comenzar de nuevo el juego, manteniendo todas las mejoras y equipamiento que haya conseguido en su partida previa, pero aumentando la dificultad de los enemigos.

### Trucos y Easter Eggs

**Trucos**
- Modo God: El jugador será invulnerable.
- Desbloquear todos los niveles.

**Easter Eggs**
A lo largo de los niveles el jugador se irá encontrando unos cofres todavía más escondidos que le proporcionarán unas habilidades y mecánicas excepcionales. 

## Historia, características y personajes

### Historia

Año X-2034, la FEI (Federación Espacial Intergaláctica) recibe una petición de socorro procedente del planeta Kepler. 

Al parecer un agente biológico no identificado ha aniquilado a gran parte de la población del planeta y amena. Ante esta situación la FEI envía a su mejor agente para poner fin a la plaga, el agente CX-44.

### Mundo del juego

El juego transcurrirá en el planeta Kepler. Allí, el agente CX-44 deberá superar bosques, ciudades e infiernos de lava, llenos de criaturas mutadas por el agente biológico.

### Personajes

Nuestro protagonista es un cyber agente llamado CX-44, perteneciente a la FEI. Con unas habilidades sobrehumanas ya que es mitad robot mitad humano. 

## Niveles

### Tutorial

Es un primer nivel introductorio para que el jugador conozca los controles e incluso se enfrente con un sencillo boss final. Todo esto transcurre para llegar al lobby principal. 

El mapa comienza con un breve diálogo para situar al personaje en la historia. Seguidamente, aparece nuestro protagonista en la nave con intención de aterrizar en una  estación espacial. Cuando sale, se le muestra al jugador unas breves indicaciones para controlarlo. Solo puede avanzar por el mapa hacia la derecha, donde se encontrará algunos oponentes, y al final, un sencillo boss final.

### Nivel 1. El gran bosque

Los niveles de bosque estarán compuestos principalmente por plataformas situadas en los árboles. Entre las plataformas habrá vacío donde el jugador podrá caerse y morir.

- **Nivel 1-1:**  El primer nivel del juego, este nivel no debería suponer mucha dificultad. El jugador avanzará a ras del suelo, topándose con enemigos básicos que anden libremente hacia delante. Habrá plataformas estáticas y algún vacío donde el jugador debe saltar para superarlo.
- **Nivel 1-2:** En este nivel, el jugador se moverá entre los árboles. Será un nivel más enfocado en las plataformas. El jugador deberá tener cuidado de caerse al vacío o de tocar unas zarzas ya que será muerte instantánea. También habrá algún enemigo volador que molestará al jugador.
- **Nivel 1-3:** En este nivel el jugador ya debería conocer las mecánicas básicas del juego. Será un nivel donde se mezcle lo aprendido en los dos niveles anteriores pero haciéndolo un poco más complicado. Ya comenzarán a haber enemigos más complejos pero no muchos.
- **Jefe Final del Sector:** Será un enemigo estático que ocupará toda la pantalla. Tendrá varios patrones de ataque. Cada cierto tiempo, invocará enemigos voladores y atacará con unas raíces que hacen daño al jugador y le atrapan. Este enemigo no tiene ningún punto débil, simplemente hay que dispararle y ya.

### Nivel 2. La ciudad futurista

En este caso, el mapa estará ambientado principalmente por la calle de una ciudad futurista algo derruida. Donde tiene que conseguir llegar a la azotea de un edificio. Durante el mapa habrá plataformas y vacíos donde se pondrán a prueba las habilidades del jugador.

- **Nivel 2-1:** En este primer nivel empezará en la calle de la ciudad, donde se irá encontrando coches que tiene que ir saltando, algunos robots enemigos  que le irán disparando, algunas plataformas. Y todo hasta llegar a un edificio en particular.
- **Nivel 2-2:** En este nivel, transcurre todo dentro del edificio algo destruido. El personaje irá pasando de una habitación a otra donde se encontrará ya otro tipos de enemigos, como soldados. Irá saltando por distintas plataformas que se irá encontrando, hasta llegar al final donde habrá un ascensor que le llevará a la azotea.
- **Nivel 2-3:** En este tercer nivel, el personaje irá avanzando por las azoteas de edificios. Donde encontrará plataformas que le permitirán saltar de uno a otro, algunos huecos donde podrá caer y morir, algunos enemigos que tendrá que ir superando.
- **Jefe Final del Sector:** El boss final será un robot como 2-3 veces más grande que el personaje, el cual es resistente a las balas, pero con un punto débil, y se mueve de izquierda a derecha pudiendo saltar encima del protagonista. Cuando se le consigue quitar algo de vida, vuelve a su posición inicial.

### Nivel 3. El sector infernal

Este mapa estará ambientado en una zona volcánica compuesta por árboles quemados, edificios destruidos, rocas que caen del cielo que se deberán esquivar y lagos de lava donde se puede morir.

- **Nivel 3-1:** En este primer nivel, el personaje se encontrará en una cueva de la cual debe salir con la ayuda de distintas plataformas mientras elimina enemigos y evita caer a pequeñas zonas de lava y huecos con rocas puntiagudas.
- **Nivel 3-2:** En este nivel, el personaje se encontrará en un paisaje quemado con lagos de lava y fuego que deberá evitar saltando a través de distintas plataformas mientras elimina numerosos enemigos.
- **Nivel 3-3:** En este último nivel, el personaje se encontrará en el pie de un volcán en erupción en el que deberá avanzar a través de plataformas (algunas de ellas muy dañadas que se destruirán después de estar un tiempo sobre ellas), evitando caer en la lava y eliminando todo tipo de enemigos mientras esquiva rocas que caen del cielo.
- **Jefe Final del Sector:** El boss final será un dragón del tamaño de media pantalla, el cual estará volando y lanzando ataques que debemos esquivar. Cada cierto tiempo bajará a tierra a realizar un ataque cargado y deberemos aprovechar ese momento mientras carga para dispararle.

## Inteligencia artificial

### IA del oponente

Contamos con varios oponentes y cada uno de ellos tendrá una IA diferente:

- **Zombi:** el zombi estará deambulando una zona y te hará daño si te acercas mucho a él. El zombi se dará la vuelta si llega hasta un borde.
- **Guerrero:** el guerrero dará espadazos a la izquierda y a la derecha, pero estará estático. Para derrotarlo tendrás que darle un golpe por la espalda
- **Mago:** el mago estará de manera estática esperando a que entres en su rango de visión para invocar a sus súbditos que atacarán por él. Estos súbditos se moverán hacia ti por cielo y tierra además que intentarán chocar contigo para explotar y hacerte daño. El tipo de súbdito que invocará el Mago estará condicionado por el nivel en el que estemos, por ejemplo, en el nivel 1 invocará insectos o pájaros.
- **Soldado:** los soldados estarán patrullando una zona y no dudarán en atacarte cuando te vean. Los soldados cuentan con varias armas a distancia que tendrás que esquivar para derrotarlos.

**Jefes Finales:** cada jefe contará con diferentes mecanismos para derrotarte y estarán influenciados por el nivel al que pertenezcan:

- **Árbol maldito contaminado:** este jefe final estará estático pero utilizará sus raíces para atraparte y hacerte daño. También cuenta con la habilidad de invocar pájaros e insectos como los magos.
- **Robot gigante:** este jefe final disparará rayos láser desde una altura elevada y es muy resistente a las balas, pero tiene un punto débil. Tras dañarlo lo suficiente este se reposicionará y volverá a atacarte.
- **Dragón anciano:** este jefe final podrá volar por todo el escenario mientras dispara bolas de fuego. Tras cierto tiempo, el dragón se posará en el suelo para cargar un super lanzallamas. Este es el momento en el que tendrás que atacar para que cancele su ataque, si no, disparará su lanzallamas que será imposible de esquivar.

### IA de los NPC

Contaremos con un único NPC que será el tendero. El tendero sólo saldrá en una ventana estática donde nos venderá mejoras para nuestro personaje. Tendrá diversos diálogos a la hora de entrar y salir de la tienda, escoger alguna mejora y comprarlo.

### IA de soporte

Utilizaremos IA de soporte como la detección de colisiones en los enemigos, el protagonista y el terreno del nivel, al haber diversos obstáculos. También utilizaremos una IA de proximidad para que diversos enemigos te ataquen cuando estés en su rango.

## Diseño software

### Diagramas de clase de alto nivel

![](/otros/img/clase_alto_nivel.png)

### Otros diagramas estáticos o dinámicos



### Patrones de diseño

- **Patrón Singleton:** El patrón Singleton se utiliza para garantizar que solo exista una instancia de una clase, de este modo las demás clases pueden acceder a sus atributos y métodos sin que se cree más de una instancia. Utilizaremos este patrón por ejemplo para los diferentes enemigos con los que cuenta nuestro juego.
- **Patrón State:** Se utiliza una clase Estado que controla qué tipo de pantalla debe ejecutarse en cada momento. Utilizaremos este patrón para el flujo de nuestro juego.

## Motores

### Motor2D

- **OpenGL**

### Física



### Scripting



## Dirección y planificación

### Funcionalidades básicas por entregable

- Movimiento de personaje con plataformas.
- Matar enemigos (Hitbox).
- Físicas (personajes que vuelan y otros no).
- Batallas de jefe (IA, ganar partida…).
- Cambio de nivel (cargar distintos mapas).
- Movimiento de cámara (que la cámara siga al personaje).
- HUD (vida, munición…).
- Distintos tipos de arma.
- Diálogos (escribir en pantalla).
- Animaciones (cargar y dividir el spritesheet).
- Menú pausa (que el juego pare mientras estás en el menú y vuelva donde estabas).
- IA de enemigos.

### Funcionalidades opcionales

- Tienda.
- Cofres.