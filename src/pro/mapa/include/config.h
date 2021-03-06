#ifndef CONFIG_H
#define CONFIG_H

static const unsigned int WIDTH = 3200;
static const unsigned int HEIGHT = 1200;
static const unsigned int BPP = 32;

#define TAMANO_BLOQUE_X 17 // posicion inicial del jugador
#define TAMANO_BLOQUE_Y 17 // arriba-abajo
#define NUM_FILAS 66
#define NUM_COLUMNAS 60
#define KVEL 30
#define TIPO_ENEMIGO 2      // hasta el 4
#define COLOR_ATAQUE 0      // 0 si enemigo (naranja), 1 si jugador (azul)
#define TIPO_ATAQUE 2       // 2 flecha, 1 bola, 0 y 3 forma de fuego
#define DIRECCION_ENEMIGO 0 // 0 derecha, 1 izquierda

#define COORD_X 10 // posicion inicial del jugador
#define COORD_Y 950

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
#define TIME_BEFORE_POTION_APPEARS 0.3f
#define GAME_OVER_TITLE_PATH "resources/font/witchhunt1.ttf"
#define FONT_NO_TITLE "resources/font/amagro.ttf"
#define FONT_TITLE "resources/font/tipo.otf"

#define GRAVITY 0.3

#endif // CONFIG_H