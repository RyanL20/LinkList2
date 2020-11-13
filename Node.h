#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node{
 public:
  Node(Student*, Node*);
  ~Node();
  void setNext(Node*);
  Node* getNext();
  void setStudent(Student*);
  Student* getStudent();
 private:
  Node* next;
  Student* student;
};
#endif
