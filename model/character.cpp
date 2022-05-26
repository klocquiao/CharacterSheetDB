#include "character.h"

//SET functions
void Character :: setFirstName(string str) {
    firstName = str;
}
void Character :: setLastName(string str) {
    lastName = str;
}
void Character :: setGender(string str) {
    gender = str;
}
void Character :: setRace(string str) {
    race = str;
}
void Character :: setJob(string str) {
    job = str;
}
void Character :: setLevel(int num) {
    level = num;
}
void Character :: setAge(int num) {
    age = num;
}


//GET functions
string Character :: getFirstName() const {
    return firstName;
}
string Character :: getLastName() const {
    return lastName;
}
string Character :: getGender() const {
    return gender;
}
string Character :: getRace() const {
    return race;
}
string Character :: getJob() const {
    return job;
}
int Character :: getLevel() const {
    return level;
}
int Character :: getAge() const {
    return age;
}


//Saves character record to database.txt
void Character :: write() {
    ofstream myfile;
    myfile.open ("database.txt", ios::app);
    myfile << firstName << ", ";
    myfile << lastName << ", ";
    myfile << gender << ", ";
    myfile << race << ", ";
    myfile << job << ", ";
    myfile << age << ", ";
    myfile << level << "\n";
    myfile.close();
}






