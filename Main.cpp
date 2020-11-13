#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

int main() {
  char* firstName;
  char* lastName;
  float GPA;
  int ID;
  Student newStudent (firstName, lastName, GPA, ID);
  Node* firstNode = new Node(&newStudent, NULL);
  Student* NewStudent = new Student();
  firstNode->setNext(NULL);
  NewStudent->setGPA(3.1);
  char* input = new char[80];
  cout << "test" << endl;
  cin >> input;
  NewStudent->setFirstName(input);


  //char* setFirstName = "Bobby";
  //NewStudent->setFirstName(input);
  //cout << NewStudent->getGPA() << endl;
  cout << NewStudent->getFirstName() << endl;
}
