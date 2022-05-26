#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <fstream>

using namespace std;


class Character {
    private: 
        string firstName;
        string lastName;
        string gender;
        string race;
        string job;
        int age;
        int level;


    public:
        void write();

        void setFirstName(string str);
        void setLastName(string str);
        void setGender(string str);
        void setRace(string str);
        void setJob(string str);
        void setAge(int num);
        void setLevel(int num);

        string getFirstName() const;
        string getLastName() const;
        string getGender() const;
        string getRace() const;
        string getJob() const;
        int getLevel() const;
        int getAge() const;
};

#endif
