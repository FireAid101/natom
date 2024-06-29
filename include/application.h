#ifndef APPLICATION_H
#define APPLICATION_H

#include <ncurses/ncurses.h>

typedef struct {

} application_config;

static void init_program() {
	initscr();
    start_color();
	raw();
	keypad(stdscr, TRUE);
	noecho();
}

static void deinit_program() {
	endwin();
}

#endif