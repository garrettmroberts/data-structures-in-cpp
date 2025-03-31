#include <iostream>

struct Node
{
    int data;
    std::shared_ptr<Node> next;

    Node(int value) : data(value) {}
};

class LinkedList
{
    std::shared_ptr<Node> head;

public:
    LinkedList() : head(NULL) {};

    void insertAtBeginning(int v)
    {
        auto newNode = std::make_shared<Node>(v);
        newNode->next = head;
        head = newNode;
    };

    void insertAtEnd(int v)
    {
        auto newNode = std::make_shared<Node>(v);
        newNode->data = v;
        newNode->next = NULL;
        if (!head)
        {
            head = newNode;
            return;
        }
        auto temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = std::shared_ptr<Node>(newNode);
    };

    void insertAtPosition(int v, int pos)
    {
        if (pos < 0)
        {
            std::cout << "Invalid position.";
        }

        if (pos == 0)
        {
            insertAtBeginning(v);
            return;
        }

        auto newNode = new Node(v);
        newNode->data = v;

        auto temp = head;
        for (int i = 0; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            std::cout << "Invalid position." << std::endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = std::shared_ptr<Node>(newNode);
    };

    void deleteFromBeginning()
    {
        if (!head)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }

        auto temp = head;
        head = head->next;
        temp.reset();
    };

    void deleteFromEnd()
    {
        if (!head)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (!head->next)
        {
            head.reset();
            head = NULL;
            return;
        }

        auto temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }

        temp->next.reset();
        temp->next = NULL;
    }

    void deleteFromPosition(int pos)
    {
        if (!head)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }

        if (pos < 0)
        {
            return;
            std::cout << "Invalid position." << std::endl;
        }

        if (pos == 0)
        {
            deleteFromBeginning();
            return;
        }

        auto temp = head;
        for (int i = 1; i < pos && temp->next; i++)
        {
            temp = temp->next;
        }

        if (!temp->next)
        {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        // Update the links to skip the node at position `pos`
        temp->next = temp->next->next;
    };

    void display()
    {
        if (!head)
        {
            std::cout << "List is empty." << std::endl;
        }

        auto temp = head;
        while (temp)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    };

    int size()
    {
        int count = 0;

        auto temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
