#ifndef DATABASE_H
#define DATABASE_H

#include "database.h"
#include "character.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


class Database {
    private:
        vector<Character> characterBank;

    public:
        Database();

        //Get member functions
        vector<Character> getBank() const;
        Character getCharacterAtIndex(int i) const;
        string getStringFieldFromCharacter(char fieldChoice, int i) const;
        int getIntFieldFromCharacter(char fieldChoice, int i) const;

        //Finding member functions
        bool findMatchingRecord(Character newCharacter);

        //Searching member functions
        vector<int> exactSearchString(char fieldChoice, string search);
        vector<int> exactSearchInt(char fieldChoice, int search);
        vector<int> substringSearch(char fieldChoice, string search);
        vector<int> rangeSearch(char fieldChoice, int start, int end);

        //Sorting member functions
        void ascendingSort(char choice);
        void descendingSort(char choice);
        
        //Database mutation functions
        void deleteCharacter(int index);
        void addCharacter(Character newCharacter);
        void rewrite();
};

#endif