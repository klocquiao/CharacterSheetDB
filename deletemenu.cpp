#include "deletemenu.h"

Deletemenu :: Deletemenu() {
    getmaxyx(stdscr, yMax, xMax);
    win = newwin(yMax / 1.5, xMax / 1.5, yMax / 6, xMax / 6);
    getmaxyx(win, menuYMax, menuXMax);
    inputWin = newwin(3, xMax / 1.5, (yMax / 1.5) + (yMax / 6) , xMax / 6);
}


void Deletemenu :: getMenu(Database &db) {
    displays.fieldTypeDisplay(win, menuYMax, menuXMax);


    char fieldType = inputWindow(inputWin, 7);
    if (fieldType == END) {
        endwin();
        return;
    }

    if (fieldType < '6') {
        displays.searchTypeStringDisplay(win, menuYMax, menuXMax);
    }
    else {
        displays.searchTypeIntDisplay(win, menuYMax, menuXMax);
    }

    char searchType = inputWindow(inputWin, 2);
    if (searchType == END) {
        endwin();
        return;
    }

    displays.refreshWindow(win);

    string search;
    string begin;
    string end;

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


    vector<int> indexVec;        
    setIndexVec(indexVec, db, fieldType, searchType, begin, end, search);

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


void Deletemenu :: scrollData(vector<int> posVec, Database &db, int y) {
    int i = 0;
    int searchSize = posVec.size();

    box(inputWin, 0, 0);
    mvwprintw(inputWin, 1, 1, "Use 'W'/'S' to navigate; 'ENTER' to delete records");
    wrefresh(inputWin);

    displays.recordDisplay(win, y);

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
    char ch = wgetch(inputWin);

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
            
            case '\n':
                wclear (inputWin);
                box(inputWin, 0, 0);
                mvwprintw(inputWin, 1, 1, "Press 'ENTER' again to confirm deletion");
                wrefresh(inputWin);

                char endOption = tolower(wgetch(inputWin));
            
                switch (endOption) {
                    case '\n': 
                        deleteRecords(posVec, db);
                        return;
                    default: 
                        break;
                }
        }

    string location = "";
    location += to_string(i + 1) + '/' + to_string(searchSize);
    displays.refreshInput(inputWin, location);

    displays.recordDisplay(win, y);

    currentRecord = posVec.at(i);
    currentFirstName = db.getCharacterAtIndex(currentRecord).getFirstName();
    currentLastName = db.getCharacterAtIndex(currentRecord).getLastName();
    string currentGender = db.getCharacterAtIndex(currentRecord).getGender();
    currentRace = db.getCharacterAtIndex(currentRecord).getRace();
    currentJob = db.getCharacterAtIndex(currentRecord).getJob();
    currentAge = to_string(db.getCharacterAtIndex(currentRecord).getAge());
    currentLevel = to_string(db.getCharacterAtIndex(currentRecord).getLevel());


    mvwprintw(win, menuYMax - 1, menuXMax - 6, "(E)xit");
    displays.currentRecordDisplay(win, menuYMax, db.getCharacterAtIndex(currentRecord));
    
    ch = wgetch(inputWin);
    }
}


void Deletemenu :: deleteRecords(vector<int> posVec, Database &db) {
    int numOfVectorsToDelete = posVec.size();
    cout << numOfVectorsToDelete;
    for (int i = 0; i < numOfVectorsToDelete; i++) {
        db.deleteCharacter(posVec.at(i) - i);
    }
    db.rewrite();
}


Deletemenu :: ~Deletemenu() {
    cout << "Deletemenu destructor called" << "\n";
}