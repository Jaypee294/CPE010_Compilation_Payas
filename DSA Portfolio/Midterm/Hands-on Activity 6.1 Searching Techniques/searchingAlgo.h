#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>
#include "node.h"

// Linear Search for Array
template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[])
{
    int i = 0;

    while (i < arrSize)
    {
        if (dataFind == list[i])
        {
            std::cout << "Searching is successful!" << std::endl;
            return;
        }

        i++;
    }

    std::cout << "Searching is Unsuccessful" << std::endl;
}

// Linear Search for Linked List
template <typename T>
void linearSearchLL(T dataFind, Node<T>* head)
{
    while (head != nullptr)
    {
        if (head->data == dataFind)
        {
            std::cout << "Searching Successful!" << std::endl;
            return;
        }

        head = head->next;
    }

    std::cout << "Search Unsuccessfull!" << std::endl;
}

// Binary Search for Array
template <typename T>
void binarySearchAR(int arrSize, T dataFind, T list[])
{
    int low = 0;
    int up = arrSize - 1;
    int middle;

    while (low <= up)
    {
        middle = (low + up) / 2;

        if (dataFind == list[middle])
        {
            std::cout << "The search element is found!" << std::endl;
            return;
        }
        else if (dataFind < list[middle])
        {
            up = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }

    std::cout << "Search element not found" << std::endl;
}

// Get Middle Node
template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last)
{
    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != last && fast->next != last)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Binary Search for Linked List
template <typename T>
void binarySearchLL(Node<T>* start, T dataFind)
{
    Node<T>* last = nullptr;

    while (start != last)
    {
        Node<T>* middle = getMiddle(start, last);

        if (middle->data == dataFind)
        {
            std::cout << "Search Successful!" << std::endl;
            return;
        }
        else if (middle->data > dataFind)
        {
            last = middle;
        }
        else
        {
            start = middle->next;
        }
    }

    std::cout << "Search Unsuccessfull!" << std::endl;
}

#endif
