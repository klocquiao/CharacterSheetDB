#include "mainmenu.h"


Mainmenu::Mainmenu() {
    initscr();
    curs_set(0);
    noecho();
    getmaxyx(stdscr, yMax, xMax);
    win = newwin(yMax / 1.5, xMax / 1.5, yMax / 6, xMax / 6);
    getmaxyx(win, menuYMax, menuXMax);
    inputWin = newwin(3, xMax / 1.5, (yMax / 1.5) + (yMax / 6) , xMax / 6);
    getMenu();

}

void Mainmenu::getMenu() {
    displays.mainMenuDisplay(win, menuYMax, menuXMax);

    choice = inputWindow(inputWin, 4);
    
    displays.refreshWindow(win);
    displays.refreshWindow(win);
    endwin();
}

char Mainmenu :: getChoice() const {
    return choice;
}

Mainmenu :: ~Mainmenu() {
    cout << "Mainmenu destructor called" << "\n";
}


