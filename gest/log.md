# Log del trabajo realizado por dia
**El log es obligatorio**

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
