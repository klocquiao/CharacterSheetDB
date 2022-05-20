#include "findmenu.h"

using namespace std;

Findmenu :: Findmenu() {
    getmaxyx(stdscr, yMax, xMax);
    win = newwin(yMax / 1.5, xMax / 1.5, yMax / 6, xMax / 6);
    getmaxyx(win, menuYMax, menuXMax);
    inputWin = newwin(3, xMax / 1.5, (yMax / 1.5) + (yMax / 6) , xMax / 6);
}


void Findmenu :: getMenu(Database& db) {
    displays.fieldTypeDisplay(win, menuYMax, menuXMax);

    //Choose field option
    char fieldType = inputWindow(inputWin, 7);
    if (fieldType == END) {
        endwin();
        return;
    }

    //Field options above 6 are integers
    if (fieldType < '6') {
        displays.searchTypeStringDisplay(win, menuYMax, menuXMax);
    }
    else {
        displays.searchTypeIntDisplay(win, menuYMax, menuXMax);
    }

    //Choose search option
    char searchType = inputWindow(inputWin, 2);
    if (searchType == END) {
        endwin();
        return;
    }

    displays.refreshWindow(win);

    //Get string for search from user
    string search;
    string begin;
    string end;

    //Range search (int field, search type 2) requires 2 inputs!
    if (fieldType >= '6') {
        if (searchType == '2') {
        inputWindowRanges(win, inputWin, begin, end);
        }
        else search = inputWindow(inputWin, true);
    }
    else { 
        search = inputWindow(inputWin, false);
        for (int i = 0; i < search.size(); i++) {
            search[i] = tolower(search[i]);
        }
    }


    //Get indices of all records that matches search
    vector<int> indexVec;        
    setIndexVec(indexVec, db, fieldType, searchType, begin, end, search);

    //Browse all matching records if possible
    if (indexVec.size() > 0) {
        scrollData(indexVec, db, menuYMax);
    }
    else {
        mvwprintw(win, menuYMax / 2, 2, "No Matches! Press anything to continue...");
        wrefresh(win);
        getch();
    }
    
    displays.refreshWindow(win);
    displays.refreshWindow(win);
    endwin();
}


void Findmenu :: scrollData(vector<int> posVec, Database &db, int y) {
    int i = 0;
    int searchSize = posVec.size();
    box(inputWin, 0, 0);
    mvwprintw(inputWin, 1, 1, "Use 'W'/'S' to navigate");
    wrefresh(inputWin);

    displays.recordDisplay(win, y);

    //Get all fields from current record
    int currentRecord = posVec.at(i);
    string currentFirstName = db.getCharacterAtIndex(currentRecord).getFirstName();
    string currentLastName = db.getCharacterAtIndex(currentRecord).getLastName();
    string currentGender = db.getCharacterAtIndex(currentRecord).getGender();
    string currentRace = db.getCharacterAtIndex(currentRecord).getRace();
    string currentJob = db.getCharacterAtIndex(currentRecord).getJob();
    string currentAge = to_string(db.getCharacterAtIndex(currentRecord).getAge());
    string currentLevel = to_string(db.getCharacterAtIndex(currentRecord).getLevel());


    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");
    displays.currentRecordDisplay(win, menuYMax, db.getCharacterAtIndex(currentRecord));
    char ch = getch();

    //Change record on screen or exit
    while(ch != END) {
        switch (ch) {
            case 'w': 
                i++;
                if (i == posVec.size()) {
                    i = 0;
                }
                break;
            case 's':
                i--;
                if (i == - 1) {
                    i = posVec.size() - 1;
                }
                break;
        }
    
    //Get current index and display on screen
    string location = "";
    location += to_string(i + 1) + '/' + to_string(searchSize);
    displays.refreshInput(inputWin, location);

    displays.recordDisplay(win, y);

    //Get all fields from current record
    currentRecord = posVec.at(i);
    currentFirstName = db.getCharacterAtIndex(currentRecord).getFirstName();
    currentLastName = db.getCharacterAtIndex(currentRecord).getLastName();
    currentGender = db.getCharacterAtIndex(currentRecord).getGender();
    currentRace = db.getCharacterAtIndex(currentRecord).getRace();
    currentJob = db.getCharacterAtIndex(currentRecord).getJob();
    currentAge = to_string(db.getCharacterAtIndex(currentRecord).getAge());
    currentLevel = to_string(db.getCharacterAtIndex(currentRecord).getLevel());

    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");
    displays.currentRecordDisplay(win, menuYMax, db.getCharacterAtIndex(currentRecord));
    
    ch = wgetch(inputWin);
    }
}


Findmenu :: ~Findmenu() {
    cout << "Findmenu destructor called" << "\n";
}