#ifndef ADDMENU_H
#define ADDMENU_H

#include "menu.h"
#include "model/character.h"
#include "model/database.h"
#include <ncurses.h>
#include <iostream>

using namespace std;


class Addmenu : public Menu {
    private:
        Character character;
        WINDOW * win;
        WINDOW * inputWin;

    public:
        Addmenu();
    
        void getMenu(Database &db);
        void getField();

        ~Addmenu();
};

#endif