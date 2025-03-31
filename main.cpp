#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

int main()
{
    DoublyLinkedList list;
    
    // Example usage of DoublyLinkedList methods
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    list.display(); // 10 20 30 null
    cout << "Size of the list: " << to_string(list.size()) << endl; // Should print 3
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display(); // 10 20 30 40 50 null
    list.insertAtPosition(25, 2);
    list.insertAtPosition(5, 0);
    list.insertAtPosition(60, 10); 
    list.display(); // 5 10 20 25 30 40 50 60 null
    list.deleteFromBeginning();
    list.display(); // 10 20 25 30 40 50 60 null
    list.deleteFromEnd();
    list.display(); // 10 20 25 30 40 50 null
    list.deleteNode(25);
    list.display(); // 10 20 30 40 50 null

    return 0;
}
