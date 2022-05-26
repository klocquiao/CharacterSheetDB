#include "database.h"

//Transfers data from txt file to a vector usable by the program
Database :: Database() {
	ifstream file("database.txt");
	while (true) {
		Character character;
        string strRecord;
        string field;
		getline (file, strRecord);
		if (file.fail()) {
			break;
 		}

        //Each record needs 5 fields
        stringstream ss(strRecord);
        for (int i = 1; i <= 7; i++) {
            ss >> field;
            field = field.substr(0, field.find(','));
            switch (i) {
                case 1:
                    character.setFirstName(field);
                    break;
                case 2:
                    character.setLastName(field);
                    break;
                case 3:
                    character.setGender(field);
                    break;
                case 4:
                    character.setRace(field);
                    break;
                case 5:
                    character.setJob(field);
                    break;
                case 6:
                    character.setAge(stoi(field));
                    break;
                case 7:
                    character.setLevel(stoi(field));
                    break;
            }
        }

		characterBank.push_back(character);
	}
}


//GET functions
string Database :: getStringFieldFromCharacter(char fieldChoice, int i) const {
    string field;
    switch(fieldChoice) {
        case '1': field = characterBank.at(i).getFirstName(); break;
        case '2': field = characterBank.at(i).getLastName(); break;
        case '3': field = characterBank.at(i).getGender(); break;
        case '4': field = characterBank.at(i).getRace(); break;
        case '5': field = characterBank.at(i).getJob(); break;
    }

    return field;
}


int Database :: getIntFieldFromCharacter(char fieldChoice, int i) const {
    int field;
    switch(fieldChoice) {
        case '6': field = characterBank.at(i).getAge(); break;
        case '7': field = characterBank.at(i).getLevel(); break;
    }

    return field;
}


vector<Character> Database :: getBank() const {
    return characterBank;
}


Character Database :: getCharacterAtIndex(int i) const {
    return characterBank.at(i);
}


//Searching functions
vector<int> Database :: exactSearchString(char fieldChoice,  string search) {
    vector<int> pos;
    string field;

    for(int i = 0; i < characterBank.size(); i++) {
        field = getStringFieldFromCharacter(fieldChoice, i);
        for (int i = 0; i < field.size(); i++) {
            field[i] = tolower(field[i]);
        }
        if (field == search) {
            pos.push_back(i);
        }
    }

    return pos;
}


vector<int> Database :: substringSearch(char fieldChoice,  string search) {
    vector<int> pos;
    string field;

    for(int i = 0; i < characterBank.size(); i ++) {
        field = getStringFieldFromCharacter(fieldChoice, i);
        for (int i = 0; i < field.size(); i++) {
            field[i] = tolower(field[i]);
        }
        if (field.find(search) != string::npos) {
            pos.push_back(i);   
        }
    }

    return pos;
}


vector<int> Database :: exactSearchInt(char fieldChoice,  int search) {
    vector<int> pos;
    int field;
        for(int i = 0; i < characterBank.size(); i++) {
            field = getIntFieldFromCharacter(fieldChoice, i);
            if (field == search) {
                pos.push_back(i);
            }
        }

    return pos;
}


vector<int> Database :: rangeSearch(char fieldChoice,  int start, int end) {
    vector<int> pos;
    int field;
        for(int i = 0; i < characterBank.size(); i++) {
            field = getIntFieldFromCharacter(fieldChoice, i);
            if (field >= start && field <= end) {
                pos.push_back(i);
            }
        }

    return pos;
}


bool Database :: findMatchingRecord(Character newRecord) {
    auto it = find_if(characterBank.begin(), characterBank.end(), [newRecord](const Character& a) {
        return (a.getFirstName() == newRecord.getFirstName()) && (a.getLastName() == newRecord.getLastName()) &&
            (a.getRace() == newRecord.getRace()) && (a.getJob() == newRecord.getJob()) && (a.getLevel() == newRecord.getLevel()) &&
            (a.getAge() == newRecord.getAge()) && (a.getGender() == newRecord.getGender());
    });

    if (it != characterBank.end()) {
        return true;
    }
    else {
        return false;
    }
}


//Sorting functions
void Database :: ascendingSort(char choice) {
    switch(choice) {
        case '1': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getFirstName() < b.getFirstName(); 
        }); break;

        case '2': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getLastName() < b.getLastName();
        }); break;

        case '3': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getGender() < b.getGender();
        }); break;

        case '4': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getRace() < b.getRace();
        }); break;

        case '5': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getJob() < b.getJob();
        }); break;

        case '6': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getAge() < b.getAge();
        }); break;
        case '7': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getLevel() < b.getLevel();
        }); break;
    }
}


void Database :: descendingSort(char choice) {
    switch(choice) {
        case '1': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getFirstName() > b.getFirstName();
        }); break;

        case '2': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getLastName() > b.getLastName();
        }); break;

        case '3': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getGender() > b.getGender();
        }); break;

        case '4': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getRace() > b.getRace();
        }); break;

        case '5': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getJob() > b.getJob();
        }); break;

        case '6': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getAge() > b.getAge();
        }); break;

        case '7': sort(characterBank.begin(), characterBank.end(), [](const Character& a, const Character& b) {
            return a.getLevel() > b.getLevel();
        }); break;


    }
}


//Database manipulation functions
void Database:: addCharacter(Character newCharacter) {
    characterBank.push_back(newCharacter);
}


void Database :: deleteCharacter(int index) {
    characterBank.erase(characterBank.begin() + index);
}


void Database :: rewrite() {
    ofstream myfile;
    myfile.open ("database.txt", ios::trunc);
    for (Character ch: characterBank) {
        myfile << ch.getFirstName() << ", ";
        myfile << ch.getLastName() << ", ";
        myfile << ch.getGender() << ", ";
        myfile << ch.getRace() << ", ";
        myfile << ch.getJob() << ", ";
        myfile << ch.getAge() << ", ";
        myfile << ch.getLevel() << "\n";

    }
    myfile.close();
}







    
