
#ifndef PROTOTYPESHEADER
#define PROTOTYPESHEADER

/*--global_variables_functions.c--*/
void must_init(bool test, const char *description);
void global_fonts();
void sprites_init();
void sprites_deinit();
int between(int lo, int hi);
float between_f(float lo, float hi);
bool collide(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);
void audio_init();
void audio_deinit();
void fx_init();
void fx_add(bool spark, int x, int y);
void fx_update();
void fx_draw();
void disp_init();
void disp_deinit();
void disp_pre_draw();
void disp_post_draw();
void keyboard_init();
void keyboard_update(ALLEGRO_EVENT* event);
void joystick_init();
void joystick_update(ALLEGRO_EVENT* event);
void off_play_input();

/*--score_board.c--*/
void generateScoreBoard();

/*--start_screen.c--*/
void init_start_screen();
void draw_start_screen();

/*-- aliens.c --*/
void aliens_draw();
void aliens_update();
void aliens_init();

/*-- ship.c --*/
void ship_draw();
void ship_update();
void ship_init();

/*-- single_player.c */
void shots_init();
bool shots_add(bool ship, bool straight, int x, int y);
void shots_update();
bool shots_collide(bool ship, int x, int y, int w, int h);
void shots_draw();
void hud_init();
void hud_deinit();
void hud_update();
void hud_draw();

/* sky.c */
void stars_init();
void stars_update();
void stars_draw();

/* game.c */
void fx_add(bool spark, int x, int y);

#endif // PROTOTYPESHEADER
