# include <stdio.h>
# include <stdlib.h>
# include <windows.h>
# include <conio.h>
# include <unistd.h>
# include <time.h>
// # include "lib.h"

// // green   \e[0;32m
// // yellow  \e[4;33m
// // blue    \e[4;34m
// // purple  \e[4;35m
// // red     \e[0;31m
// // bold    \x1b[1m
// // no line \e[4;24m
// // reset   \x1b[0m

typedef struct plane 
{
    short x ;
    short y ;
    short health ;
    short damage ;

}plane_ ;

typedef struct bullets 
{
    short x ;
    short y ;
    short damage ;
    short flag ;
}bullets ;

plane_ plane ;
plane_ bomber ;
plane_ drone ;
plane_ barbar ;
plane_ fighter ;
bullets arr_bullets[8] ;
bullets arr_fighter_bullet[5] ;
bullets arr_mines[6] ;
bullets arr_bar[3] ;

bullets bomb ;
bullets boom ;
bullets fire_ ;

short bullet_num = 5 ;
short fighter_bullet_num = 4 ;
short mine_num = 4 ;
short bar_num = 3 ;
int score ;
// حالت معمولی
int level = 2;
short speed = 3 ;
short chance = 6 ;
short frame_width = 156 ;
short frame_height = 38 ;

short bullet_damage ;
// menu and stuff
void intro () ;
void main_menu() ;
void pakkon() ;


void move (short y , short x ) ;
// printing stuff
void print_frame() ;

void print_lose() ;

void health_show( short plae_health);
void score_show() ;
void damage_bullet_show( short bullet_damage) ;

void print_lose() ;

void print_plane(short y , short x) ;
void clear_plane(short y , short x) ;

void print_mine(short y , short x) ;
void clear_mine(short y , short x) ;

void print_bullet(short y , short x) ;
void clear_bullet(short y , short x) ;

void print_bomber(short y , short x , short bomber_health) ;
void clear_bomber(short y , short x) ;

void print_bomb(short y , short x) ;
void clear_bomb(short y , short x) ;

void print_fighter(short y , short x , short fighter_health) ;
void clear_fighter(short y , short x) ;

void print_fighter_bullet(short y , short x ) ;
void clear_fighter_bullet(short y , short x ) ;

void print_drone( short y , short x , short drone_health) ;
void clear_drone( short y , short x ) ;

void print_barbar( short y , short x  , short barbar_health) ;
void clear_barbar( short y , short x ) ;

void print_bar( short y , short x) ;
void clear_bar( short y , short x) ;
// till here



void save_name () ;
// maybe in menu.h
void mini_menu (int * choice) ;

void add_explosion( short y , short x) ;
void explosion() ;

void add_fire () ;
void fire() ;

void input () ;

void add_mine() ;
void mine_movment() ;

void add_bullet() ;
void bullet_movment() ;

void add_bomber() ;
void bomber_movment() ;
void add_bomb() ;
void bomb_movment() ;

void add_fighter() ;
void fighter_movment() ;
void add_fighter_bullet() ;
void fighter_bullet_movment() ;

void add_drone() ;
void drone_movment() ;

void add_barbar() ;
void barbar_movment() ;
void add_bar() ;
void bar_movment() ;

void initialize() ;
void spawn() ;
void update() ;
void difficultly() ;




int main () 
{
    // time for openning in fullscreen
    usleep(3000000);
    // hiding the cursor
    printf("\e[?25l") ;
    intro() ;
    int choice = 0 ;
    while (1){
        system("cls") ;
        if ( choice == 0){
            main_menu() ;
        }
        initialize() ;
        difficultly() ;
        print_frame() ;
        health_show(plane.health) ;
        damage_bullet_show(bullet_damage) ;
        score_show(score);
        print_plane(plane.y , plane.x) ;
        long long i = 0 ;
        while( plane.health > 0){
            input ( ) ;
            spawn (i)  ;
            update(i) ;
            usleep(1000) ;
            i++ ;
        }
        print_lose() ;
        system("cls") ;
        save_name() ;
        mini_menu(&choice) ;
    }
    usleep(3000000) ;
    printf("\e[?25l") ;
}





// menu and stuff delete
void intro (){
    char keyopen ;
    int timer = 90000 ;
    printf("\n\n\n\n\n\n\n\n\n") ;
    printf("                                                              _______  ___      ___                                              \n"); 
    usleep(timer) ;                     
    printf("                                                             |   _   ||   |    |   |           BASIC PROGRAMING project         \n"); 
    usleep(timer) ;                     
    printf("                                                             |  |_|  ||   |    |   |                                           \n"); 
    usleep(timer) ;                     
    printf("                                                             |       ||   |    |   |                                              \n"); 
    usleep(timer) ;                     
    printf("                                                             |       ||   |___ |   |                                             \n"); 
    usleep(timer) ;                     
    printf("                                                             |   _   ||       ||   |                                              \n");
    usleep(timer) ;                      
    printf("                                                             |__| |__||_______||___|                                             \n"); 
    usleep(timer) ;                     
    printf("                                            __   __  _______  __   __  _______  __   __  __   __  _______  ______   ___          \n"); 
    usleep(timer) ;                     
    printf("                                           |  |_|  ||       ||  | |  ||   _   ||  |_|  ||  |_|  ||   _   ||      | |   |         \n"); 
    usleep(timer) ;                     
    printf("                                           |       ||   _   ||  |_|  ||  |_|  ||       ||       ||  |_|  ||  _    ||   |         \n"); 
    usleep(timer) ;                     
    printf("                                           |       ||  | |  ||       ||       ||       ||       ||       || | |   ||   |         \n"); 
    usleep(timer) ;                     
    printf("                                           |       ||  |_|  ||       ||       ||       ||       ||       || |_|   ||   |         \n"); 
    usleep(timer) ;                     
    printf("                                           | ||_|| ||       ||   _   ||   _   || ||_|| || ||_|| ||   _   ||       ||   |         \n"); 
    usleep(timer) ;                     
    printf("                                           |_|   |_||_______||__| |__||__| |__||_|   |_||_|   |_||__| |__||______| |___|         \n"); 
    usleep(timer) ;                     
    printf("                                                    _   ___  _______  _______  _______  ____   _______  _   ___   _____           \n"); 
    usleep(timer) ;                     
    printf("                                                   | | |   ||  _    ||       ||       ||    | |  _    || | |   | |  _  |         \n"); 
    usleep(timer) ;                     
    printf("                                                   | |_|   || | |   ||____   ||___    | |   | | | |   || |_|   | | |_| |          \n");
    usleep(timer) ;                      
    printf("                                                   |       || | |   | ____|  | ___|   | |   | | | |   ||       ||   _   |        \n");
    usleep(timer) ;                     
    printf("                                                   |___    || |_|   || ______||___    | |   | | |_|   ||___    ||  | |  |        \n");
    usleep(timer) ;                     
    printf("                                                       |   ||       || |_____  ___|   | |   | |       |    |   ||  |_|  |        \n");
    usleep(timer) ;                     
    printf("                                                       |___||_______||_______||_______| |___| |_______|    |___||_______|        \n\n");
    printf("                                                              PRESS  SPACE TO CONTINUE                                         \n\n\n");
    usleep(timer) ;
    while(1){
        keyopen = getch() ;
        if ( keyopen == ' '){
            break;
        } 
    }
    
    printf("\033[2J\033[1;1H");
    printf("\n\n\n\n\n\n\n\n\n\n\n") ;
    printf("                                                                 d8888 888     888 88888888888                                \n");            
    printf("                                                                d88888 888     888     888                                    \n");            
    printf("                                                               d88P888 888     888     888                                    \n");            
    printf("                                                              d88P 888 888     888     888                                    \n");            
    printf("                                                             d88P  888 888     888     888                                    \n");            
    printf("                                                            d88P   888 888     888     888                                    \n");            
    printf("                                                           d8888888888 Y88b. .d88P     888                                    \n");            
    printf("                                                          d88P     888   Y88888P       888                                    \n");            
    printf("                                                                                                                                 \n");                                  
    printf("                                                       88888880          d8888 8888888 88888880                                  \n");           
    printf("                                                       888   Y88b       d88888   888   888  Y88b                                 \n");           
    printf("                                                       888    888      d88P888   888   888    888                                \n");            
    printf("                                                       888   d88P     d88P 888   888   888    888                                \n");            
    printf("                                                       88888889      d88P  888   888   888    888                                \n");            
    printf("                                                       888 T88b     d88P   888   888   888    888                                \n");            
    printf("                                                       888  T88b   d8888888888   888   888  .d88P                                \n");            
    printf("                                                       888   T88b d88P     888 8888888 88888889                                  \n");   
    printf("                                                                                                                                 \n");      
    printf("                                                               PRESS  SPACE TO CONTINUE                                         \n\n\n");
    while(1){
        keyopen = getch() ;
        if ( keyopen == ' '){
            break;
        } 
    }
}

void pakkon (){
    for ( int i = 0 ; i < 40 ; i++){
        for ( int j = 82 ; j < 156 ; j++){
            move( i , j) ;
            printf(" ") ;
        }
    }
}

void main_menu (){
        printf("\033[2J\033[1;1H");
    for ( int i = 0 ; i < 40 ; i++){
        move( i , 80) ;
        printf("[]") ;
    }   
    move(9 , 0) ;
            printf("                            ____  __     ___  _  _           \n");
            printf("                            || \\\\ ||    // \\\\ \\\\//     \n");
            printf("                            ||_// ||    ||=||  )/            \n");
            printf("                            ||    ||__| || || //             \n");
            printf("                                                             \n");
            printf("                            __     ____ __ __  ____ __       \n");
            printf("                            ||    ||    || || ||    ||       \n");
            printf("                            ||    ||==  \\\\ // ||==  ||     \n");
            printf("                            ||__| ||___  \\V/  ||___ ||__|   \n");
            printf("                                                             \n");
            printf("                            __      ___     ___   __         \n");
            printf("                            ||     // \\\\   // \\\\ (( \\\\ \n");
            printf("                            ||    ((   )) (( ___  \\\\       \n");
            printf("                            ||__|  \\\\_//   \\\\_|| \\\\_)) \n"); 
            printf("                                                             \n");
            printf("                            __ __  __  ____   ___            \n");
            printf("                            || ||\\ || ||     // \\\\        \n");
            printf("                            || ||\\\\|| ||==  ((   ))        \n");
            printf("                            || || \\|| ||     \\\\_//        \n");
            printf("                                                             \n");
            printf("                             ____ _   _ __ ______            \n");
            printf("                            ||    \\\\ // || | || |          \n");
            printf("                            ||==   )X(  ||   ||              \n");
            printf("                            ||___ // \\\\ ||   ||            \n");
    int cnt = 10000001 ;
    char inp ;
    while (1){
        inp = getch();
        if ( inp == 's'){
            cnt++ ;}
        else if ( inp == 'w'){
            cnt-- ;}
        if ( cnt%5 == 0){
            move( 9 , 0) ;
            printf("          \e[0;35m\x1b[1m                  ____  __     ___  _  _ \n");
            printf("                            || \\\\ ||    // \\\\ \\\\//          \n");
            printf("                            ||_// ||    ||=||  )/                 \n");
            printf("                            ||    ||__| || || //       \x1b[0m    \n");
            printf("                                                                  \n");
            printf("                            __     ____ __ __  ____ __            \n");
            printf("                            ||    ||    || || ||    ||            \n");
            printf("                            ||    ||==  \\\\ // ||==  ||          \n");
            printf("                            ||__| ||___  \\V/  ||___ ||__|        \n");
            printf("                                                                  \n");
            printf("                            __      ___     ___   __              \n");
            printf("                            ||     // \\\\   // \\\\ (( \\\\      \n");
            printf("                            ||    ((   )) (( ___  \\\\            \n");
            printf("                            ||__|  \\\\_//   \\\\_|| \\\\_))      \n");
            printf("                                                                  \n");
            printf("                            __ __  __  ____   ___                 \n");
            printf("                            || ||\\ || ||     // \\\\             \n");
            printf("                            || ||\\\\|| ||==  ((   ))             \n");
            printf("                            || || \\|| ||     \\\\_//             \n");
            printf("                                                                  \n");
            printf("                             ____ _   _ __ ______                 \n");
            printf("                            ||    \\\\ // || | || |               \n");
            printf("                            ||==   )X(  ||   ||                   \n");
            printf("                            ||___ // \\\\ ||   ||                 \n");
        }
        else if ( cnt%5 == 1){
            move(9,0) ;
            printf("                            ____  __     ___  _  _                    \n");
            printf("                            || \\\\ ||    // \\\\ \\\\//              \n");
            printf("                            ||_// ||    ||=||  )/                     \n");
            printf("                            ||    ||__| || || //                      \n");
            printf("                                                                      \n");
            printf("          \e[0;35m\x1b[1m                  __     ____ __ __  ____ __ \n");
            printf("                            ||    ||    || || ||    ||                \n");
            printf("                            ||    ||==  \\\\ // ||==  ||              \n");
            printf("                            ||__| ||___  \\V/  ||___ ||__|  \x1b[0m   \n");
            printf("                                                                      \n");
            printf("                            __      ___     ___   __                  \n");
            printf("                            ||     // \\\\   // \\\\ (( \\\\          \n");
            printf("                            ||    ((   )) (( ___  \\\\                \n");
            printf("                            ||__|  \\\\_//   \\\\_|| \\\\_))          \n");
            printf("                                                                      \n");
            printf("                            __ __  __  ____   ___                     \n");
            printf("                            || ||\\ || ||     // \\\\                 \n");
            printf("                            || ||\\\\|| ||==  ((   ))                 \n");
            printf("                            || || \\|| ||     \\\\_//                 \n");
            printf("                                                                      \n");
            printf("                             ____ _   _ __ ______                     \n");
            printf("                            ||    \\\\ // || | || |                   \n");
            printf("                            ||==   )X(  ||   ||                       \n");
            printf("                            ||___ // \\\\ ||   ||                     \n");
        }    
        else if ( cnt%5 == 2){
            move(9 ,0) ;
            printf("                            ____  __     ___  _  _                    \n");
            printf("                            || \\\\ ||    // \\\\ \\\\//              \n");
            printf("                            ||_// ||    ||=||  )/                     \n");
            printf("                            ||    ||__| || || //                      \n");
            printf("                                                                      \n");
            printf("                            __     ____ __ __  ____ __                \n");
            printf("                            ||    ||    || || ||    ||                \n");
            printf("                            ||    ||==  \\\\ // ||==  ||              \n");
            printf("                            ||__| ||___  \\V/  ||___ ||__|            \n");
            printf("                                                                      \n");
            printf("   \e[0;35m\x1b[1m                         __      ___     ___   __   \n");
            printf("                            ||     // \\\\   // \\\\ (( \\\\          \n");
            printf("                            ||    ((   )) (( ___  \\\\                \n");
            printf("                            ||__|  \\\\_//   \\\\_|| \\\\_)) \x1b[0m  \n");
            printf("                                                                      \n");
            printf("                            __ __  __  ____   ___                     \n");
            printf("                            || ||\\ || ||     // \\\\                 \n");
            printf("                            || ||\\\\|| ||==  ((   ))                 \n");
            printf("                            || || \\|| ||     \\\\_//                 \n");
            printf("                                                                      \n");
            printf("                             ____ _   _ __ ______                     \n");
            printf("                            ||    \\\\ // || | || |                   \n");
            printf("                            ||==   )X(  ||   ||                       \n");
            printf("                            ||___ // \\\\ ||   ||                     \n");
        }
        else if ( cnt%5 == 3){
            move(9 , 0) ;
            printf("                            ____  __     ___  _  _                    \n");
            printf("                            || \\\\ ||    // \\\\ \\\\//              \n");
            printf("                            ||_// ||    ||=||  )/                     \n");
            printf("                            ||    ||__| || || //                      \n");
            printf("                                                                      \n");
            printf("                            __     ____ __ __  ____ __                \n");
            printf("                            ||    ||    || || ||    ||                \n");
            printf("                            ||    ||==  \\\\ // ||==  ||              \n");
            printf("                            ||__| ||___  \\V/  ||___ ||__|            \n");
            printf("                                                                      \n");
            printf("                            __      ___     ___   __                  \n");
            printf("                            ||     // \\\\   // \\\\ (( \\\\          \n");
            printf("                            ||    ((   )) (( ___  \\\\                \n");
            printf("                            ||__|  \\\\_//   \\\\_|| \\\\_))          \n");
            printf("                                                                      \n");
            printf("    \e[0;35m\x1b[1m                        __ __  __  ____   ___      \n");
            printf("                            || ||\\ || ||     // \\\\                 \n");
            printf("                            || ||\\\\|| ||==  ((   ))                 \n");
            printf("                            || || \\|| ||     \\\\_//      \x1b[0m    \n");
            printf("                                                                      \n");
            printf("                             ____ _   _ __ ______                     \n");
            printf("                            ||    \\\\ // || | || |                   \n");
            printf("                            ||==   )X(  ||   ||                       \n");
            printf("                            ||___ // \\\\ ||   ||                     \n");
        }    
        else if ( cnt%5 == 4){
            move(9,0) ;
            printf("                            ____  __     ___  _  _                    \n");
            printf("                            || \\\\ ||    // \\\\ \\\\//              \n");
            printf("                            ||_// ||    ||=||  )/                     \n");
            printf("                            ||    ||__| || || //                      \n");
            printf("                                                                      \n");
            printf("                            __     ____ __ __  ____ __                \n");
            printf("                            ||    ||    || || ||    ||                \n");
            printf("                            ||    ||==  \\\\ // ||==  ||              \n");
            printf("                            ||__| ||___  \\V/  ||___ ||__|            \n");
            printf("                                                                      \n");
            printf("                            __      ___     ___   __                  \n");
            printf("                            ||     // \\\\   // \\\\ (( \\\\          \n");
            printf("                            ||    ((   )) (( ___  \\\\                \n");
            printf("                            ||__|  \\\\_//   \\\\_|| \\\\_))          \n");
            printf("                                                                      \n");
            printf("                            __ __  __  ____   ___                     \n");
            printf("                            || ||\\ || ||     // \\\\                 \n");
            printf("                            || ||\\\\|| ||==  ((   ))                 \n");
            printf("                            || || \\|| ||     \\\\_//                 \n");
            printf("                                                                      \n");
            printf("   \e[0;35m\x1b[1m                          ____ _   _ __ ______      \n");
            printf("                            ||    \\\\ // || | || |                   \n");
            printf("                            ||==   )X(  ||   ||                       \n");
            printf("                            ||___ // \\\\ ||   ||             \x1b[0m \n");
        }
        if ( inp == ' '){
            if ( cnt%5 == 0){
                printf("\033[2J\033[1;1H");
                break ;
            }
            if ( cnt%5 == 1){
                int cnt_lev = 999999 ;
                char key ;
                pakkon() ;
                move( 10 , 90 ) ;
                printf(" choose your defficultly level ") ;
                move( 11 , 90) ;
                printf("      EAZY ") ;
                move ( 12 , 90) ;
                printf("      MEDIUM") ;
                move ( 13 , 90) ;
                printf("      HARD") ;
                while (1){
                    key = getch() ;
                    if ( key == 'w' ){
                        cnt_lev-- ;
                    }
                    else if ( key == 's'){
                        cnt_lev++ ;
                    }
                    if ( cnt_lev%3 == 0) {
                        move( 10 , 90 ) ;
                        printf("choose your defficultly level ") ;
                        move( 11 , 90) ;
                        printf("====> EAZY ") ;
                        move ( 12 , 90) ;
                        printf("      MEDIUM") ;
                        move ( 13 , 90) ;
                        printf("      HARD") ;
                    }
                    else if ( cnt_lev%3 == 1){
                        move( 10 , 90 ) ;
                        printf("choose your defficultly level ") ;
                        move( 11 , 90) ;
                        printf("      EAZY ") ;
                        move ( 12 , 90) ;
                        printf("====> MEDIUM") ;
                        move ( 13 , 90) ;
                        printf("      HARD") ;
                    }
                    else if ( cnt_lev%3 == 2){
                        move( 10 , 90 ) ;
                        printf("choose your defficultly level ") ;
                        move( 11 , 90) ;
                        printf("      EAZY ") ;
                        move ( 12 , 90) ;
                        printf("      MEDIUM") ;
                        move ( 13 , 90) ;
                        printf("====> HARD") ;
                    }
                    if (key == ' '){
                        if ( cnt_lev%3 == 0) {
                            level = 1 ;
                            move( 15 , 90) ;
                            printf(" difficultly set to EASY") ;
                            break ;   

                        }
                        else if ( cnt_lev%3 == 1){
                            level = 2 ;
                            move( 15 , 90) ;
                            printf(" difficultly set to MEDIUM") ;
                            break ; 
                        }
                        else if ( cnt_lev%3 == 2){
                            level = 3 ;
                            move( 15 , 90) ;
                            printf(" difficultly set to HARD") ;
                            break ; 
                        }
                    }
                }
            }
            if ( cnt%5 == 2){
                pakkon() ;
                FILE * fpon ;
                fpon = fopen( "scores.txt" , "r") ;
                if ( fpon == NULL){
                    printf (" cant open the file ") ;
                }
                char temp ;
                int line_cnt = 0 ;
                while ( (temp = fgetc(fpon)) != EOF){
                    if ( temp == '*' ){
                        line_cnt++ ;
                    }
                }
                char buff [1000] ;
                for ( int i = 1 ; i <= line_cnt ; i++){
                    fseek(fpon , -i*67 ,SEEK_END) ;
                    fgets( buff , 1000 , fpon) ;
                    move( 1+i , 85) ;
                    printf( "%s" , buff) ;
                }
                fclose(fpon) ;
            }
            if ( cnt%5 == 3){
                pakkon() ;
                move(10 , 95) ;
                printf("You just failed basic programming , you are furious") ;
                move(11 , 95) ;
                printf("so , you decide to hack NASAs space jett and destroy") ;
                move(12 , 95) ;
                printf("AUT but your archnemesis DR.zainali is waiting for ") ;
                move(13 , 95) ;
                printf("you with his drones , GO soldier and take your revenge") ;

                move(16, 98) ;
                printf("\e[0;32m\x1b[1m|V|  your plane") ;
                move(17 , 97) ;
                printf("|| ||") ;
                move(18 , 96) ;
                printf("/     \\") ;
                move(19 , 95) ;
                printf("|--| |--|") ;
                move(20 , 97);
                printf("/|||\\\x1b[0m")  ;

                move( 16 , 120) ;
                printf("\e[0;31m /\\ mine") ;
                move( 17, 120) ;
                printf("(01)") ;
                move(18 , 120) ;
                printf(" \\/\x1b[0m") ;

                move(16 , 130);
                printf("\e[0;1m\x1b[31m(-) bomb");
                move(17 , 130) ;
                printf("(-)");  
                move(18 , 130) ;
                printf("(-)\x1b[0m"); 

                move(22   ,101) ;
                printf("\x1b[1m,-.  bomber") ;
                move(23 , 91) ;
                printf("_,.      /  /") ;
                move(24 ,90) ;
                printf("; \\____,-==-._ ") ;
                move(25 ,90) ;
                printf("//_00  `----' {+>") ;
                move(26 ,90) ;
                printf("`  `'--/  /-'`") ;
                move(27 ,96) ;
                printf("/  /") ;
                move(28 ,96) ;
                printf("`='\x1b[0m") ;

                move( 22 , 120) ;
                printf("\x1b[1m\x1b[34m/ \\   / \\");
                move( 23 , 120) ;
                printf("\\  \\ /  / ");
                move( 24 , 121) ; 
                printf("\\||0||/ fighter");
                move( 25 , 122) ;
                printf("\\\\V//");
                move( 26 , 123) ;
                printf("\\./ \x1b[0m");

                move( 30 , 90 );
                printf("\e[4;35m\e[4;24m\x1b[1m /--\\ drone") ;
                move( 31 , 90) ;          
                printf("/<><>\\") ;
                move ( 32 , 90) ;               
                printf("\\<00>/") ;
                move ( 33 ,91) ;                    
                printf("\\--/\x1b[0m") ;

                move(30 ,109) ;
                printf("\e[4;35m\x1b[1m\e[4;24m________  barbar");
                move ( 31 , 106);
                printf("___\\ BACK /___");
                move ( 32 , 105);
                printf("|____\\ UP /____|");
                move ( 33 , 110);
                printf("( 00 )");
                move ( 34 , 111);
                printf("\\__/\x1b[0m");  
                
                move( 30 , 130);
                printf("\x1b[1m\e[4;24m+------+  bar") ;
                move (31 , 130) ;
                printf("|  ??  |") ;
                move( 32 , 130);
                printf("|______|\x1b[0m"); 

            }
            if ( cnt%5 == 4){
                exit(1) ;
            }
        }
    }
}

// till here

// printing 
void move (short y , short x ){
    printf("\033[%d;%dH" , y , x) ;
}

void print_frame(){
    move( 0 , 0) ;
    for ( int i = 0 ; i < frame_width ; i++ ){
        printf("=") ;
    }
    move ( frame_height+2,0);
    for ( int i = 0 ; i < frame_width ; i++ ){
        printf("=") ;
    }
    move(frame_height , 0 ) ;
    for ( int i = 0 ; i < frame_width ; i++ ){
        printf("-") ;
    }
    for ( int i = 0 ; i < frame_height+2 ; i++){
        move( i , 0) ;
        printf("|") ;
        move( i , frame_width) ;
        printf("|") ;
    }
}

void print_lose (){
    short y = (frame_height/2) - 5 ;
    short x = (frame_width/2) - 35 ;
    move (y , x) ;
    printf("\e[0;31m\x1b[1m____    ____  ______    __    __      _______   __   _______  _______ ") ;
    move ( y+1 , x) ;
    printf("\\   \\  /   / /  __  \\  |  |  |  |    |       \\ |  | |   ____||       \\ ");
    move ( y+2 , x) ;
    printf(" \\   \\/   / |  |  |  | |  |  |  |    |  .--.  ||  | |  |__   |  .--.  |");
    move ( y+3 , x) ;
    printf("  \\_    _/  |  |  |  | |  |  |  |    |  |  |  ||  | |   __|  |  |  |  |");
    move ( y+4 , x) ;
    printf("    |  |    |  `--'  | |  `--'  |    |  '--'  ||  | |  |____ |  '--'  |");
    move ( y+5 , x) ;
    printf("    |__|     \\______/   \\______/     |_______/ |__| |_______||_______/ \e[0;0m");
    usleep(2000000) ;
}



void health_show( short plane_health){
    move (frame_height + 1 , 20 ) ;
    printf ("            ") ;
    move( frame_height+1 , 20 ) ;
    printf("HEALTH : %d ",plane_health) ;    
}
void score_show(){
    score++ ;
    move (frame_height +1 , 70 ) ;
    printf("             ") ;
    move (frame_height+1 , 70) ;
    printf(" SCORE : %d", score) ;

}
void damage_bullet_show( short bullet_damage){
    move( frame_height+1 , 40) ;
    printf("                  ") ;
    move( frame_height+1 , 40) ;
    printf(" BULLET DAMAGE : %d", bullet_damage) ;
}

void print_plane ( short y , short x){
    move(y, x+3) ;
    printf("\e[0;32m\x1b[1m|V|") ;
    move(y + 1 , x +2) ;
    printf("|| ||") ;
    move(y + 2 , x +1) ;
    printf("/     \\") ;
    move(y + 3 , x) ;
    printf("|--| |--|") ;
    move(y+ 4 , x + 2);
    printf("/|||\\\x1b[0m")  ;
}
void clear_plane ( short y , short x){
    move(y, x+3) ;
    printf("    ") ;
    move(y + 1 , x +2) ;
    printf("     ") ;
    move(y + 2 , x +1) ;
    printf("        ") ;
    move(y + 3 , x) ;
    printf("         ") ;
    move(y+ 4 , x + 2);
    printf("     ")  ;
    
}


void print_mine( short y , short x){
    move( y , x) ;
    printf("\e[0;31m /\\") ;
    move( y+1, x) ;
    printf("(01)") ;
    move(y+2 , x) ;
    printf(" \\/\x1b[0m") ;
}
void clear_mine( short y , short x ){
    move( y-1 , x) ;
    printf("   ") ;
    move( y , x) ;
    printf("    ") ;
    move(  y+1 , x) ;
    printf("   ") ;

}

void print_bullet( short y , short x){
    move(y, x) ;
    printf("\x1b[31m\x1b[1m*\x1b[0m") ;
}
void clear_bullet ( short y , short x){
    move(y+1, x) ;
    printf("  ") ;
}

void print_bomber( short y , short x , short bomber_health) {
    move(y   ,x+11) ;
    printf("\x1b[1m,-.") ;
    move(y+1 ,x+1) ;
    printf("_,.      /  /") ;
    move(y+2 ,x) ;
    printf("; \\____,-==-._ ") ;
    move(y+3 ,x) ;
    printf("//_%.2d  `----' {+>",bomber_health) ;
    move(y+4 ,x) ;
    printf("`  `'--/  /-'`") ;
    move(y+5 ,x+6) ;
    printf("/  /") ;
    move(y+6 ,x+6) ;
    printf("`='\x1b[0m") ;
}
void clear_bomber( short y , short x){
    move(y ,x+10) ;
    printf("   ") ;
    move(y+1,x) ;
    printf("             ") ;
    move(y+2 ,x-1) ;
    printf("                ") ;
    move(y+3 ,x-1) ;
    printf("                 ") ;
    move(y+4 ,x-1) ;
    printf("              ") ;
    move(y+5 ,x+4) ;
    printf("     ") ;
    move(y+6 ,x+4) ;
    printf("    ") ;
}

void print_bomb ( short y , short x){
    move(y , x);
    printf("\e[0;1m\x1b[31m(-)");
    move(y +1 , x) ;
    printf("(-)");  
    move(y +2 , x) ;
    printf("(-)\x1b[0m"); 
}
void clear_bomb( short y , short x){
    move(y-1 , x);
    printf("    ");
    move( y,x) ;
    printf("    ");
    move( y+1,x) ;
    printf("    ");

}


void print_fighter( short y , short x , short fighter_health){
    move( y , x) ;
    printf("\x1b[1m\x1b[34m/ \\   / \\");
    move( y+1 , x) ;
    printf("\\  \\ /  / ");
    move( y+2 , x+1) ; 
    printf("\\| %.2d|/",fighter_health);
    move( y+3 , x+2) ;
    printf("\\\\V//");
    move( y+4 , x+3) ;
    printf("\\./ \x1b[0m");
}
void clear_fighter( short y , short x){
    move( y-1 , x) ;
    printf("           ");
    move( y , x) ;
    printf("            ");
    move( y+1 , x+1) ; 
    printf("        ");
    move( y+2 , x+2) ;
    printf("       ");
    move( y+3 , x+3) ;
    printf("     ");
}


void print_fighter_bullet( short y , short x){
    move(y, x) ;//  o
    printf("\x1b[31mo\x1b[0m") ;
}
void clear_fighter_bullet ( short y , short x){
    move(y-1, x) ;
    printf(" ") ;
}


void print_drone (short y , short x , short drone_health){
    move( y , x );
    printf("\e[4;35m\e[4;24m\x1b[1m /--\\") ;
    move( y+1 , x) ;          
    printf("/<><>\\") ;
    move ( y+2 , x) ;               
    printf("\\<%.2d>/",drone_health) ;
    move ( y+3 ,x+1) ;                    
    printf("\\--/\x1b[0m") ;
}
void clear_drone( short y , short x){
    move( y , x-1 );
    printf("      ") ;
    move(y+1 , x-1) ;
    printf("       ") ;
    move( y+2 , x) ;
    printf("       ");
    move(y+3 , x+1) ;
    printf("      ");
}

void print_barbar( short y , short x , short barbar_health){
    move(y ,x+4) ;
    printf("\e[4;35m\x1b[1m\e[4;24m________");
    move ( y+1 , x+1);
    printf("___\\ BACK /___");
    move ( y+2 , x);
    printf("|____\\ UP /____|");
    move ( y+3 , x+5);
    printf("( %.2d )",barbar_health);
    move ( y+4 , x+6);
    printf("\\__/\x1b[0m");  
}
void clear_barbar( short y , short x){
    move(y-1 ,x+4) ;
    printf("        ");
    move ( y , x+1);
    printf("               ");
    move ( y+1 , x);
    printf("                ");
    move ( y+2 , x+5);
    printf("      ");
    move ( y+3 , x+6);
    printf("     ");  
}

void print_bar ( short y , short x){
    move( y , x);
    printf("\x1b[1m\e[4;24m+------+") ;
    move (y+1 , x) ;
    printf("|  ??  |") ;
    move( y +2 , x);
    printf("|______|\x1b[0m"); 
}
void clear_bar ( short y , short x){
    move( y-1 , x);
    printf("        ") ;
    move (y , x) ;
    printf("        ") ;
    move( y+1 , x);
    printf("        "); 
}
// untill here



void save_name () {
    char name [21] ;
    move ( 18 , 65) ;
    printf (" pls enter your name to save your score  : ") ;
    scanf("%s" , name) ;
    time_t t = time(NULL) ;
    struct tm date = *localtime(&t);
    char buffer_date[30] ;
    sprintf( buffer_date , "%.2d-%.2d-%.2d-%.2d-%.2d-%.2d" , date.tm_year+1900 , date.tm_mon+1 , date.tm_mday , date.tm_hour , date.tm_min , date.tm_sec) ;
    FILE * fpin ;
    fpin = fopen ( "scores.txt" , "a") ;
    if ( fpin == NULL){
        printf(" cant open the file") ;
    }
    fprintf( fpin, "date : %s score : %-6d name : %-14s *\n" ,buffer_date , score , name) ;
    fclose(fpin) ;
}

void mini_menu ( int * choice ){
    short mini_cnt = 1000 ;
    char mini_key ;
    move ( 20 , 65) ;
    printf (" do you want to play again ") ;
    move (21 , 70) ;
    printf("        YES") ;
    move ( 22 ,70) ;
    printf("      MAIN MENU") ;
    while (1){
        mini_key = getch() ;
        if ( mini_key == 'w') {
            mini_cnt++ ;
        }
        else if (mini_key == 's') { mini_cnt-- ;}
        if ( mini_cnt%2 == 0){
                move( 20 , 65) ;
                printf (" do you want to play again ") ;
                move ( 21 , 70) ;
                printf("\e[0;31m\e[4;1m====>\e[4;0m   YES") ;
                move ( 22 , 70) ;
                printf("      MAIN MENU") ;
        }
        else { 
                move ( 20 , 65) ;
                printf (" do you want to play again ") ;
                move ( 21 , 70) ;
                printf("        YES") ;
                move ( 22 , 70) ;
                printf("\e[0;31m\e[4;1m====>\e[4;0m MAIN MENU") ;
        }
        if ( mini_key == ' '){
            if ( mini_cnt%2 == 0) {
                * choice = 1 ;
                break ;
            }
            else {
                // this should change -----
                * choice = 0 ;
                return ;
            }
        }

    }
}
// might delete this
int i = 0 ;
void add_explosion( short y , short x){
    boom.flag = 1 ;
    boom.y = y ;
    boom.x = x ;
}

void explosion(){

    if ( boom.flag == 1){
        i++ ;
        if ( i%10 == 1){ 
            move( boom.y , boom.x+3) ;
            printf("\e[0;31m##");
            move ( boom.y+1 , boom.x+3) ;
            printf("##\x1b[0m");
        }
        if ( i%10 == 4 ){
            move ( boom.y-1 , boom.x+2) ;
            printf("\e[0;31m #") ;
            move ( boom.y , boom.x+2) ;
            printf("###");
            move ( boom.y+1 , boom.x+2) ;
            printf("###");
            move ( boom.y+2 , boom.x+2) ;
            printf(" #\x1b[0m") ;
        }
        if ( i%10 == 6){
            move(boom.y-2 , boom.x) ;
            printf("\e[0;31m   #");
            move ( boom.y -1 , boom.x) ;
            printf(" ####");
            move( boom.y , boom.x) ;
            printf("##  ##");
            move ( boom.y+1 ,boom.x) ;
            printf(" ####");
            move(boom.y+2 , boom.x) ;
            printf("  #\x1b[0m");
        }
        if (i%10 == 9){
            move(boom.y-2 , boom.x) ;
            printf("    ");
            move ( boom.y -1 , boom.x) ;
            printf("     ");
            move( boom.y , boom.x) ;
            printf("      ");
            move ( boom.y+1 ,boom.x) ;
            printf("     ");
            move(boom.y+2 , boom.x) ;
            printf("    ");
            i = 0 ;
            boom.flag = 0 ;
        }
    }
}
void add_fire (){
    if ( fire_.flag == 0){
        fire_.flag = 1 ;
        fire_.x = plane.x+3 ;
        fire_.y = plane.y +5 ;
        fire_.damage = 0 ;
    }
}
void fire () {
    if (fire_.flag == 1){
        
        if ( fire_.damage == 0) {
            move(fire_.y , fire_.x) ;
            printf("\e[0;31m()()\x1b[0m") ;
        }
        if ( fire_.damage == 3){
            move( fire_.y , fire_.x) ;
            printf("     ") ;
            fire_.flag = 0 ;
            fire_.damage = 0 ;
        }
        fire_.damage++ ;
    }
}
void input (){
    if (kbhit()){
        
        char c = getch() ;
        if ( c == 'd' && plane.x+8 < frame_width-1){
            plane.x += 2 ;
            clear_plane( plane.y , plane.x-2) ;
            print_plane( plane.y , plane.x);
        }
        if ( c == 'a' && plane.x > 2){
            plane.x -= 2 ;
            clear_plane( plane.y , plane.x+2) ;
            print_plane( plane.y , plane.x);
            
        }
        if ( c == 'w' && plane.y > 2){
            plane.y -= 2 ;
            clear_plane( plane.y+2 , plane.x) ;
            print_plane( plane.y , plane.x);
            add_fire() ;
        }
        if ( c == 's' && plane.y+2 < frame_height-4){
            plane.y += 2 ;
            clear_plane( plane.y-2 , plane.x) ;
            print_plane( plane.y , plane.x);
        }
        if ( c == ' ' && plane.y > 3){
            add_bullet( plane.y , plane.x) ;
        }
        if ( c == 'p'){
            while(1) {
                c = getch() ;
                if ( c == 'p'){
                    break; 
                }
            }
        }
        if ( c == '='){
            exit(1) ;
        }
    }
}

void add_mine(){
    for ( int i = 0 ; i < mine_num ; i++){
        if ( arr_mines[i].flag == 0){
            arr_mines[i].flag = 1 ;
            arr_mines[i].y = 3 ;
            arr_mines[i].x = ((plane.x * score)%130) + 10 ;
            // رنذوم نیست اما این کارایی بیشتری داره :)
            // 120 =~ frame_width - 20 
            arr_mines[i].damage = 10*level ;
            break;
        }
    }

}

void mine_movment (){
    for ( int i = 0 ; i < mine_num ; i++){
        if ( arr_mines[i].flag == 1){
            clear_mine(arr_mines[i].y , arr_mines[i].x) ;
            print_mine(arr_mines[i].y , arr_mines[i].x) ;
            arr_mines[i].y++ ;
            // mine and plane
            if ((arr_mines[i].y+2 >= plane.y && arr_mines[i].y+2 <= plane.y+4)&&( arr_mines[i].x+2 >= plane.x && arr_mines[i].x+2 <= plane.x+8)){
                plane.health -= arr_mines[i].damage ;
                arr_mines[i].flag = 0 ;
                clear_mine( arr_mines[i].y , arr_mines[i].x) ;
                health_show(plane.health) ;
                score += 100 ;
                bullet_damage-- ;
            
            }
            // mine and drone
            if ((arr_mines[i].y+2 >= drone.y && arr_mines[i].y+2 <= drone.y+4)&&( arr_mines[i].x+2 >= drone.x && arr_mines[i].x+2 <= drone.x+8)){
                drone.health = 0 ;
                arr_mines[i].flag = 0 ;
                clear_drone( drone.y , drone.x) ;
                clear_mine( arr_mines[i].y , arr_mines[i].x) ;
            }
            //mine out of frame
            if ( arr_mines[i].y+2 > frame_height -2) {
                arr_mines[i].flag = 0 ;
                clear_mine(arr_mines[i].y , arr_mines[i].x) ;
            }
        }
    }
}

void add_bullet(){
    for ( int i = 0 ; i < bullet_num ; i++){
        if ( arr_bullets[i].flag == 0){
            arr_bullets[i].y = plane.y -2 ;
            arr_bullets[i].x = plane.x +4 ;
            arr_bullets[i].flag = 1 ;
            arr_bullets[i].damage = bullet_damage ;
            break;
        }
    }
}

void bullet_movment (){
    for ( int i = 0 ; i < bullet_num ; i++){
        if ( arr_bullets[i].flag == 1){
            clear_bullet(arr_bullets[i].y, arr_bullets[i].x) ;
            print_bullet(arr_bullets[i].y, arr_bullets[i].x) ;
            
            arr_bullets[i].y-- ;
            // bullet and bomber ;
            if ( arr_bullets[i].y == bomber.y+2 && (arr_bullets[i].x > bomber.x  && arr_bullets[i].x  < bomber.x+16)){
                arr_bullets[i].flag = 0 ;
                clear_bullet(arr_bullets[i].y, arr_bullets[i].x) ;
                bomber.health -= arr_bullets[i].damage ;
                if ( bomber.health <= 0 ){
                    clear_bomber(bomber.y , bomber.x) ;
                    add_explosion( arr_bullets[i].y , arr_bullets[i].x) ;
                    score += 300 ;
                }
            }
            // bullet and bomb
            if ( arr_bullets[i].y == bomb.y+2 && (arr_bullets[i].x >= bomb.x  && arr_bullets[i].x  <= bomb.x+2)){
                arr_bullets[i].flag = 0 ;
                clear_bullet(arr_bullets[i].y, arr_bullets[i].x) ;
                bomb.flag = 0 ;
                clear_bomb(bomb.y , bomb.x) ;
                score += 100 ;
            }
            // bullet and fighter
            if ( arr_bullets[i].y == fighter.y && (arr_bullets[i].x > fighter.x-1  && arr_bullets[i].x  < fighter.x+12)){
                arr_bullets[i].flag = 0 ;
                clear_bullet(arr_bullets[i].y, arr_bullets[i].x) ;
                fighter.health -= arr_bullets[i].damage ;
                if ( fighter.health <= 0 ){
                    add_explosion(fighter.y+1 , fighter.x) ;
                    clear_fighter(fighter.y , fighter.x) ;
                    score += 200 ;
                }
            }
            // bullet and drone 
            if ( arr_bullets[i].y == drone.y+3 && (arr_bullets[i].x > drone.x-1  && arr_bullets[i].x  < drone.x+6)){
                arr_bullets[i].flag = 0 ;
                clear_bullet(arr_bullets[i].y, arr_bullets[i].x) ;
                drone.health -= arr_bullets[i].damage ;
                if ( drone.health <= 0 ){
                    add_explosion(drone.y , drone.x) ;
                    clear_drone(drone.y , drone.x) ;
                    score += 200 ;
                }
            }
            // bullet and barbar 
            if ( arr_bullets[i].y == barbar.y +1 && (arr_bullets[i].x > barbar.x-1 && arr_bullets[i].x < barbar.x + 15)){
                arr_bullets[i].flag = 0 ;
                clear_bullet(arr_bullets[i].y , arr_bullets[i].x) ;
                barbar.health -= arr_bullets[i].damage ;
                if ( barbar.health <= 0){
                    clear_barbar(barbar.y , barbar.x) ;
                    add_explosion( barbar.y+1,barbar.x+3); 
                    add_bar() ;
                    score += 100 ;
                }
            }
            // bullet and mine
            for ( int j = 0 ; j < mine_num ; j++){
                if ( arr_bullets[i].y == arr_mines[j].y-1 && ( arr_bullets[i].x > arr_mines[j].x-1 && arr_bullets[i].x < arr_mines[j].x+4)){
                    arr_bullets[i].flag = 0 ;
                    arr_mines[j].flag = 0 ;
                    clear_bullet( arr_bullets[i].y , arr_bullets[i].x) ;
                    clear_mine ( arr_mines[j].y , arr_mines[j].x) ;
                    score += 50 ;
                }
            }
            // bullet out of frame
            if ( arr_bullets[i].y <= 1){
                clear_bullet(arr_bullets[i].y, arr_bullets[i].x) ;
                arr_bullets[i].flag = 0 ;
            }
        }
    }
}  

void add_bomber (){
    if ( bomber.health <= 0){
        srand(time(NULL)) ;
        bomber.x = 3 ;
        bomber.y = rand()%10+4 ;
        bomber.damage = 20*level ;
        bomber.health = 25*level ;
    }
}

void bomber_movment (){ 
    if ( bomber.health > 0 ){
        if ((bomber.x >= plane.x && bomber.x <= plane.x+8) && bomb.flag == 0 ){
            add_bomb() ;
        }
        clear_bomber(bomber.y , bomber.x) ;
        print_bomber(bomber.y , bomber.x , bomber.health) ;
        bomber.x++ ;
        if ( bomber.x%15 == 1){ 
            bomber.y++ ;
            clear_bomber(bomber.y-1, bomber.x) ;
            print_bomber(bomber.y , bomber.x , bomber.health) ;
        }
        // bomber and plane ;
        if ( (plane.y+1 >= bomber.y +1 && plane.y+1 < bomber.y+5) && ( plane.x+4 > bomber.x && plane.x+4 < bomber.x+16)){
            plane.health -= bomber.damage ;
            bomber.health = 0 ;
            clear_bomber(bomber.y , bomber.x) ;
            health_show(plane.health) ;
            
           bullet_damage-- ;
           damage_bullet_show(bullet_damage) ;
    
        }
        // bomber and drone 
        if ( (drone.y+2 > bomber.y+1 && drone.y+2 < bomber.y+5) && ( drone.x+2 > bomber.x && drone.x+2 < bomber.x+16)){
            bomber.health = 0 ;
            drone.health =  0 ;
            clear_drone(drone.y , drone.x) ; 
            clear_bomber(bomber.y , bomber.x) ;
            
        }
        // bomber and barbar 
        if ( ( barbar.y+3 > bomber.y+1 && barbar.y+3 < bomber.y+5) && (  barbar.x+5 > bomber.x  &&  barbar.x+5 < bomber.x+16)){
            bomber.health -= barbar.damage ;
            barbar.health =  0 ;
            clear_barbar(drone.y , drone.x) ;
            if ( bomber.health <= 0){
                clear_bomber(bomber.y , bomber.x) ;
            }
        }
        // bomber and fighter 
        if ((fighter.y+2 > bomber.y+1 && fighter.y+2 < bomber.y+5) &&( fighter.x+2 > bomber.x && fighter.x+2 < bomber.x+16)){
            bomber.health -= fighter.damage ;
            fighter.health = 0 ;
            clear_fighter(fighter.y,fighter.x) ;
            if (bomber.health <= 0){
                clear_bomber(bomber.y , bomber.x); 
            }

        }
        // bomber out of frame
        if ( bomber.x+10 > frame_width-10){
            bomber.health = 0 ;
            clear_bomber(bomber.y , bomber.x) ;
        }
    }
}
void add_bomb(){
    bomb.x = bomber.x + 4;
    bomb.y = bomber.y +5 ;
    bomb.damage = 10*level ;
    bomb.flag = 1 ;
}

void bomb_momvent(){
    if ( bomb.flag == 1){
        clear_bomb(bomb.y, bomb.x) ;
        print_bomb(bomb.y, bomb.x) ;
        bomb.y++ ;
        // bomb and plane
        if ((bomb.y+1 <= plane.y+6  && bomb.y+1 >= plane.y)&&(bomb.x+1 <= plane.x + 8 && bomb.x+1 >= plane.x )){
            bomb.flag = 0 ;
            plane.health -= bomb.damage ;
            clear_bomb(bomb.y, bomb.x) ;
            health_show(plane.health) ;
            bullet_damage-- ;
            damage_bullet_show(bullet_damage) ;
     
            
        }
        //  bomb and drone
        if ((bomb.y+1 <= drone.y+4 && bomb.y+1 >= drone.y) &&(bomb.x+1 <= drone.x +8 && bomb.x+1 >= drone.x )){
            bomb.flag = 0 ;
            drone.health  = 0 ;
            clear_bomb(bomb.y , bomb.x) ;
            clear_drone(drone.y , drone.x) ;
        }
        // bomb out of frame
        if ( bomb.y+3 > frame_height-3){
            clear_bomb(bomb.y , bomb.x) ;
            bomb.flag = 0 ;
        }
    }
}

void add_fighter (){
    if ( fighter.health <= 0){
    fighter.x  = score%(frame_width-20)+10;
    fighter.y  = 3 ;
    fighter.health = 15*level ;
    fighter.damage = 15*level ;
    }

}

void fighter_movment(long long i){
    if ( fighter.health > 0 ){
        if ( i%50 == 1){
            add_fighter_bullet() ;
        }
        clear_fighter(fighter.y , fighter.x) ;
        print_fighter(fighter.y , fighter.x , fighter.health) ;
        fighter.y++ ;
        // fighter and plane
        if ((fighter.y+3 >= plane.y-1 && fighter.y+3 <= plane.y+4 )&&(fighter.x+4 >= plane.x && fighter.x+4 <= plane.x+8)){
            plane.health -= fighter.damage ;
            fighter.health = 0 ;
            clear_fighter( fighter.y , fighter.x) ;
            health_show(plane.health) ;
            bullet_damage-- ;
            damage_bullet_show(bullet_damage) ;
            
        }
        // fighter and drone 
        if ((fighter.y+3 >= drone.y && fighter.y+3 <= drone.y+4 )&&(fighter.x+4 >= drone.x && fighter.x+4 <= drone.x+8)){
            drone.health = 0 ;
            fighter.health = 0 ;
            clear_fighter( fighter.y , fighter.x) ;
            clear_drone(drone.y , drone.x) ;
        }
        // fighter out of frame 
        if ( fighter.y+4 > frame_height-2){
            clear_fighter( fighter.y , fighter.x) ;
            fighter.health = 0 ;
        }

    }

}
void add_fighter_bullet (){
    for ( int i = 0 ; i < fighter_bullet_num ;i++){
        if (arr_fighter_bullet[i].flag == 0){
            arr_fighter_bullet[i].x = fighter.x + 4 ;
            arr_fighter_bullet[i].y = fighter.y + 5 ;
            arr_fighter_bullet[i].damage = 5 * level ;
            arr_fighter_bullet[i].flag = 1 ;
            break;
            // این بریک باعث میشود تیر ها پیوسته پرتاب شوند
        }
    }
}
void fighter_bullet_movment(){
    for ( int i = 0 ; i < fighter_bullet_num ; i++){
        if ( arr_fighter_bullet[i].flag == 1){
            clear_fighter_bullet (arr_fighter_bullet[i].y , arr_fighter_bullet[i].x) ;
            print_fighter_bullet (arr_fighter_bullet[i].y , arr_fighter_bullet[i].x) ;
            arr_fighter_bullet[i].y++ ;
            // fighter bullet and plane 
            if ( (arr_fighter_bullet[i].y >= plane.y-1 && arr_fighter_bullet[i].y <= plane.y+4) && (arr_fighter_bullet[i].x >= plane.x && arr_fighter_bullet[i].x <= plane.x+8)){
                plane.health -= arr_fighter_bullet[i].damage ;
                arr_fighter_bullet[i].flag = 0 ;
                clear_fighter_bullet(arr_fighter_bullet[i].y , arr_fighter_bullet[i].x) ;
                health_show(plane.health) ;
                bullet_damage-- ;
                damage_bullet_show(bullet_damage) ;

            }
            // fighter bullet and drone 
            if ( (arr_fighter_bullet[i].y <= drone.y-1 && arr_fighter_bullet[i].y >= drone.y+4) && (arr_fighter_bullet[i].x >= drone.x && arr_fighter_bullet[i].x <= drone.x+8)){
                drone.health -= arr_fighter_bullet[i].damage ;
                arr_fighter_bullet[i].flag = 0 ;
                clear_fighter_bullet(arr_fighter_bullet[i].y , arr_fighter_bullet[i].x) ;
                if ( drone.health <= 0){
                    clear_drone( drone.y , drone.x) ;
                }

            }
            // fighter bullet out of frame 
            if ( arr_fighter_bullet[i].y > frame_height-2){
                arr_fighter_bullet[i].flag = 0 ;
                clear_fighter_bullet (arr_fighter_bullet[i].y , arr_fighter_bullet[i].x) ;
            }
        }
    }
}

void add_drone(){
    if ( drone.health <= 0){
        srand(time(0)) ;
        drone.x = rand()%(frame_width-20)+10 ;
        drone.y = 3 ;
        drone.health = 15*level ;
        drone.damage = 20*level ;
    }
}

void drone_movement(){
    if ( drone.health > 0){
        clear_drone(drone.y , drone.x) ;
        print_drone(drone.y , drone.x , drone.health) ;
        if ( drone.x > plane.x){
            drone.x -- ;
            clear_drone(drone.y , drone.x+1) ;
            print_drone(drone.y , drone.x , drone.health) ;
        }
        if ( drone.x < plane.x){
            drone.x ++ ;
            clear_drone(drone.y , drone.x-1) ;
            print_drone(drone.y , drone.x , drone.health) ;
        }
        if ( drone.y < plane.y){
            drone.y ++ ;
            clear_drone(drone.y-1 , drone.x) ;
            print_drone(drone.y , drone.x , drone.health) ;
        }
        if ( drone.y > plane.y){
            drone.y -- ;
            clear_drone(drone.y+1 , drone.x) ;
            print_drone(drone.y , drone.x , drone.health) ;
        }
        // drone and plane 
        if ( (drone.y+2 >= plane.y && drone.y+2 <= plane.y+4)&&(drone.x+4 >= plane.x && drone.x+4 <= plane.x+8)){
            drone.health = 0 ;
            plane.health -= drone.damage ;
            clear_drone(drone.y , drone.x) ;
            health_show(plane.health) ;
            bullet_damage-- ;
            damage_bullet_show(bullet_damage) ;
        }
    }
}
void add_barbar(){
    if ( barbar.health <= 0){
        srand(time(NULL)) ;
        barbar.y = 3 ;
        barbar.x = rand()%(frame_width-30)+10 ;
        barbar.health = 20*level ;
        barbar.damage = 10*level ;
    }
}
void barbar_movment(){
    if ( barbar.health > 0){
        clear_barbar(barbar.y , barbar.x) ;
        print_barbar(barbar.y , barbar.x , barbar.health) ;
        barbar.y++ ;
        // barbar and plane 
        if ( (barbar.y+3 >= plane.y && barbar.y+3 <= plane.y+4)&& barbar.x+8 >= plane.x-4 && barbar.x+8 <= plane.x+12 ){
            barbar.health = 0 ;
            plane.health -= barbar.damage ;
            clear_barbar(barbar.y , barbar.x) ;
            health_show(plane.health) ;
            bullet_damage -- ;
            damage_bullet_show(bullet_damage) ;
    
        }
        // barbar and drone 
        if ( (barbar.y+3 >= drone.y && barbar.y+3 <= drone.y+4)&& barbar.x+8 >= drone.x && barbar.x+8 <= drone.x+8 ){
            barbar.health = 0 ;
            drone.health = 0 ;
            clear_drone(drone.y , drone.x) ;
            clear_barbar(barbar.y , barbar.x) ;
        }
        
        // barbar out of frame
        if ( barbar.y+3 > frame_height-2){
            clear_barbar(barbar.y , barbar.x) ;
            barbar.health = 0 ;
        }
    }
}
void add_bar (){
    for (int i = 0 ; i < bar_num ; i++){
        if (arr_bar[i].flag == 0 ){
            arr_bar[i].x = barbar.x ;
            arr_bar[i].y = barbar.y + 2 ;
            arr_bar[i].damage = 0 ;
            arr_bar[i].flag = 1   ;
            break;
        }  
    }
}
void bar_movment (){
    for ( int i = 0 ; i < bar_num ; i++){
        if ( arr_bar[i].flag == 1){
            clear_bar(arr_bar[i].y , arr_bar[i].x) ;
            print_bar(arr_bar[i].y , arr_bar[i].x) ;
            arr_bar[i].y++ ;
            // bar and plane 
            if ( (arr_bar[i].y+1 >= plane.y && arr_bar[i].y+1 <= plane.y+6)&& (arr_bar[i].x+4 >= plane.x && arr_bar[i].x+4 <= plane.x+8)){
                arr_bar[i].flag = 0 ;
                clear_bar(arr_bar[i].y , arr_bar[i].x) ;
                if ( score%2 == 1){
                    plane.health += 2;
                    health_show(plane.health) ;
                }
                else {
                    bullet_damage ++ ;
                    damage_bullet_show(bullet_damage) ;
                }

            }
            // bar out of frame
            if ( arr_bar[i].y+2 > frame_height-2){
                arr_bar[i].flag = 0 ;
                clear_bar(arr_bar[i].y , arr_bar[i].x) ;
            }
        }
    }
} 
void difficultly (){
    if ( level == 1){
        plane.health = 100 ;
        bullet_damage = 15 ;
        speed = 6 ;
        chance = 90 ;
    }
    if ( level == 2 ){
        plane.health = 80 ;
        bullet_damage = 10 ;
        speed = 3 ;
        chance = 6 ;
    }
    if ( level == 3){
        plane.health = 60 ;
        bullet_damage = 6 ;
        speed = 2 ;
        chance = 6 ;
    }
}
void initialize () {
    plane.x = 75 ;
    plane.y = 30 ;
    for ( int i = 0 ; i < bullet_num ; i++){
        arr_bullets[i].flag = 0 ;
    }
    for ( int i = 0 ; i < mine_num ; i++){
        arr_mines[i].flag = 0 ;
    }
    for ( int i = 0 ; i < bar_num ; i++){
        arr_bar[i].flag = 0 ;
    }
    bomber.health = 0 ;
    fighter.health = 0 ;
    drone.health = 0 ;
    barbar.health = 0 ;
    score = 0 ;
}
void spawn  (long long i){
    if ( i%(10 * chance) == 1){
        add_mine() ;
    }
    if ( i% (15 * chance) == 1){
        add_barbar() ;
        add_fighter() ;
    }
    if (i% (15 * chance) == 1){
        add_drone() ;
    }
    if ( i%(20 * chance ) == 1 ){
        add_bomber() ;
    }
}
void update (long long i){ 
    if ( i%10 == 1){
        score_show(score) ;
    }
    if ( i%(1*speed) == 1){
        bullet_movment() ;
        fighter_bullet_movment() ;
        explosion() ;
        fire() ;
    }
    if ( i%(5*speed) == 1){
        mine_movment() ;
        bomb_momvent() ;
        bar_movment() ;
    }
    if ( i%(1*speed) == 1){
        bomber_movment() ;   
    }
    if ( i%(3*speed) == 1){
        fighter_movment(i) ;
        barbar_movment() ;
        drone_movement() ; 
    }
}