#include <iostream>

struct Node
{
    int data;
    Node* next;
};

int main()
{
    int values[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 10; i++)
    {
        Node* newNode = new Node;
        newNode->data = values[i];
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int key = 18;
    int comparisons = 0;
    Node* current = head;

    while (current != nullptr)
    {
        comparisons++;

        if (current->data == key)
        {
            std::cout << "Key found: "
                      << current->data << std::endl;
            break;
        }

        current = current->next;
    }

    std::cout << "Number of comparisons: "
              << comparisons << std::endl;

    return 0;
}
