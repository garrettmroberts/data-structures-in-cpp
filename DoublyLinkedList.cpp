#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    shared_ptr<Node> prev;
    shared_ptr<Node> next;

    Node(int value) : data(value), prev(), next() {}
};

class DoublyLinkedList
{
private:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    int size()
    {
        int count = 0;       // Initialize count to 0
        auto current = head; // Start from the head of the list
        while (current)      // Traverse the list until the end
        {
            count++;                 // Increment count for each node
            current = current->next; // Move to the next node
        }

        return count; // Return the total count of nodes
    };

    void insertAtBeginning(int value)
    {
        shared_ptr<Node> newNode = std::make_shared<Node>(value); // Create a new node with the given value
        if (!head)                                                // If the list is empty, set both head and tail to the new node
        {
            head = newNode;
            tail = newNode;
        }
        else // If the list is not empty, insert the new node at the beginning
        {
            newNode->next = head; // Point new node's next to current head
            head->prev = newNode; // Point current head's prev to new node
            head = newNode;       // Update head to new node
        }
    }

    void insertAtEnd(int data)
    {
        shared_ptr<Node> newNode = make_shared<Node>(data); // Create a new node with the given data
        if (!tail)
        { // If the list is empty, set both head and tail to the new node
            head = newNode;
            tail = newNode;
        }
        else
        {                         // If the list is not empty, insert the new node at the end
            tail->next = newNode; // Point the current tail's next to the new node
            newNode->prev = tail; // Point the new node's prev to the current tail
            tail = newNode;       // Update the tail to the new node
        }
    };

    void insertAtPosition(int data, int position)
    {
        if (position < 0)
        {
            cout << "Invalid position. Must be >= 0." << endl;
            return; // Invalid position, return without inserting
        }
        if (position == 0)
        { // If position is 0, insert at the beginning
            insertAtBeginning(data);
            return; // Insertion done, return
        }
        int currentPosition = 0;                            // Start from the head
        shared_ptr<Node> newNode = make_shared<Node>(data); // Create a new node with the given data
        auto current = head;                                // Start from the head of the list
        while (current && currentPosition < position - 1)
        {                            // Traverse the list to find the position
            current = current->next; // Move to the next node
            currentPosition++;       // Increment the current position
        }

        if (!current)
        { // If current is null, it means position is greater than the size of the list
            cout << "Position is out of bounds. Inserting at the end." << endl;
            insertAtEnd(data); // Insert at the end if position is out of bounds
            return;            // Return after insertion
        }
        else
        {
            newNode->next = current->next;
            newNode->prev = current; // Set the new node's prev to the current node
            current->next = newNode; // Point the current node's next to the new node
        }
    };

    void deleteFromBeginning()
    {
        shared_ptr<Node> temp = head; // Store the current head to delete it later
        if (!head)
        { // If the list is empty, nothing to delete
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (head == tail)
        {                   // If there is only one node in the list
            head = nullptr; // Set head to null
            tail = nullptr; // Set tail to null
        }
        else
        {                         // If there are multiple nodes
            head = head->next;    // Move the head pointer to the next node
            head->prev = nullptr; // Set the new head's prev to null
        }
    };

    void deleteFromEnd()
    {
        shared_ptr<Node> temp = head;
        if (!head)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
    };

    void deleteNode(int value)
    {
        auto current = head;
        while (current->data != value && current)
        {
            current = current->next;
        }

        if (!current)
        {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        if (current == head)
        {
            deleteFromBeginning();
        }
        else if (current == tail)
        {
            deleteFromEnd();
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
    };

    void reverse()
    {
        if (!head)
        {
            cout << "List is empty.";
            return;
        }

        auto current = head;
        shared_ptr<Node> tmp = nullptr;

        // Traverse the list while swapping next and prev pointers
        while (current)
        {
            tmp = current->prev;
            current->prev = current->next;
            current->next = tmp;
            current = current->prev;
        }

        // Swap head and tail pointers
        if (tmp)
        {
            head = tmp->prev;
            tail = tmp->next;
        }
    };

    void display()
    {
        auto current = head;
        while (current)
        {
            cout << current->data << " ";
            current = std::shared_ptr<Node>(current->next);
        }
        cout << "NULL" << endl;
    };
};
