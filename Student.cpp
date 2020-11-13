#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

Student::Student() {
  firstName = new char[80];
  lastName = new char[80];
}

Student::Student(char* newFirstName, char* newLastName, int newID, float newGPA) {
  firstName = new char[80];
  lastName = new char[80];

  //strcpy(firstName, newFirstName);
  //strcpy(lastName, newLastName);
  ID = newID;
  GPA = newGPA;
}

Student::~Student() {
}

void Student::setFirstName(char* newFirstName) {
  firstName = newFirstName;
  //strcpy(firstName, newFirstName);
}
char* Student::getFirstName() {
  return firstName;
}
void Student::setLastName(char* newLastName) {
  lastName = newLastName;
  //strcpy(lastName, newLastName);
}
char* Student::getLastName() {
  return lastName;
}
void Student::setID(int newID) {
  ID = newID;
}
int Student::getID() {
  return ID;
}
void Student::setGPA(float newGPA) {
  GPA = newGPA;
}
float Student::getGPA() {
  return GPA;
}

