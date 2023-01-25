#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

#include "global.h"
#include "utils.h"
#include "typewriter.h"

void title()
{
    animated_printf("WELCOME TO...\n");
    
    print("\n%s\n\n%s\n\n", TITLE_INTERN, TITLE_ADVENTURES);
    wait_ms(1000);

    animated_printf("Press any key to continue...\n");
    getch();

    timed_ms_animated_printf(10, 500, "\n\n=============================================================================================\n\n");
    
    refresh();
}

void intro()
{
    animated_printf("Hello, bold adventurer. I see you've discovered me. I'm mowerdev1. What's your name, bold adventurer?\n");

    char buf[256];
    getstr(buf);

    global.player_name = buf;
    animated_printf("Nice to meet you, %s. I guess I can stop calling you \"bold aventurer\" now, bold adventurer... Allow me to tell you a story, bold adventurer.", global.player_name);

    animated_printf("\n\nThe year is 2023... A humble intern from the Massachusetts Institute of Technology waits patiently at his desk for a new task... But no task comes... Soon, the intern gets restless. He can not wait any longer. After all, this was no ordinary intern...\n\n");
    timed_ms_animated_printf(STD_CHAR_PAUSE_MS, STD_SENTENCE_PAUSE_MS * 2, "For this was the intern, Michael Lu... Now what made this Michael guy so special? Well, you see %s, Michael was exceptionally...", global.player_name);
    timed_ms_animated_printf(STD_CHAR_PAUSE_MS, STD_SENTENCE_PAUSE_MS * 2, "\n\nstupid.\n\n");

    animated_printf("Well, I guess that's why he created this... and also created me... I will say %s, you're in for quite the adventure!\n\n", global.player_name);  

    animated_printf("Are you ready? Press any key to continue!\n");
    getch();  
}

int main(int argc, int** argv)
{
    initscr();

    title();
    intro();

    endwin();

    return 0;
}