#ifndef LISTMENU_H
#define LISTMENU_H

#include "menu.h"
#include "database.h"
#include <ncurses.h>
#include <iostream>

using namespace std;


class Listmenu : public Menu{
    private:
        WINDOW * win;
        WINDOW * inputWin;

    public:
        Listmenu();
    
        void getMenu(Database &db);
        void scrollData(Database &db, int y);

        ~Listmenu();
};
#endif
