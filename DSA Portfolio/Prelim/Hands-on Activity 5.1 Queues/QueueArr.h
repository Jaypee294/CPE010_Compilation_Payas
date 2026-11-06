#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>
#include <cstddef>

template <typename T>
class QueueArr
{
private:
    T* q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    QueueArr(size_t capacity);
    QueueArr();

    ~QueueArr();

    bool Empty() const;
    bool Full() const;

    size_t Size() const;
    void clear();

    T front() const;
    T back() const;

    void Enqueue(T newData);
    void Dequeue();

    void displayAll() const;

    QueueArr(const QueueArr<T>& other);
    QueueArr<T>& operator=(const QueueArr<T>& other);
};


// Constructor
template <typename T>
QueueArr<T>::QueueArr(size_t capacity)
{
    q_capacity = capacity;
    q_array = new T[q_capacity];
    q_size = 0;
    q_front = 0;
    q_back = -1;
}


// Default Constructor
template <typename T>
QueueArr<T>::QueueArr()
{
    q_capacity = 10;
    q_array = new T[q_capacity];
    q_size = 0;
    q_front = 0;
    q_back = -1;
}


// Destructor
template <typename T>
QueueArr<T>::~QueueArr()
{
    delete[] q_array;
}


// Empty
template <typename T>
bool QueueArr<T>::Empty() const
{
    return q_size == 0;
}


// Full
template <typename T>
bool QueueArr<T>::Full() const
{
    return q_size == q_capacity;
}


// Size
template <typename T>
size_t QueueArr<T>::Size() const
{
    return q_size;
}


// Front
template <typename T>
T QueueArr<T>::front() const
{
    if (Empty())
    {
        std::cout << " Queue is empty" << std::endl;
        return T();
    }
    return q_array[q_front];
}


// Back
template <typename T>
T QueueArr<T>::back() const
{
    if (Empty())
    {
        std::cout << " Queue is empty" << std::endl;
        return T();
    }
    return q_array[q_back];
}


// Enqueue
template <typename T>
void QueueArr<T>::Enqueue(T newData)
{
    if (Full())
    {
        std::cout << " Queue is full" << std::endl;
        return;
    }
    q_back = (q_back + 1) % q_capacity;
    q_array[q_back] = newData;
    q_size++;
}


// Dequeue
template <typename T>
void QueueArr<T>::Dequeue()
{
    if (Empty())
    {
        std::cout << " Queue is empty" << std::endl;
        return;
    }
    q_front = (q_front + 1) % q_capacity;
    q_size--;

    if (q_size == 0)
    {
        clear();
    }
}


// Clear
template <typename T>
void QueueArr<T>::clear()
{
    q_size = 0;
    q_front = 0;
    q_back = -1;
}


// Copy Constructor
template <typename T>
QueueArr<T>::QueueArr(const QueueArr<T>& other)
{
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];

    for (size_t i = 0; i < q_capacity; i++)
    {
        q_array[i] = other.q_array[i];
    }
}


// Assignment Operator
template <typename T>
QueueArr<T>& QueueArr<T>::operator=(const QueueArr<T>& other)
{
    if (this != &other)
    {
        delete[] q_array;

        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new T[q_capacity];

        for (size_t i = 0; i < q_capacity; i++)
        {
            q_array[i] = other.q_array[i];
        }
    }
    return
     *this;
}


//Display all
template <typename T>
void QueueArr<T>::displayAll() const
{
    if (Empty())
    {
        std::cout << " The queue is empty!" << std::endl;
        return;
    }
    std::cout << " The current Queue: ";

    for (size_t i = 0; i < q_size; i++)
    {
        int index = (q_front + i) % q_capacity;
        std::cout << q_array[index] << " ";
    }
    std::cout << std::endl;
}


#endif