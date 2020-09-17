#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

#ifndef MAINHEADER
#define MAINHEADER

/* Window Size*/
#define BUFFER_W 320
#define BUFFER_H 240
#define STARS_N ((BUFFER_W / 2) - 1)
#define DISP_SCALE 3
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)

/*ship and aliens*/
#define SHIP_W 12
#define SHIP_H 13
#define SHIP_SHOT_W 2
#define SHIP_SHOT_H 9
#define LIFE_W 6
#define LIFE_H 6
extern const int ALIEN_W[3];
extern const int ALIEN_H[3];
#define ALIEN_BUG_W      ALIEN_W[0]
#define ALIEN_BUG_H      ALIEN_H[0]
#define ALIEN_ARROW_W    ALIEN_W[1]
#define ALIEN_ARROW_H    ALIEN_H[1]
#define ALIEN_THICCBOI_W ALIEN_W[2]
#define ALIEN_THICCBOI_H ALIEN_H[2]
#define ALIEN_SHOT_W 4
#define ALIEN_SHOT_H 4
#define EXPLOSION_FRAMES 4
#define SPARKS_FRAMES    3
long frames;
long score;
#define EXPLOSION_FRAMES 4
#define SPARKS_FRAMES    3
ALLEGRO_SAMPLE* sample_shot;
ALLEGRO_SAMPLE* sample_explode[2];

/* controls */
unsigned char key[ALLEGRO_KEY_MAX];
#define JOY_KEYS 20
#define JOY_SELECT 0
#define JOY_LEFT_ANALOG_DOWN 1
#define JOY_RIGHT_ANALOG_DOWN 2
#define JOY_START 3
#define JOY_UP 4
#define JOY_RIGHT 5
#define JOY_DOWN 6
#define JOY_LEFT 7
#define JOY_L2 8
#define JOY_R2 9
#define JOY_L1 10
#define JOY_R1 11
#define JOY_TRIANGLE 12
#define JOY_CIRCLE 13
#define JOY_X 14
#define JOY_SQUARE 15
#define JOY_HOME 16

unsigned char joy[JOY_KEYS];
typedef struct joy_stick
{
    float xpos;
    float ypos;

} joy_stick;

joy_stick joyStick;

/* Colors */
#define backgroudColor 225,222,227
#define alien0Color 191,180,143
#define alien1Color 37,38,39
#define alien2Color 58,79,65
#define shipColor 35,0,7
#define mybulletColor 114,110,117
#define alienbulletColor 138,163,153
#define blustColor 222,158,54
#define textColor 72,61,63

/*--global_functions.c--*/
ALLEGRO_FONT *fontStart,*fontStartTitle,*fontgameTitle,*fontSmall;
typedef struct SPRITES
{
    ALLEGRO_BITMAP* _sheet;

    ALLEGRO_BITMAP* ship;
    ALLEGRO_BITMAP* ship_shot[2];
    ALLEGRO_BITMAP* life;

    ALLEGRO_BITMAP* alien[3];
    ALLEGRO_BITMAP* alien_shot;

    ALLEGRO_BITMAP* explosion[EXPLOSION_FRAMES];
    ALLEGRO_BITMAP* sparks[SPARKS_FRAMES];

    ALLEGRO_BITMAP* powerup[4];
} SPRITES;
SPRITES sprites;
ALLEGRO_DISPLAY* disp;

/*--start_screen.c--*/
int selectMenuItem;
int select;
ALLEGRO_AUDIO_STREAM* startMusic;
ALLEGRO_SAMPLE* bow_fire_arrow;

/*--ship.c --*/
typedef struct SHIP
{
    int x, y;
    int shot_timer;
    int lives;
    int respawn_timer;
    int invincible_timer;
} SHIP;
SHIP ship;

/* -- game.c -- */
int milliseconds;
int seconds;
int minutes;
int hours;

bool isGamePlay;
bool closeGame;
#endif
