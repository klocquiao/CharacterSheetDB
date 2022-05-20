#include "listmenu.h"

using namespace std;

Listmenu :: Listmenu() {
    getmaxyx(stdscr, yMax, xMax);
    win = newwin(yMax / 1.5, xMax / 1.5, yMax / 6, xMax / 6);
    getmaxyx(win, menuYMax, menuXMax);
    inputWin = newwin(3, xMax / 1.5, (yMax / 1.5) + (yMax / 6) , xMax / 6);
}


void Listmenu :: getMenu(Database& db) {

    displays.fieldTypeDisplay(win, menuYMax, menuXMax);

    //Choose field option
    char fieldType = inputWindow(inputWin, 7);
;
    if (fieldType == END) {
        endwin();
        return;
    }
    //Note: field options above 6 are integers
    else if (fieldType < '6') displays.sortTypeStringDisplay(win, menuYMax, menuXMax);
    else displays.sortTypeIntDisplay(win, menuYMax, menuXMax);

    //Choose field option
    char searchType = inputWindow(inputWin, 2);
    if (searchType == END) {
        endwin();
    }

    displays.refreshWindow(win);

    //Sort db vector
    switch(searchType) {
        case '1': db.ascendingSort(fieldType); break;
        case '2': db.descendingSort(fieldType); break;
    }

    if (db.getBank().size() > 0) {
        scrollData(db, menuYMax);
    }
    else {
        mvwprintw(win, menuYMax / 2, 2, "Database is empty! Press anything to continue...");
        wrefresh(win);
        getch();
    }

    displays.refreshWindow(win);
    displays.refreshWindow(win);
    endwin();
}


void Listmenu :: scrollData(Database &db, int y) {
    int i = 0;
    int searchSize = db.getBank().size();
    WINDOW * inputWin = newwin(3, xMax / 1.5, (yMax / 1.5) + (yMax /6) , xMax / 6);
    box(inputWin, 0, 0);
    mvwprintw(inputWin, 1, 1, "Use 'W'/'S' to navigate");
    wrefresh(inputWin);

    displays.recordDisplay(win, y);

    //Get all fields from current record
    string currentFirstName = db.getCharacterAtIndex(i).getFirstName();
    string currentLastName = db.getCharacterAtIndex(i).getLastName();
    string currentGender = db.getCharacterAtIndex(i).getGender();
    string currentRace = db.getCharacterAtIndex(i).getRace();
    string currentJob = db.getCharacterAtIndex(i).getJob();
    string currentAge = to_string(db.getCharacterAtIndex(i).getAge());
    string currentLevel = to_string(db.getCharacterAtIndex(i).getLevel());

    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");
    displays.currentRecordDisplay(win, menuYMax, db.getCharacterAtIndex(i));
    char ch = getch();

    //Change record on screen or exit
    while(ch != END) {
        switch (ch) {
            case 'w': 
                i++;
                if (i == db.getBank().size()) {
                    i = 0;
                }
                break;
            case 's':
                i--;
                if (i == - 1) {
                    i = db.getBank().size() - 1;
                }
                break;
        }

    //Get current index and display on screen
    string location = "";
    location += to_string(i + 1) + '/' + to_string(searchSize);
    displays.refreshInput(inputWin, location);
    
    displays.recordDisplay(win, y);

    //Get all fields from current record
    currentFirstName = db.getCharacterAtIndex(i).getFirstName();
    currentLastName = db.getCharacterAtIndex(i).getLastName();
    currentGender = db.getCharacterAtIndex(i).getGender();
    currentRace = db.getCharacterAtIndex(i).getRace();
    currentJob = db.getCharacterAtIndex(i).getJob();
    currentAge = to_string(db.getCharacterAtIndex(i).getAge());
    currentLevel = to_string(db.getCharacterAtIndex(i).getLevel());

    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");
    displays.currentRecordDisplay(win, menuYMax, db.getCharacterAtIndex(i));
    
    ch = wgetch(inputWin);
    }
}


Listmenu :: ~Listmenu() {
    cout << "Listmenu destructor called" << "\n";
}