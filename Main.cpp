#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Student.h"
#include "Node.h"

// This program is to create ADD, PRINT, AVERAGE GPA and DELETE student record from linked list.
// By: Ryan Le
// Date:11/13/2020

void ADD (Node* head);
void ADD_R (Node* head, Student* newStudent);
void PRINT (Node* head, bool node_1);
float AVERAGE (Node* head, bool node_1, float sum, int count);
void DELETE (Node* head, bool node_1);
void DELETE_R (Node* head, bool node_1, int id);

using namespace std;

int main() {
  Student newStudent;
  
  //Instructions
  cout << "Executable Actions: ADD, PRINT, DELETE, AVERAGE, QUIT" << endl;
  
 Node* head = new Node(&newStudent, NULL);

  head->setNext(NULL);
  char* input = new char[80];

 //checks if user typed ADD, PRINT, DELETE, QUIT, or something else
  bool exit = 0;
  
  while (exit == 0) {
    cin >> input;
    if (input[0] == 'A' && input[1] == 'D' && input[2] == 'D' && input[3] == '\0') {
      ADD(head);
    }
    else if (input[0] == 'P' && input[1] == 'R' && input[2] == 'I' && input[3] == 'N' && input[4] == 'T' && input[5] == '\0') { 
      PRINT (head, 1);
    }
    else if (input[0] == 'D' && input[1] == 'E' && input[2] == 'L' && input[3] == 'E' && input[4] == 'T' && input[5] == 'E' && input[6] == '\0') {
      DELETE(head, true);
    }
    else if (input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T' && input[4] == '\0') {
      cout << "EXITED PROGRAM" << endl;
      exit = 1;
    }
    else if (input[0] == 'A' && input[1] == 'V' && input[2] == 'E' && input[3] == 'R' && input[4] == 'A' && input[5] == 'G' && input[6] == 'E' && input[7] == '\0') {
      float avg_gpa = AVERAGE(head, true, 0, 0);
      cout << "Average GPA: " << avg_gpa << endl;
      
  }
    else {
      cout << "Incorrect Input: ADD, PRINT, DELETE, AVERAGE, or QUIT" << endl;
    }
    cout << "--------------------------" << endl;
    cout << "ADD, PRINT, DELETE, AVERAGE, QUIT" << endl;
  }
  return 0;
 
}

//*************************
//ADD function
//***********************
// This function pass head pointer, take user inputs assign to Student class. 
void ADD(Node* currentNode) {
  
  char* inputf = new char[80];
  char* inputl = new char[80];
  Student* newStudent = new Student();
  cout << "Student First Name:" << endl;
  cin >> inputf;
  newStudent->setFirstName(inputf);
  //Debug - cout << inputf << " First Input " << endl;
  
  cout << "Student Last Name:" << endl;
  cin >> inputl;
  newStudent->setLastName(inputl);
  //Debug - cout << inputl << " input " << endl; 
  
  cout << "Student ID:" << endl;
  int newID;
  cin >> newID;
  newStudent->setID(newID);

  cout << "Student GPA:" << endl;
  float newGPA;
  cin >> newGPA;
  newStudent->setGPA(newGPA);

  // Assign curentnode (head) new node and new node->next point to NULL
  if (currentNode->getNext() == NULL) {
    Node* grandNode = new Node(newStudent, NULL);
    currentNode->setNext(grandNode);  
    grandNode->setNext(NULL);
    return;
  }
      
  // Compare ID and insert orderly asscending onto the existing linked list.
  int new_ID; int current_ID;
  new_ID = newStudent->getID();
  current_ID = currentNode->getNext()->getStudent()->getID();

  if(current_ID > new_ID) {
    Node* brandNode = new Node(newStudent, NULL);
    brandNode->setNext(currentNode->getNext());
    currentNode->setNext(brandNode);
    return;
  }

  // call ADD_R func to insert new funciton
  if(current_ID < new_ID) {
    ADD_R(currentNode->getNext(), newStudent);
    return;
  }
}

//This function is to create a new Node student class and add to linked list.  This func is called recursively in ADD func.
void ADD_R(Node* currentNode, Student* newStudent) {
   if(currentNode->getNext() == NULL) {
     Node* brandNode = new Node(newStudent, NULL);
     currentNode->setNext(brandNode);
     brandNode->setNext(NULL);
     return;
   }
   // add new student node ascending order
   int current_ID = currentNode->getNext()->getStudent()->getID();
   int new_ID = newStudent->getID();
   
   if (current_ID >= new_ID)  {
     Node* brandNode = new Node(newStudent, NULL);
     brandNode->setNext(currentNode->getNext());
     currentNode->setNext(brandNode);
     return;
   }

   if(current_ID < new_ID) {
     ADD_R(currentNode->getNext(), newStudent);
     return;
   }
}


//********************
// PRINT function
//********************
//Goes through and prints the student info from each Node
void PRINT (Node* currentNode, bool node_1) {

  // Print if no student record if user tries to print out before add any record.
  if((currentNode->getNext() == NULL) && node_1) {
    cout << "Empty linked list - No students record. Please try to ADD first\n";
    return;
  }
  // Print header + record if node_1 is true.  Then set to false.
  if (node_1) {
    cout << "Student Record:" << endl;
    cout << "First Name" << '\t';
    cout << "Last Name" << '\t';
    cout << "ID" << '\t';
    cout << "GPA" << endl;
    PRINT (currentNode->getNext(), false);
    currentNode->setNext(currentNode->getNext());
    return;
  }
  //If it isn't the first itteration and the next one is NULL, then just print out the information from that NODE and return
  if(currentNode->getNext() == NULL) {  
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
   // Debug - cout << currentNode << endl;
   cout << currentNode->getStudent()->getFirstName() << '\t' << '\t';
   cout << currentNode->getStudent()->getLastName()  << '\t' << '\t';
   cout << currentNode->getStudent()->getID() << "\t";
   cout << currentNode->getStudent()->getGPA() << endl;
   return;
    
  }
  else {
    // Debug - cout << currentNode << " PRINT " << endl;
    cout << currentNode->getStudent()->getFirstName() << '\t' << '\t';
    cout << currentNode->getStudent()->getLastName()  << '\t' << '\t';
    cout << currentNode->getStudent()->getID() << '\t';
    cout << currentNode->getStudent()->getGPA() << endl;
    PRINT (currentNode->getNext(), false);
    return;
  }
  
}


//**********************************************
// AVERAGE function to return average of all GPA by traversing all student linked list.
//**********************************************

float AVERAGE(Node* currentNode, bool node_1, float sum, int count) {
  if((currentNode->getNext() == NULL) && node_1) {
    cout << "No students yet!\n";
    return 0;
  }

  else if (node_1) {
    return AVERAGE(currentNode->getNext(), false, sum, count);
  }
  else if(currentNode->getNext() == NULL) {
    sum += currentNode->getStudent()->getGPA();
    count++;
    float average = sum/count;
    return average;
  }
  else {
    sum += currentNode->getStudent()->getGPA();
    count++;
    return AVERAGE(currentNode->getNext(), false, sum, count);
  }
}

//********************************
// DELETE function - Remove student record from the linked list
//********************************

void DELETE(Node* currentNode, bool node_1) {
  if((currentNode->getNext() == NULL) && node_1) {
      cout << "No students record!\n";
      return;
    }

  int input_ID;
  cout << "Enter ID to delete: ";
  cin >> input_ID;
  
  if((currentNode->getNext() == NULL) && node_1) {
    cout << "No student record!\n";
    return;
  }
  // Compare ID and delete
  int current_ID = currentNode->getNext()->getStudent()->getID();
  if(current_ID == input_ID) {
    cout << "Student record found" << endl;
    cout << "First Name: " << currentNode->getNext()->getStudent()->getFirstName() << endl;
    cout << "Last Name: " << currentNode->getNext()->getStudent()->getLastName() << endl;
    cout << "ID: " << currentNode->getNext()->getStudent()->getID() << endl;
    cout << "GPA: " << currentNode->getNext()->getStudent()->getGPA() << endl;
    char* input = new char[1];
    cout << "Y (Yes) or N (No) for delete: ";
    cin >> input;
    //If user said yes, delete the person
    if (strcmp(input, "Y") == 0) {
      cout << " delete " << endl;
      currentNode->setNext(currentNode->getNext()->getNext());
      return;
    }
    else if(strcmp(input, "N")==0) {
      cout << "Student not deleted\n";
      return;
    }
    else {
      cout << "Invalid input" << endl;
      return;
    }
  }
  //call the function agian with the next NODE in the list
  else{
    DELETE_R(currentNode->getNext(), false, input_ID);
    return;
  }
}


void DELETE_R(Node* currentNode, bool node_1, int input_ID) {
 
   //If the next one is null, return not found.
  if(currentNode->getNext() == NULL) {
    cout << "No student found.\n";
    return;
  }
  
  int current_ID = currentNode->getNext()->getStudent()->getID();
  if (current_ID == input_ID) {
    cout << "Student record found" << endl;
    cout << "First Name: " << currentNode->getNext()->getStudent()->getFirstName() << endl;
    cout << "Last Name: " << currentNode->getNext()->getStudent()->getLastName() << endl;
    cout << "ID: " << currentNode->getNext()->getStudent()->getID() << endl;
    cout << "GPA: " << currentNode->getNext()->getStudent()->getGPA() << endl;

    char* input = new char[1];
    cout << "Y (Yes) or N (No) for delete: ";
    cin >> input;

    if(strcmp(input, "Y") == 0) {
      //Call destructor for currentNode->getNext();
      currentNode->setNext(currentNode->getNext()->getNext());
      return;
    }
    else if(strcmp(input, "N") == 0) {
      cout << "Student not deletedt\n";
      return;
    }
    else {
      cout << "Invalid input";
      return;
    }
  }
  //Otherwise, call the function again with the next node
  else {
    DELETE_R(currentNode->getNext(), false, input_ID);
    return;
  }
}
