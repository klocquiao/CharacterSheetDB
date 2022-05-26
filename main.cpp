#include <ncurses.h>
#include "model/character.h"
#include "model/database.h"
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

