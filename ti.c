// STANDARD LIBRARY
#include <stdio.h>
#include <string.h>

// PROJECT
#include "mode.h"

// NCURSES
#include <ncurses.h>

// global defaults
#define DEFAULT_BUFFER_NAME "unnamed"
#define DEFAULT_MODE NORMAL
#define DEFAULT_STATE NONE

// global definitions.
char *buffer_name;
MODE current_mode;
STATE current_state;

int main(int argc, char **argv) {
    buffer_name = DEFAULT_BUFFER_NAME;
    current_mode = DEFAULT_MODE;
    current_state = DEFAULT_STATE;

    FILE *fp;
    
    if(argc > 1) {
        for (int i = 0; i < argc; i++)
        {
            //printf("%s ", argv[i]);
            if(argv[i][0] == '-') {
                //printf("FLAG ");
            } else {
                buffer_name = argv[i];
            }
        }
    }

    fp = fopen(buffer_name, "rw");

    printf("%s\n", buffer_name);

    initscr();			/* Start curses mode 		  */
	printw(buffer_name);	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */

    int ch;

    int row,col;
    int y,x;

    while(1) {
        getmaxyx(stdscr,row,col);
        getsyx(y,x);

        ch = getch();
	    if(ch == KEY_ENTER && current_state != NONE) {
            current_state = NONE;
        }
        if(current_state == NONE) {
            if(ch == ':') {
                current_state = COMMAND;
                
                move(row - 1, 0);
                printw(":");
            }
        }
        if(current_state == COMMAND) {
            if(ch == 'q') {
                break;
            }
        }
        refresh();
    }

    endwin();			/* End curses mode		  */

}