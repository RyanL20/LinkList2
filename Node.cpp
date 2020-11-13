#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

Node::Node(Student* newStudent, Node* newNode) {
  student = newStudent;
  next = newNode;
}
Node::~Node() {
  delete student;
  next = NULL;
}  
void Node::setNext(Node* newNode) {
  next = newNode;
}
Node* Node::getNext() {
  return next;
}
void Node::setStudent(Student* newStudent) {
  student = newStudent;
}
Student* Node::getStudent() {
  return student;
}
