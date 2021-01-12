#include <iostream>
#include "Carte.h"
#include <string>
#include <fstream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <stdbool.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

using namespace std;



int main()
{
    //Load map carte1.txt carte2.txt carte3.txt
    Carte c("carte2.txt");
    c.afficheCarte();
   // cout << c.getObjRamass().size() << endl;
   // cout << c.getGuer().getP().getX();
   // cout << c.getGuer().getP().getY() << endl;
   // cout << c.checkDeplacement(c.getGuer(), Carte::RIGHT) << endl;
    //cout << c.checkDeplacement(c.getGuer(), Carte::LEFT) << endl;
   // cout << c.checkDeplacement(c.getGuer(), Carte::UP) << endl;
    //cout << c.checkDeplacement(c.getGuer(), Carte::DOWN) << endl;

    /*
    c.deplacer(c.getGuer(), Carte:: RIGHT);
    cout << c.getGuer().getP().getX();
    cout << c.getGuer().getP().getY() << endl;
    cout << c.ramassable(c.getGuer()) << endl;
    c.deplacer(c.getGuer(), Carte:: RIGHT);
    cout << c.getGuer().getP().getX();
    cout << c.getGuer().getP().getY() << endl;

    cout << c.ramassable(c.getGuer()) << "main" << endl;
    c.ramasser(c.getGuer());
    c.afficheCarteInt();
    cout << c.getObjRamass().size() << endl;
    cout << c.getGuer().getPDV();
    */

    // constant
    const char *WINDOW_TITLE = " ANTMAN_GAME ";
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int FPS = 10;
    bool quitGame = false;
    bool firstMove = true;
    bool done = false;
    const int tileSize = 32;

    // ALLEGRO stuff
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_KEYBOARD_STATE keyState;

    ALLEGRO_BITMAP *obstacle;
    ALLEGRO_BITMAP *guerrier1;
    ALLEGRO_BITMAP *guerrier2;
    ALLEGRO_BITMAP *obstacle_ram1;
    ALLEGRO_BITMAP *obstacle_ram2;
    ALLEGRO_BITMAP *obstacle_ram3;
    ALLEGRO_BITMAP *obstacle_ram4;
    ALLEGRO_BITMAP *obstacle_ram5;
    ALLEGRO_BITMAP *obstacle_ram6;
    ALLEGRO_BITMAP *obstacle_ram7;
    ALLEGRO_BITMAP *obstacle_ram8;
    ALLEGRO_BITMAP *obstacle_ram9;

    ALLEGRO_FONT *font;
    ALLEGRO_FONT *font1;

    // Create display
    if(!al_init())
    {
        al_show_native_message_box(NULL,NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
        return -1;
    }
    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    display = al_create_display(800,600);
    al_set_window_title(display, "ANTMAN_RPG");

    if(!display)
    {
        al_show_native_message_box(display, "Sample Title", "Display Settings", "Display Window was not created succesfully", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    al_set_window_title(display, WINDOW_TITLE);

    // install allegro components and initialize the addons
    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    // Create the core allegro components
    timer = al_create_timer(1.0/FPS);
    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    // load ressources
    obstacle = al_load_bitmap("image/brick.png");

    obstacle_ram1 = al_load_bitmap("image/1.png");
    obstacle_ram2 = al_load_bitmap("image/2.png");
    obstacle_ram3 = al_load_bitmap("image/3.png");
    obstacle_ram4 = al_load_bitmap("image/4.png");
    obstacle_ram5 = al_load_bitmap("image/5.png");
    obstacle_ram6 = al_load_bitmap("image/6.png");
    obstacle_ram7 = al_load_bitmap("image/7.png");
    obstacle_ram8 = al_load_bitmap("image/8.png");
    obstacle_ram9 = al_load_bitmap("image/9.png");

    guerrier1 = al_load_bitmap("image/player.png");
    guerrier2 = al_load_bitmap("image/player2.png");
    font = al_load_font("arial.ttf", 16, NULL);
    font1 = al_load_font("Orbitron Black.ttf", 32, NULL);

    al_start_timer(timer);
    while(!quitGame)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);

        if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            quitGame = true;
        }
        if(events.type == ALLEGRO_KEY_DOWN && events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            quitGame = true;
        }


        if(events.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if(!done)
            {
            switch(events.keyboard.keycode)
            {
                case ALLEGRO_KEY_DOWN:
                    if(c.rencontreAd(c.getGuer())){
                       c.attaque(c.getGuer(),c.getGuerEnemy(),Carte::DOWN);
                       c.checkDeplacement(c.getGuer(),Carte::DOWN);
                       c.deplacer(c.getGuer(),Carte::DOWN);
                    }else if(c.ramassable(c.getGuer()) && c.checkDeplacement(c.getGuer(),Carte::DOWN)){
                       c.ramasser(c.getGuer());
                       c.checkDeplacement(c.getGuer(),Carte::DOWN);
                       c.deplacer(c.getGuer(),Carte::DOWN);
                    }else{
                        c.checkDeplacement(c.getGuer(),Carte::DOWN);
                        c.deplacer(c.getGuer(),Carte::DOWN);
                        cout << c.getGuer().getP().getX();
                        cout << c.getGuer().getP().getY() << endl;
                    }
                    break;
                case ALLEGRO_KEY_UP:
                    if(c.rencontreAd(c.getGuer())){
                       c.attaque(c.getGuer(),c.getGuerEnemy(),Carte::UP);
                       c.checkDeplacement(c.getGuer(),Carte::UP);
                       c.deplacer(c.getGuer(),Carte::UP);
                    }else if(c.ramassable(c.getGuer()) &&   c.checkDeplacement(c.getGuer(),Carte::UP)){
                       c.ramasser(c.getGuer());
                       c.checkDeplacement(c.getGuer(),Carte::UP);
                       c.deplacer(c.getGuer(),Carte::UP);
                    }else{
                        c.checkDeplacement(c.getGuer(),Carte::UP);
                        c.deplacer(c.getGuer(),Carte::UP);
                        cout << c.getGuer().getP().getX();
                        cout << c.getGuer().getP().getY() << endl;
                    }
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if(c.rencontreAd(c.getGuer())){
                       c.attaque(c.getGuer(),c.getGuerEnemy(), Carte::RIGHT);
                       c.checkDeplacement(c.getGuer(),Carte::RIGHT);
                       c.deplacer(c.getGuer(),Carte::RIGHT);
                    }else if(c.ramassable(c.getGuer()) &&   c.checkDeplacement(c.getGuer(),Carte::RIGHT)){
                       c.ramasser(c.getGuer());
                       c.checkDeplacement(c.getGuer(),Carte::RIGHT);
                       c.deplacer(c.getGuer(),Carte::RIGHT);
                    }else{
                        c.checkDeplacement(c.getGuer(),Carte::RIGHT);
                        c.deplacer(c.getGuer(),Carte::RIGHT);
                        cout << c.getGuer().getP().getX();
                        cout << c.getGuer().getP().getY() << endl;
                    }
                    break;
                case ALLEGRO_KEY_LEFT:
                    if(c.rencontreAd(c.getGuer())){
                       c.attaque(c.getGuer(),c.getGuerEnemy(),Carte::LEFT);
                       c.checkDeplacement(c.getGuer(),Carte::LEFT);
                       c.deplacer(c.getGuer(),Carte::LEFT);
                    }else if(c.ramassable(c.getGuer()) && c.checkDeplacement(c.getGuer(),Carte::LEFT)){
                       c.ramasser(c.getGuer());
                       c.checkDeplacement(c.getGuer(),Carte::LEFT);
                       c.deplacer(c.getGuer(),Carte::LEFT);
                    }else{
                        c.checkDeplacement(c.getGuer(),Carte::LEFT);
                        c.deplacer(c.getGuer(),Carte::LEFT);
                        cout << c.getGuer().getP().getX();
                        cout << c.getGuer().getP().getY() << endl;
                    }
                    break;
                case ALLEGRO_KEY_W:
                    c.briser(Carte::UP);
                    break;
                case ALLEGRO_KEY_S:
                    c.briser(Carte::DOWN);
                    break;
                case ALLEGRO_KEY_D:
                    c.briser(Carte::RIGHT);
                    break;
                case ALLEGRO_KEY_A:
                    c.briser(Carte::LEFT);
                    break;
                }
            }
            //al_draw_textf(font,al_map_rgb(255,255,255), 340, 340, ALLEGRO_ALIGN_CENTRE, "YOU LOSE!");
        }
        al_draw_textf(font,al_map_rgb(255,255,255), 460, 10, ALLEGRO_ALIGN_CENTRE, "Guerrier - Point de vie: %i", c.getGuer().getPDV());
        al_draw_textf(font,al_map_rgb(255,255,255), 460, 40, ALLEGRO_ALIGN_CENTRE, "Guerrier - Capacite Attaque: %i", c.getGuer().getCA());
        al_draw_textf(font,al_map_rgb(255,255,255), 460, 70, ALLEGRO_ALIGN_CENTRE, "Guerrier - Capacite Defense: %i", c.getGuer().getCD());

        al_draw_textf(font,al_map_rgb(255,255,255), 470, 150, ALLEGRO_ALIGN_CENTRE, "Guerrier Enemy - Point de vie: %i", c.getGuerEnemy().getPDV());
        al_draw_textf(font,al_map_rgb(255,255,255), 470, 180, ALLEGRO_ALIGN_CENTRE, "Guerrier Enemy - Capacite Attaque: %i", c.getGuerEnemy().getCA());
        al_draw_textf(font,al_map_rgb(255,255,255), 470, 210, ALLEGRO_ALIGN_CENTRE, "Guerrier Enemy - Capacite Defense: %i", c.getGuerEnemy().getCD());

         //draw
        for(int i = 0; i < c.getLargeur(); i++)
        {
            for(int j = 0; j < c.getHauteur(); j++)
            {
                if(c.mazeInt[i][j] == 35)
                {
                al_draw_bitmap(obstacle,j*tileSize,i*tileSize, NULL);
                }

                if(c.mazeInt[i][j] >= 49 && c.mazeInt[i][j] <= 57)
                {
                switch(c.mazeInt[i][j] - 48){
                    case 1:
                    al_draw_bitmap(obstacle_ram1,j*tileSize, i*tileSize, NULL);
                    break;
                    case 2:
                    al_draw_bitmap(obstacle_ram2,j*tileSize, i*tileSize, NULL);
                    break;
                    case 3:
                    al_draw_bitmap(obstacle_ram3,j*tileSize, i*tileSize, NULL);
                    break;
                    case 4:
                    al_draw_bitmap(obstacle_ram4,j*tileSize, i*tileSize, NULL);
                    break;
                    case 5:
                    al_draw_bitmap(obstacle_ram5,j*tileSize, i*tileSize, NULL);
                    break;
                    case 6:
                    al_draw_bitmap(obstacle_ram6,j*tileSize, i*tileSize, NULL);
                    break;
                    case 7:
                    al_draw_bitmap(obstacle_ram7,j*tileSize, i*tileSize, NULL);
                    break;
                    case 8:
                    al_draw_bitmap(obstacle_ram8,j*tileSize, i*tileSize, NULL);
                    break;
                    case 9:
                    al_draw_bitmap(obstacle_ram9,j*tileSize, i*tileSize, NULL);
                    break;
                }

                }

                if(c.mazeInt[i][j] == 83)
                {
                al_draw_bitmap(guerrier1,j*tileSize, i*tileSize, NULL);
                }

                if(c.mazeInt[i][j] == 67)
                {
                al_draw_bitmap(guerrier2,j*tileSize, i*tileSize, NULL);
                }

            }
        }

        if(c.getGuer().getPDV() <= 0)
        {
            al_draw_textf(font1,al_map_rgb(255,255,255), 160, 160, ALLEGRO_ALIGN_CENTRE, "YOU LOSE!");
            done = true;

        }else if(c.getGuerEnemy().getPDV() <= 0){
            al_draw_textf(font1,al_map_rgb(255,255,255), 160, 160, ALLEGRO_ALIGN_CENTRE, "YOU WIN!");
            done = true;
        }


        //al_draw_textf(font,al_map_rgb(255,0,255), )
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));

    }

    al_destroy_bitmap(obstacle);
    al_destroy_bitmap(guerrier1);
    al_destroy_bitmap(guerrier2);
    al_destroy_bitmap(obstacle_ram1);
    al_destroy_bitmap(obstacle_ram2);
    al_destroy_bitmap(obstacle_ram3);
    al_destroy_bitmap(obstacle_ram4);
    al_destroy_bitmap(obstacle_ram5);
    al_destroy_bitmap(obstacle_ram6);
    al_destroy_bitmap(obstacle_ram7);
    al_destroy_bitmap(obstacle_ram8);
    al_destroy_bitmap(obstacle_ram9);

    al_destroy_font(font);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    return 0;
}
