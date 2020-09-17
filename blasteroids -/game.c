#include "header_global.h"
#include "header_prototypes.h"

const int ALIEN_W[3] = {14, 13, 45};
const int ALIEN_H[3] = { 9, 10, 27};

int main()
{
    milliseconds = 0;
    seconds = 0;
    minutes = 0;
    hours = 0;
    isGamePlay = 0;

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_install_joystick(), "joyStick");
    must_init(al_init_font_addon(),"font addon");
    must_init(al_init_ttf_addon(),"ttf font addon");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    disp_init();

    audio_init();

    must_init(al_init_image_addon(), "image");
    sprites_init();

    hud_init();

    must_init(al_init_primitives_addon(), "primitives");

    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(16), "reserve samples");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_joystick_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    init_start_screen();

    keyboard_init();

    joystick_init();

    fx_init();
    shots_init();
    ship_init();
    aliens_init();
    stars_init();

    frames = 0;
    score = 0;

    closeGame = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);

    global_fonts();

    while(1) // main game loop
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            if(isGamePlay)
            {
                fx_update();
                shots_update();
                stars_update();
                ship_update();
                aliens_update();

                if(ship.lives>=0)
                    milliseconds ++;

                if(milliseconds > 60)
                {
                    milliseconds = 0;
                    seconds++;
                    if(seconds > 59)
                    {
                        seconds = 0;
                        minutes++;
                        if(minutes >59)
                        {
                            minutes = 0;
                            hours++;
                            if(hours > 99)
                            {
                                ship.lives = -1; //kill ship
                            }
                        }
                    }
                }

                hud_update();

                if(key[ALLEGRO_KEY_ESCAPE])
                {
                    closeGame = true;
                }
            }

            redraw = true;
            frames++;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            closeGame = true;
            break;
        }

        if(closeGame)
            break;

        keyboard_update(&event);
        joystick_update(&event);

        if(!isGamePlay)   // run code below only when game isn't playing
        {
            off_play_input();
        }


        if(redraw && al_is_event_queue_empty(queue))
        {
            if(!isGamePlay)
                draw_start_screen();
            else
            {
                disp_pre_draw();
                al_clear_to_color(al_map_rgb(backgroudColor));

                stars_draw();
                aliens_draw();
                shots_draw();
                fx_draw();
                ship_draw();

                hud_draw();

                disp_post_draw();
            }
            redraw = false;
        }
    }

    sprites_deinit();
    hud_deinit();
    audio_deinit();
    disp_deinit();
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}
