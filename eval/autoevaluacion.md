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
Este hito comencé implementando la clase juego con el patrón estado en forma de ejemplo, pero se ha quedado sin implementar todavia el patrón al seguir trabajando en que el juego funcione.
También me di cuenta de que mi código de mapa tenia varios errores al coger los tiles y tuve que arreglarlo de inmediato. Además intenté usar la fachada en la clase mapa igual que Jose al haber hecho yo el código, pero lo dejamos para más adelante si hay tiempo para no liar mucho la cosa, ya que funciona correctamente así.
Por último, he creado las clases mundo y menú con las funciones de estado nada más porque como he mencionado antes, no estamos trabajando aun con el juego usando el patrón estado.

## Rubén Herrera Cervera
Para este hito lo primero que hice fue unificar el código del menú que teniamos separado. Aquí tuve un error ya que al pasar el codigo al proyecto probe a llamarlo desde el main para ver el resultado y no conseguía que se dibujase. Era porque tenía un error con la variable que manejaba es estado del menu en el que se encontraba. 
Implemente las diferentes funciones del patrón state en el menú e intenté continuar implementandolo en la clase CyberPlague pero sin éxito.
Finalmente adapté el codigo del menú para que utilizase el patrón fachada y añadí a este para que pudiese dibujar el texto.
Me ha quedado pendiente haber conseguido implementar el patrón state completo, aunque confío en tenerlo esta próxima semana.


# Autoevaluación general
Requiere añadir una propuesta de nota sobre 10