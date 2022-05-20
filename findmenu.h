#ifndef FINDMENU_H
#define FINDMENU_H

#include "menu.h"
#include "database.h"
#include <ncurses.h>
#include <iostream>

using namespace std;


class Findmenu : public Menu{
    private:
        WINDOW * win;
        WINDOW * inputWin;

    public:
        Findmenu();
    
        void getMenu(Database &db);
        void scrollData(vector<int> posVec, Database &db, int y);

        ~Findmenu();
};

#endif