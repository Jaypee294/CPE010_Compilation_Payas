
#ifndef QUEUE_H
#define QUEUE_H

struct Node
{
    char data;
    Node* next;

    Node(char value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void enqueue(char value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    char dequeue()
    {
        if (isEmpty())
        {
            return '\0';
        }
        Node* temp = front;
        char value = temp->data;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;

        return value;
    }
};

#endif
