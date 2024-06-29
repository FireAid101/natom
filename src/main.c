#include <application.h>
#include <string.h>

#define ctrl(x) ((x) & 0x1f)

int main(int argc, char **argv) {
	init_program();

	bool should_close = false;
	bool show_title = true;

	int menu_selection = 0;

	init_pair(1, COLOR_BLACK, COLOR_WHITE);

	while (!should_close) {
		if (show_title) {
			curs_set(0);
			// Draw main menu
			const char *menu[] = {"Natom", "By Aiden Koorsen", "Version -- 0.0.1a -- 2024"};

			const char *buttons[] = {"New file - Ctrl + N", "Open file - Ctrl + O"};

			// Get the screen size
			int rows, columns;
			getmaxyx(stdscr, rows, columns);

			attron(A_BOLD);
			for (int i = 0; i < 3; i++)
				mvprintw((rows / 2) + i, (columns - strlen(menu[i])) / 2, "%s", menu[i]);				
			attroff(A_BOLD);

			for (int i = 0; i < 2; i++) {
				if (i == menu_selection) {
					attron(COLOR_PAIR(1));
				}

				mvprintw((rows / 2) + 5 + i, (columns - strlen(buttons[i])) / 2, "%s", buttons[i]);					

				if (i == menu_selection) {
					attroff(COLOR_PAIR(1));
				}
			}
			
		}
		else 
			curs_set(1);

		refresh();

		int c = getch();

		switch (c)
		{
		case ctrl('q'): // Quit
				should_close = true;
			break;

		case KEY_UP:
		case KEY_DOWN:
			if (show_title == true) {
				if (menu_selection == 0)
					menu_selection = 1;
				else 
					menu_selection = 0;
			}
			break;
		}
	}

	deinit_program();
	return 0;
}