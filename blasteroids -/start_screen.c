#include "header_global.h"
#include "header_prototypes.h"

typedef struct menuItem
{
    float x;
    float y;
} menuItemCord;

menuItemCord menuCords[4] = {{0.65,0.35},{0.65,0.45},{0.65,0.55},{0.65,0.65}};

ALLEGRO_BITMAP* _sheet ;

void init_start_screen()
{

    bow_fire_arrow = al_load_sample("data/sounds/bow_fire_arrow.wav");
    must_init(bow_fire_arrow, "bow_fire_arrow");

    startMusic = al_load_audio_stream("data/sounds/blazer_rail.wav", 2, 2048);
    must_init(startMusic, "startMusic");
    al_set_audio_stream_playmode(startMusic, ALLEGRO_PLAYMODE_LOOP);
    al_attach_audio_stream_to_mixer(startMusic, al_get_default_mixer());

   _sheet = al_load_bitmap("data/sprites/spritesheet.png");
    must_init(_sheet, "spritesheet.png in start_screen.c");
}

int selectMenuItem = 0;
int select = 3;

float alienPosi = DISP_H*0.4;
int  borderFlag = 1;

void draw_start_screen()
{
    int triangleBase = 30;
    int triangleHeight = 30;

    al_clear_to_color(al_map_rgb(backgroudColor));

    if(selectMenuItem == 0)
    {
        al_draw_text(fontgameTitle, al_map_rgb(textColor), DISP_W*0.05, DISP_H*0.25, 0, "B L A S T E R O I D S");
        al_draw_tinted_scaled_bitmap(al_create_sub_bitmap(_sheet,0, 21, ALIEN_THICCBOI_W, ALIEN_THICCBOI_H), al_map_rgb(alien0Color),0, 0, ALIEN_THICCBOI_W,
                                     ALIEN_THICCBOI_H, DISP_W*0.05, alienPosi, ALIEN_THICCBOI_W*10,
                                      ALIEN_THICCBOI_H*10, 0);

        if(borderFlag == 1)
        {
            alienPosi-= 3;
        } else
        {
            alienPosi+= 3;
        }

        if(alienPosi < DISP_H*0.25 + 50)
        {
            borderFlag = 0;
        }
        if(alienPosi > DISP_H*0.6)
        {
            borderFlag = 1;
        }

        al_draw_text(fontStartTitle, al_map_rgb(textColor), DISP_W*0.7, DISP_H*0.25, 0, "M E N U");
        al_draw_text(fontStart, al_map_rgb(textColor),DISP_W*menuCords[0].x,DISP_H*menuCords[0].y,
                      0, "SETTINGS");
        al_draw_text(fontStart, al_map_rgb(textColor),DISP_W*menuCords[1].x,DISP_H*menuCords[1].y,
                      0, "SINGLE PLAYER");
        al_draw_text(fontStart, al_map_rgb(textColor),DISP_W*menuCords[2].x,DISP_H*menuCords[2].y,
                      0, "MULTI-PLAYER");
        al_draw_text(fontStart, al_map_rgb(textColor),DISP_W*menuCords[3].x,DISP_H*menuCords[3].y,
                      0, "SCORE BOARD");

        al_draw_filled_triangle(DISP_W*menuCords[select].x-triangleHeight, DISP_H*menuCords[select].y,
                                 DISP_W*menuCords[select].x, DISP_H*menuCords[select].y+triangleBase/2,
                                 DISP_W*menuCords[select].x-triangleHeight, DISP_H*menuCords[select].y+triangleBase,
                                 al_map_rgb(46, 64, 83));
    }else if(selectMenuItem == 3)
    {
        generateScoreBoard();
    }

    al_flip_display();
}
