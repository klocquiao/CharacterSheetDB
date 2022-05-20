#ifndef DELETEMENU_H
#define DELETEMENU_H

#include "menu.h"
#include "database.h"
#include <ncurses.h>
#include <iostream>
#include <vector>

using namespace std;


class Deletemenu : public Menu{
    private:
        WINDOW * win;
        WINDOW * inputWin;

    public:
        Deletemenu();
    
        void getMenu(Database &db);
        void deleteRecords(vector<int> posVec, Database &db);
        void scrollData(vector<int> posVec, Database &db, int y);

        ~Deletemenu();
};

#endif