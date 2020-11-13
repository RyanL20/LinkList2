#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student {
 public:
  Student();
  Student(char* newFirstName, char* newLastName, int ID, float GPA);
     ~Student();

     void setFirstName(char* newFirstName);
     char* getFirstName();
     void setLastName(char* newLastName);
     char* getLastName();
     void setID(int newID);
     int getID();
     void setGPA(float newGPA);
     float getGPA();
 private:
     char* firstName;
     char* lastName;
     int ID;
     float GPA;
};
#endif
