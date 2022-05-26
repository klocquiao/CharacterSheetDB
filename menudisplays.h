#ifndef MENUDISPLAYS_H
#define MENUDISPLAYS_H

#include "model/character.h"
#include <ncurses.h>
#include <string>

using namespace std;


struct Menudisplays {
    void recordDisplay(WINDOW * win, double menuYMax);
    void currentRecordDisplay(WINDOW * win, double menuYMax, Character currentCharacter);
    void mainMenuDisplay(WINDOW * win, double menuYMax, double menuXMax);
    void fieldTypeDisplay(WINDOW * win, double menuYMax, double menuXMax);
    void searchTypeStringDisplay(WINDOW * win, double menuYMax, double menuXMax);
    void searchTypeIntDisplay(WINDOW * win, double menuYMax, double menuXMax);
    void sortTypeStringDisplay(WINDOW * win, double menuYMax, double menuXMax);
    void sortTypeIntDisplay(WINDOW * win, double menuYMax, double menuXMax);
    void errorDisplayLimit(WINDOW * win);
    void errorDisplayInvalidInput(WINDOW * win);
    void errorDisplayEmpty(WINDOW * win);
    void errorDisplayIntEntered(WINDOW * win);
    void errorDisplayCharEntered(WINDOW * win);
    void refreshInput(WINDOW * win, string input);
    void refreshWindow(WINDOW * win);
    
};

#endif