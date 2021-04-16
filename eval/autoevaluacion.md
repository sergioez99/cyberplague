# Autoevaluación individual

## Miembro 1
Reflejar tanto el progreso como los problemas encontrados con el grupo, código, juego... Si no se refleja ningún problema se asume que no existen.

## Miembro 2...


## José Antonio Sansano Melero
En este hito 2, he transferido las colisiones al mapa, y he simulado la gravedad para que el jugador no pueda moverse en cualquier dirección. También he añadido la funcionalidad de saltar, que será mejorada más adelante (doble salto, por ejemplo).
He creado una carpeta Tools con structs que son para sustituir a los de SFML (Vector2 de floats, Vector4 de Ints). También he intentado convertir todo el código que esta puesto de SFML a C++, utilizando solamente de SFML las clases de Motor2D (Fachada), pero no he podido por un error. Necesitaré hacerlo por partes, o dejar la clase Map (la que da el error) sin transformar y que siga utilizando funciones de SFML directamente.
He ayudado a implementar la clase personaje que no tenía sprite porque no heredaba de Entidad.
Y he ordenado como se realizaban los Inputs. Ahora los Inputs de movimiento los coge en tiempo real, y los pulsados (el botón de disparar, por ejemplo) utilizando el bucle de Events.

# Autoevaluación general
Requiere añadir una propuesta de nota sobre 10