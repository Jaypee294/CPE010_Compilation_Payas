#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    static const int MAX = 100;
    char data[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == MAX - 1;
    }

    void push(char value)
    {
        if (!isFull())
        {
            data[++top] = value;
        }
    }

    char pop()
    {
        if (!isEmpty())
        {
            return data[top--];
        }

        return '\0';
    }
};

#endif
