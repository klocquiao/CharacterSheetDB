#ifndef MAINMENU_H
#define MAINMENU_H

#include "menu.h"
#include <ncurses.h>
#include <iostream>

using namespace std;


class Mainmenu : public Menu {
    private:
        char choice;
        WINDOW * win;
        WINDOW * inputWin;

    public:
        Mainmenu();

        void getMenu();
        char getChoice() const;
        
        ~Mainmenu();
};

#endif
