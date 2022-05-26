#include "addmenu.h"

Addmenu :: Addmenu() {
    getmaxyx(stdscr, yMax, xMax);
    win = newwin(yMax / 1.5, xMax / 1.5, yMax / 6, xMax / 6);
    getmaxyx(win, menuYMax, menuXMax);
    inputWin = newwin(3, xMax / 1.5, (yMax / 1.5) + (yMax / 6) , xMax / 6);
}


void Addmenu :: getMenu(Database& db) {
    displays.recordDisplay(win, menuYMax);

    getField();

    wclear(inputWin);
    box(inputWin, 0, 0);

    if (db.findMatchingRecord(character)) {
        mvwprintw(inputWin, 1, 1, "Record already exists! Press anything to continue...");
        wrefresh(inputWin);

    }
    else {
        mvwprintw(inputWin, 1, 1, "Record added! Press anything to continue...");
        wrefresh(inputWin);
        db.addCharacter(character);
        character.write();
    }

    getch();

    endwin();
}


void Addmenu :: getField() {
    box(inputWin, 0, 0);
    mvwprintw(inputWin, 1, 1, "Enter data...");
    wrefresh(inputWin);

    string field;
    for (int i = 1; i <= 7; i++) {
        if (i >= 6) {
            field = inputWindow(inputWin, true);
        }
        else {
            field = inputWindow(inputWin, false);
            field[0] = toupper(field[0]);
            for (int i = 1; i < field.size(); i++) {
                field[i] = tolower(field[i]);
            }
        }

        mvwprintw(win, (i*menuYMax) / 8, 14, field.c_str());
        wclear(inputWin);
        box(inputWin, 0, 0);
        mvwprintw(inputWin, 1, 1, "Enter data...");
        wrefresh(win);

        switch(i) {
            case 1: character.setFirstName(field); break;
            case 2: character.setLastName(field); break;
            case 3: character.setGender(field); break;
            case 4: character.setRace(field); break;
            case 5: character.setJob(field); break;
            case 6: character.setAge(stoi(field)); break;
            case 7: character.setLevel(stoi(field)); break;

        }
    }

    wclear(inputWin);
    mvwprintw(inputWin, 1, 1, "Record added! Press anything to continue...");
    box(inputWin, 0, 0);
    wrefresh(inputWin);
}

Addmenu :: ~Addmenu() {
    cout << "Addmenu destructor called" << "\n";
}

