// a3.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Kyle Locquiao
// St.# : 301412765
// Email: knl5@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

/* CITATIONS
  1. https://www.youtube.com/watch?v=g7Woz3YVgvQ&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=15
        - Adapted method of creating an ncurses menubar for the menu system of my program
        - I've also learned most of the basics of ncurses from this channel

  2. https://stackoverflow.com/questions/24120062/sort-a-vector-of-objects
        - Used a similar method of using a lambda expression w/ the sort function from <algorithm> to 
            sort the vector containing records

  3. https://stackoverflow.com/questions/6939129/how-to-use-stdfind-stdfind-if-with-a-vector-of-custom-class-objects
        - Got the idea of using a lambda expression w/ the find_if function from <algorithm> from this source
        - Used the following source to help me correctly do this https://www.geeksforgeeks.org/lambda-expression-in-c/

  4. Function used to find substrings of a search is taken from one of the previous challenges

  5. Adapted make file from previous assignment

*/

#include <ncurses.h>
#include "character.h"
#include "database.h"
#include "mainmenu.h"
#include "addmenu.h"
#include "findmenu.h"
#include "deletemenu.h"
#include "listmenu.h"

 int main() {
    Database data;
    Mainmenu * mainMenu = new Mainmenu;
    Addmenu * addMenu = new Addmenu;
    Findmenu * findMenu = new Findmenu;
    Deletemenu * deleteMenu = new Deletemenu;
    Listmenu * listMenu = new Listmenu;

    while (mainMenu->getChoice() != 'e') {
        switch(mainMenu->getChoice()) {
            case '1': 
                clear();
                refresh();
                addMenu->getMenu(data);
                mainMenu->getMenu();
                break;
        
            case '2': 
                clear();
                refresh();
                findMenu->getMenu(data);
                mainMenu->getMenu();
                break;
            case '3':
                clear();
                refresh();
                deleteMenu->getMenu(data);
                mainMenu->getMenu();
                break;
            case '4':
                clear();
                refresh();
                listMenu->getMenu(data);
                mainMenu->getMenu();
                break;
        }
    }

    delete mainMenu;
    delete addMenu;
    delete findMenu;
    delete deleteMenu;
    delete listMenu;
    cout << "Program has been successfully terminated";
 }

