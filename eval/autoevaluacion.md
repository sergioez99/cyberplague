# Autoevaluación individual

## José Antonio Sansano Melero
En este hito 3, me he dedicado a perfeccionar las colisiones, ya que el personaje se movia raro.
Desde que el bucle interpolado se añadió al juego, el movimiento del player hacia cosas raras : Vibraba, se metía dentro del suelo si saltaba muy alto... Pero también tenia otros problemas secundarios, que no eran a causa del bucle interpolado, como que el Player podía "agarrarse" a la pared y no caerse de ella. Todos los bugs que surgían se han fixeado, hasta el del bucle interpolado.
Ahora mismo, la colisión del Player con el mapa esta lo más perfecta posible, no hace cosas raras y se mueve como debería de moverse. También realiza el salto bien, y cambié el spritesheet del Player para que tenga una animación correcta el salto sin cambiar código. Aparecian algunos bugs que se creaban al añadir cosas nuevas, como uno del input del menu, que he acabado fixeando, y he creado el Hud del juego. 
El Hud se podia hacer de dos maneras, pero he optado por la más rápida, que es hacer que el hud siga la vista del juego, por lo que crea una sensación de que el hud no se mueve y está en su sitio, al menos respecto a la View. La he creado de tal manera de que el Hud solo puede existir si esta el Player creado, ya que no tiene sentido que haya Hud si no hay Player para mostrar sus estadísticas.

## Ramón Rodríguez Pedraza
En este último hito he implementado el render interpolado y he arreglado un problema con la limitación de las llamadas a update.
También he implementado las colisiones de las balas de Player con el mapa, los sprite sheets y animación de los NPCs Zombi y Soldado con sus respectivos ataques, he hecho que los NPCs colisionen entre ellos y junto a Sergio he posicionado todos los NPCs y Cofres en los mapas.

## Sergio Espinosa Zaragoza
Este último hito lo primero que implementé fueron las clases menú y mundo con el patrón state que se quedaron a medias en el hito 2. 
Una vez funcionales, me puse a crear un segundo nivel para nuestro videojuego. Después salió un problema con las capas del mapa y tuve que arreglar las colisiones de las balas, y el dibujado del personaje que también es el de las balas. 
Y por último decidimos hacer un tercer nivel que también cree e implementé yo, y también decidi buscar los sprites para el HUD que ya había empezado a implementar Jose para quitarle trabajo, ya que a los sprites del HUD habia que quitarles el fondo porque no había ningún png sin fondo que nos sirviese.


## Rubén Herrera Cervera
En el hito final, me he encargado de terminar el menu y arreglar unos fallos que tenía. Le he añadido a este una pantalla con los controles. He creado la clase pausa que mantiene el estilo del menú y he hecho que funciones parando el update y el render del juego. Tambien he creado el sistema con el que funciona la tienda del juego en este menú. Al final he añadido la pantalla de muerte que te permite ir al menú.

## Carlos Villena Cerdá
Para finalizar con el proyecto, en el hito 3 decidí terminar de hacer todas las armas y sus mejoras y terminar de perfeccionarlas (hice que las balas se eliminaran del mapa cuando llegan a cierta distancia), también creé una clase para implementar mejor los inputs del usuario, creé todo el sistema de looteo de monedas y el sistema de los cofres (la mayoría de los sprites los creé de 0 y los incluí en su respectivo spritesheet), implementé la lógica de la tienda (no hice los menús) y para terminar hice que el jugador sea independiente del nivel en el que se esté. Aparte de todo lo anterior, corregí algunos problemas menores con algunas clases y ajuste el código en general para que todo funcione mejor. Creo que en rasgos generales ha sido un buen hito y personalmente me siento muy satisfecho con el resultado final.

## Jorge Mompeán Cabezas
En este hito he tenido bastante poca participación por mi parte por temas personales y de tiempo. Conseguí en la rama experimental que el personaje principal tenga una animación en estático y una animación corriendo de un lado para otro, y con la ayuda de Jose Antonio, una vez incluí en esta rama lo hecho en experimental, adaptamos mi código a lo que se había hecho en el main. Confio que para la entrega del proyecto final tenga más presencia y pueda aportar mucho más de lo poco que he hecho en relación al resto de compañeros.


# Autoevaluación general
Este hito hemos conseguido implementar casi todas las funcionalidades propuestas al principio del proyecto en el juego, incluyendo las funcionales opcionales de las monedas y la tienda, pero quitando los NPC de Pajaro y Mago. Estamos bastante contentos con el resultado de nuestro trabajo y pensamos que hemos conseguido un buen resultado. Creemos que la nota de nuestro hito podría ser un 7/10.

# Porcentaje de nota
José Antonio Sansano Melero : 20% Ramón Rodríguez Pedraza : 20% Sergio Espinosa Zaragoza: 20% Rubén Herrera Cervera : 16% Carlos Villena Cerdá : 20% Jorge Mompeán Cabezas: 4%
