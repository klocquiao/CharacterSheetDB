#include "menudisplays.h"

void Menudisplays :: mainMenuDisplay(WINDOW * win, double menuYMax, double menuXMax) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 0, 1, "RPG Character Database");
    mvwprintw(win, menuYMax / 5, 2, "1. Add a character...");
    mvwprintw(win, (2*menuYMax) / 5 , 2, "2. Find a character...");
    mvwprintw(win, (3*menuYMax) / 5, 2, "3. Delete a character...");
    mvwprintw(win, (4*menuYMax) / 5, 2, "4. List all characters...");
    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");

    wrefresh(win);
}


void Menudisplays :: recordDisplay(WINDOW * win, double menuYMax) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 0, 1, "RPG Character Database");
    mvwprintw(win, menuYMax / 8, 2, "First name:");
    mvwprintw(win, (2*menuYMax) / 8 , 2, "Last name:");
    mvwprintw(win, (3*menuYMax) / 8 , 2, "Gender:");
    mvwprintw(win, (4*menuYMax) / 8, 2, "Race:");
    mvwprintw(win, (5*menuYMax) / 8, 2, "Job:");
    mvwprintw(win, (6*menuYMax) / 8, 2, "Age:");
    mvwprintw(win, (7*menuYMax) / 8, 2, "Level:");


    wrefresh(win);
 }


void Menudisplays :: searchTypeStringDisplay(WINDOW * win, double menuYMax, double menuXMax) {
    wclear(win);
    box(win, 0 , 0);

    mvwprintw(win, 0, 1, "RPG Character Database");
    mvwprintw(win, menuYMax / 4, 2, "Search by...");
    mvwprintw(win, (2*menuYMax) / 4, 2, "1. Exact string");
    mvwprintw(win, (3*menuYMax) / 4 , 2, "2. Substring");
    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");

    wrefresh(win);
}


void Menudisplays :: searchTypeIntDisplay(WINDOW * win, double menuYMax, double menuXMax) {
    wclear(win);
    box(win, 0 , 0);

    mvwprintw(win, 0, 1, "RPG Character Database");
    mvwprintw(win, menuYMax / 4, 2, "Search by...");
    mvwprintw(win, (2*menuYMax) / 4, 2, "1. Exact number");
    mvwprintw(win, (3*menuYMax) / 4 , 2, "2. Range ");
    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");

    wrefresh(win);
}

    
void Menudisplays :: fieldTypeDisplay(WINDOW * win, double menuYMax, double menuXMax) {
    wclear(win);
    box(win, 0 , 0);

    mvwprintw(win, 0, 1, "RPG Character Database");
    mvwprintw(win, menuYMax / 4, 2, "Search by...");
    mvwprintw(win, (2*menuYMax) / 4, 2, "1. First name");
    mvwprintw(win, (3*menuYMax) / 4 , 2, "2. Last name");
    mvwprintw(win, menuYMax / 6, menuXMax / 2, "3. Gender");
    mvwprintw(win, (2*menuYMax) / 6, menuXMax / 2, "4. Race");
    mvwprintw(win, (3*menuYMax) / 6, menuXMax / 2, "5. Job");
    mvwprintw(win, (4*menuYMax) / 6, menuXMax / 2, "6. Age");
    mvwprintw(win, (5*menuYMax) / 6, menuXMax / 2, "7. Level");
    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");

    wrefresh(win);
    }


void Menudisplays :: currentRecordDisplay(WINDOW * win, double menuYMax, Character currentCharacter) {
    mvwprintw(win, (menuYMax) / 8, 14, currentCharacter.getFirstName().c_str());
    mvwprintw(win, (2*menuYMax) / 8, 14, currentCharacter.getLastName().c_str());
    mvwprintw(win, (3*menuYMax) / 8, 14, currentCharacter.getGender().c_str());
    mvwprintw(win, (4*menuYMax) / 8, 14, currentCharacter.getRace().c_str());
    mvwprintw(win, (5*menuYMax) / 8, 14, currentCharacter.getJob().c_str());
    mvwprintw(win, (6*menuYMax) / 8, 14, to_string(currentCharacter.getAge()).c_str());
    mvwprintw(win, (7*menuYMax) / 8, 14, to_string(currentCharacter.getLevel()).c_str());

    wrefresh(win);
}


void Menudisplays :: sortTypeStringDisplay(WINDOW * win, double menuYMax, double menuXMax) {
    wclear(win);
    box(win, 0 , 0);

    mvwprintw(win, 0, 1, "RPG Character Database");
    mvwprintw(win, menuYMax / 4, 2, "Sort by...");
    mvwprintw(win, (2*menuYMax) / 4, 2, "1. Alphabetical Order");
    mvwprintw(win, (3*menuYMax) / 4 , 2, "2. Reverse Alphabetical Order");
    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");

    wrefresh(win);
}


void Menudisplays :: sortTypeIntDisplay(WINDOW * win, double menuYMax, double menuXMax) {
    wclear(win);
    box(win, 0 , 0);

    mvwprintw(win, 0, 1, "RPG Character Database");
    mvwprintw(win, menuYMax / 4, 2, "Search by...");
    mvwprintw(win, (2*menuYMax) / 4, 2, "1. Ascending Order");
    mvwprintw(win, (3*menuYMax) / 4 , 2, "2. Descending Order");
    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");

    wrefresh(win);
}


void Menudisplays :: errorDisplayLimit(WINDOW * win) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, 1, "ERROR! Max size reached!");

    wrefresh(win);
}


void Menudisplays :: errorDisplayInvalidInput(WINDOW * win) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, 1, "ERROR! Invalid input entered!");
    
    wrefresh(win);
}

void Menudisplays :: errorDisplayIntEntered(WINDOW * win) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, 1, "ERROR! Numbers used for word!");

    wrefresh(win);
}

void Menudisplays :: errorDisplayCharEntered(WINDOW * win) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, 1, "ERROR! Letters/punctuation used for number!");

    wrefresh(win);
}


void Menudisplays :: errorDisplayEmpty(WINDOW * win) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, 1, "ERROR! Input can't be empty");

    wrefresh(win);
}


void Menudisplays :: refreshInput(WINDOW * win, string input) {
    wclear(win);
    box(win, 0, 0);

    mvwprintw(win, 1, 1, input.c_str());

    wrefresh(win); 
}


void Menudisplays :: refreshWindow(WINDOW * win) {
    wclear(win);
    box(win, 0, 0);

    wrefresh(win); 
}