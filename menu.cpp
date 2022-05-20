#include "menu.h"

char Menu :: inputWindow(WINDOW * inputWin, int numOfOptions) {
    box(inputWin, 0, 0);
    mvwprintw(inputWin, 1, 1, "Enter one of the options...");
    wrefresh(inputWin);

    char choice = tolower(wgetch(inputWin));
    bool isOption = false;
    for (int i = 1; i <= numOfOptions; i++) {
        if (choice == (i + '0') || choice == END) {
            isOption = true;
        }
    }

    while(!isOption) {
        wclear(inputWin);
        mvwprintw(inputWin, 1, 1, "Wrong input! Please try again");
        box(inputWin, 0, 0);
        wrefresh(inputWin);
        choice = tolower(wgetch(inputWin));
        for (int i = 1; i <= numOfOptions; i++) {
            if (choice == (i + '0') || choice == END) {
                isOption = true;
            }
        }
    }

    return choice;
}


string Menu :: inputWindow(WINDOW * inputWin, bool isInt) {
    wclear(inputWin);
    box(inputWin, 0, 0);
    mvwprintw(inputWin, 1, 1, "Search...");
    wrefresh(inputWin);

    int maxSize = 12;
    if (isInt) maxSize = 3;
    string str = "";
    char ch = wgetch(inputWin);

    while (ch == '\n' && str.size() == 0) {
        displays.errorDisplayEmpty(inputWin);
        ch = wgetch(inputWin);
    }

    while (ch != '\n') {
        //convert spaces to dashes
        if (ch == ' ') ch = '-';

        if (isValidInput(ch, str[str.size() - 1], isInt)) {
            if (ch == '0' && str.size() == 0) {
                displays.errorDisplayInvalidInput(inputWin);
            }
            else if (str.size() >= maxSize) {
                str = "";
                displays.errorDisplayLimit(inputWin);
            }
            else {
                str += ch;
                displays.refreshInput(inputWin, str);
            }
        }
        
        else {
            str = "";
            if (ch >= '0' && ch <= '9') {
                displays.errorDisplayIntEntered(inputWin);
            }
            else if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A') || ch == '-' || ch == '\'') {
                displays.errorDisplayCharEntered(inputWin);
            }
            else {
                displays.errorDisplayInvalidInput(inputWin);
            }
        }

        ch = wgetch(inputWin);
        while (ch == '\n' && str.size() == 0) {
            displays.errorDisplayEmpty(inputWin);
            ch = wgetch(inputWin);
        }
    }

    return str;
}


bool Menu :: isValidInput(char toAppend, char recentAppend, bool isInt) {
    bool isValidInput = false;

    bool isValidCharacter = false;
    if ((toAppend >= 'a' && toAppend <= 'z') || (toAppend <= 'Z' && toAppend >= 'A') 
        || (toAppend == '\'') || (toAppend == '-')) {
        isValidCharacter = true;
    }

    bool isValidNumber = false;
    if (toAppend >= '0' && toAppend <= '9') {
        isValidNumber = true;
    }

    bool isPunctuationAppropriate = true;
    if ((toAppend == '\'' || toAppend == '-') && (recentAppend == '-' || recentAppend == '\'' || recentAppend == '\0')) {
        isPunctuationAppropriate = false;
    }


    //Field is string-based
    if (isInt) {
        if (isValidNumber) {
            isValidInput = true;
        }
        else {
            isValidInput = false;
        }
    }
    //Field is integer-based
    else {
        if (isValidCharacter) {
            if (!isPunctuationAppropriate) {
                isValidInput = false;
            }
            else {
                isValidInput = true;
            }
        }
        else {
            isValidInput = false;
        }
    }

    return isValidInput;
}


//Used only for ranged based searching (deletemenu, findmenu)
void Menu :: inputWindowRanges(WINDOW * win, WINDOW * inputWin, string& begin, string& end) {
        mvwprintw(win, menuYMax / 2, 2, "Enter start of range...");
        wrefresh(win);
        begin = inputWindow(inputWin, true);

        mvwprintw(win, menuYMax / 2, 2, "Enter end of range...");
        wrefresh(win);
        end = inputWindow(inputWin, true);
}


//Used for getting indices of matches to search or numbers in range (begin - end)
void Menu :: setIndexVec(vector<int> &vec, Database &db, const char fieldType, const char searchType, 
    const string begin, const string end, const string search) {
    //Note: Field options greater or equal to 6 are integers
    if (searchType == '1') {
        if (fieldType < '6') {
        vec = db.exactSearchString(fieldType, search); 
        }
        else {
        vec = db.exactSearchInt(fieldType, stoi(search)); 
        }
    }
    else {
        if (fieldType < '6') {
            vec= db.substringSearch(fieldType, search);
        }
        else {
            vec= db.rangeSearch(fieldType, stoi(begin), stoi(end));
        }
    }
}
    
