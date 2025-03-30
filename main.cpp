#include <iostream>
#include "LinkedList.cpp"

int main()
{
  LinkedList list1;

  list1.insertAtEnd(10);
  list1.insertAtEnd(20);
  list1.insertAtEnd(30);
  list1.display(); // [10, 20, 30]

  list1.insertAtBeginning(5);
  list1.insertAtPosition(7, 1);
  list1.display(); // [5, 7, 10, 20, 30]

  list1.deleteFromBeginning();
  list1.deleteFromEnd();
  list1.display(); // [7, 10, 20]

  list1.deleteFromPosition(1);
  list1.display(); // [7, 20]

  return 0;
}
