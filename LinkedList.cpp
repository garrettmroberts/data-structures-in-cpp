#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(NULL) {};

    void insertAtBeginning(int v) {
        Node* newNode = new Node();
        newNode->data = v;
        newNode->next = head;
        head = newNode; 
    };

    void insertAtEnd(int v) {
        Node* newNode = new Node();
        newNode->data = v;
        newNode->next = NULL; 
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    };

    void insertAtPosition(int v, int pos) { 
        if (pos < 0) {
            std::cout << "Invalid position.";
        }

       if (pos == 0) {
          insertAtBeginning(v);
          return;
       } 

       Node* newNode = new Node();
       newNode->data = v;

       Node* temp = head;
       for (int i = 0; i < pos - 1; i++) {
           temp = temp->next;
       }

       if (!temp) {
           std::cout << "Invalid position." << std::endl;
           delete newNode;
           return;
       }

       newNode->next = temp->next;
       temp->next = newNode;
    };

    void deleteFromBeginning() {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        
        Node* temp = head;
        head = head->next; 
        delete temp;
    };

    void deleteFromEnd() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    } 

    void deleteFromPosition(int pos) {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        if (pos < 0) {
            return;
            std::cout << "Invalid position." << std::endl;
        }

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp; i++) {
            if (!temp->next) {
                std::cout << "Invalid position" << std::endl;
                return;
            }
            temp = temp->next;
        }    

        if (!temp || !temp->next) {
            std::cout << "Invalid position." << std::endl;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    };

    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
        }

        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    };
};
