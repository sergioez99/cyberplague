# Manual de usuario

* Manual de usuario de cualquier elemento que este disponible en la rama master. Se puede crear un manual por elemento*
*Manual de usuario de cualquier elemento que este disponible en la rama master. Se puede crear un manual por elemento*

### PROT: Zombi

En este prototipo se observa como el enemigo Zombi se mueve sobre una plataforma representada con un rectángulo blanco sin caerse de ella.

### PROT: Mago

En este prototipo el jugador podrá moverse hacia la derecha o izquierda con las flechas del teclado.

Observaremos al enemigo Mago situado al lado izquierdo de la pantalla. Si nos acercamos un poco a él entraremos en su rango de visión y este comenzará a spawnear enemigos cada 2 segundos. En este prototipo los enemigos spawneados de moverán en línea recta, posteriormente se les aplicará el Algoritmo A* para calcular un pathfinding hasta el jugador.

### PROT: Soldado

En este prototipo el jugador podrá moverse hacia la derecha o izquierda con las flechas del teclado.

Observaremos al enemigo Soldado situado al lado izquierdo de la pantalla sobre una plataforma representada con un rectángulo blanco. Si nos acercamos un poco a él entraremos en su rango de visión y este nos diparará cada 1 segundo. Mientrás no estemos en su rango de visión este se moverá sobre la plataforma sin caerse.

### Mapa: Tiled y Mapa: Nivel 1 Mapa 1

Simplemente son ejecutables para visualizar que funciona la carga de mapa y el dibujado. No hay interacción con estos.

## Prototipos de Armas

En estos prototipos se definen las diferentes armas que tenga el personaje principal. Para disparar, pulsar la tecla 'Z'. 
En cada prototipo hay algunos parámetros que pueden ser ajustados a gusto del usuario, por ejemplo, la cadencia de disparo del arma, el daño y si se le quiere aplicar alguna mejora.

Estos parámetros son:

    - cad: Ajustar la cadencia de disparo, cada 'cad' frames, el personaje disparará. (+cad = cadencia más lenta, -cad = cadencia más rapida.)

    - dmg: Ajustar el daño del arma. (En algunos prototipos el daño se encuentra como una variable para aplicar correctamente la mejora.) 

    - mejora: Activar o desactivar la mejora del arma. (El arma básica no tiene mejora.)

Además en la parte derecha de la pantalla, aparecerá un enemigo de prueba. Cada vez un proyectil impacte con el, la consola mostrará la vida que le falte.

### PROT: Arma_Basica

Dispara un proyectil simple con una cadencia media. Hace un daño moderado.


### PROT: Arco_Hojas

Dispara un proyectil poderoso pero muy lento. Con esta arma es posible atravesar enemigos. 

#### MEJORA:

Con la mejora aplicada es posible disparar tres proyectiles en vez de uno.


### PROT: Rayo_Laser

Dispara un proyectil con una cadencia muy alta pero un daño muy bajo. Su munición atraviesa al enemigo.

#### MEJORA:

La mejora aumenta el daño del arma.


### PROT: Lanzallamas

Esta es un arma especial, en vez de disparar proyectiles, dispara un llama que hace daño constante. Hace mucho daño pero gasta mucha munición.

#### MEJORA:

Con la mejora aplicada, aumenta el daño y el rango del arma.
