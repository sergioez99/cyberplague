# Autoevaluación individual

## José Antonio Sansano Melero
En este hito 2, he transferido las colisiones al mapa, y he simulado la gravedad para que el jugador no pueda moverse en cualquier dirección. También he añadido la funcionalidad de saltar, que será mejorada más adelante (doble salto, por ejemplo).
He creado una carpeta Tools con structs que son para sustituir a los de SFML (Vector2 de floats, Vector4 de Ints). También he intentado convertir todo el código que esta puesto de SFML a C++, utilizando solamente de SFML las clases de Motor2D (Fachada), pero no he podido por un error. Necesitaré hacerlo por partes, o dejar la clase Map (la que da el error) sin transformar y que siga utilizando funciones de SFML directamente.
He ayudado a implementar la clase personaje que no tenía sprite porque no heredaba de Entidad.
Y he ordenado como se realizaban los Inputs. Ahora los Inputs de movimiento los coge en tiempo real, y los pulsados (el botón de disparar, por ejemplo) utilizando el bucle de Events.

## Ramón Rodríguez Pedraza
En este hito 2, he solucionado los errores que tuve en el hito 1 con el Algoritmo A*, y he unificado todos los NPCs a través de la clase NPC de la que todos heredan. También he creado la clase AI_Agent que contiene una clase Nodo y que sirve para obtener un camino a seguir utilizando el Algoritmo A*, esta clase se utilizará en el NPC Pájaro.
He hecho que los NPCs terrestres, Zombi y Soldado, se muevan de un lado a otro sin caerse de la plataforma en la que están utilizando la matriz de colisiones del mapa.
He implementado el movimiento de la cámara, haciendo que siga al jugador cuando llegue a la mitad de la pantalla y que deje de seguirlo cuando llegue al final del mapa. Para esto he creado una clase M_View en Motor2D para no trabajar sobre la View de SFML.
He hecho que cuando el jugador colisione con un NPC sufra daño y muera cuando su vida llegue a 0 (actualmente cuando muere deja de llamar a su update y a su render, por lo que no se mostrará y no podremos interactuar, para el próximo hito lo que hará será mostrar la típica pantalla de Game Over). También he hecho que cuando un proyectil colisione con un NPC este reciba daño y el proyectil se elimine. Cuando la vida del NPC llegue a 0 este morirá.
Por último, he limitado las llamadas a los update a 15 veces por segundo y he intentado implementar el render interpolado, pero como hasta el momento estabamos moviendo los sprites en los updates me han surgido varios errores al implementarlo y he tenido que quitarlo para este hito.

## Sergio Espinosa Zaragoza
Este último hito lo primero que implementé fueron las clases menú y mundo con el patrón state que se quedaron a medias en el hito 2. 
Una vez funcionales, me puse a crear un segundo nivel para nuestro videojuego. Después salió un problema con las capas del mapa y tuve que arreglar las colisiones de las balas, y el dibujado del personaje que también es el de las balas. 
Y por último decidimos hacer un tercer nivel que también cree e implementé yo, y también decidi buscar los sprites para el HUD que ya había empezado a implementar Jose para quitarle trabajo, ya que a los sprites del HUD habia que quitarles el fondo porque no había ningún png sin fondo que nos sirviese.


## Rubén Herrera Cervera
Para este hito lo primero que hice fue unificar el código del menú que teniamos separado. Aquí tuve un error ya que al pasar el codigo al proyecto probe a llamarlo desde el main para ver el resultado y no conseguía que se dibujase. Era porque tenía un error con la variable que manejaba es estado del menu en el que se encontraba. 
Implemente las diferentes funciones del patrón state en el menú e intenté continuar implementandolo en la clase CyberPlague pero sin éxito.
Finalmente adapté el codigo del menú para que utilizase el patrón fachada y añadí a este para que pudiese dibujar el texto.
Me ha quedado pendiente haber conseguido implementar el patrón state completo, aunque confío en tenerlo esta próxima semana.

## Carlos Villena Cerdá
Al comienzo del hito empecé creando la clase M_Window y M_Sprite, después creé la clase Entidad y NPC e incluí algunas funcionalidades para que las clases de los NPCs (que ya estaban creadas) para que pudieran utilizar los métodos de las clases padre. También implementé las clases de las armas y creé sus sprites.
En general creo que ha sido un buen hito, hemos conseguido implementar muchas funcionalidades y nuestro juego a dia de hoy parece algo muy diferente a cuando empecemos. A pesar de que aun quedan más funcionalidades por implementar, estoy muy satisfecho con el resultado. 

## Jorge Mompeán Cabezas
En este hito he tenido bastante poca participación por mi parte por temas personales y de tiempo. Conseguí en la rama experimental que el personaje principal tenga una animación en estático y una animación corriendo de un lado para otro, y con la ayuda de Jose Antonio, una vez incluí en esta rama lo hecho en experimental, adaptamos mi código a lo que se había hecho en el main. Confio que para la entrega del proyecto final tenga más presencia y pueda aportar mucho más de lo poco que he hecho en relación al resto de compañeros.


# Autoevaluación general
En este hito hemos conseguido asentar las bases de lo que será nuestro futuro videojuego y, a pesar de que nos queda más trabajo a realizar, estamos muy satisfechos con el resultado. Creemos que la nota de nuestro hito podría ser un 7/10.
