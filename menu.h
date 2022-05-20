#ifndef MENU_H
#define MENU_H

#include "menudisplays.h"
#include "database.h"
#include <ncurses.h>
#include <vector>

using namespace std;

class Menu {
    public:
        Menudisplays displays;
        double yMax, xMax;
        double menuYMax, menuXMax;
        
        const char END = 'e';

        virtual string inputWindow(WINDOW * inputWin, bool isInt);
        virtual char inputWindow(WINDOW * inputWin, int numOfOptions);
        virtual void setIndexVec(vector<int> &vec, Database &db, char fieldType, char stringType, 
            string begin, string end, string search);
        virtual void inputWindowRanges(WINDOW * win, WINDOW * inputWin, string& begin, string& end);
        virtual bool isValidInput(char toAppend, char recentAppend, bool isInt);

        virtual ~Menu() {}
};

#endif