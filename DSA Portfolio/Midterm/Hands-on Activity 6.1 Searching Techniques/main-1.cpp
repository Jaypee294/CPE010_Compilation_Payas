#include <iostream>
#include <cstdlib>
#include <ctime>

#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main()
{
    // Generate random data
    int dataset[max_size];

    srand(time(0));

    for (int i = 0; i < max_size; i++)
    {
        dataset[i] = rand();
    }

    // Display generated data
    for (int i = 0; i < max_size; i++)
    {
        std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;

    // Linear Search for Array
    int userInput;

    std::cout << "What number to search?";
    std::cin >> userInput;

    linearSearchArr(max_size, userInput, dataset);


    // Create Linked List for Linear Search
    Node<char>* name1 = new_node('J');
    Node<char>* name2 = new_node('A');
    Node<char>* name3 = new_node('Y');
    Node<char>* name4 = new_node('P');
    Node<char>* name5 = new_node('E');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;

    // Linear Search Linked List
    linearSearchLL('Y', name1);
    linearSearchLL('r', name1);


    // Create Linked List for Binary Search
    Node<int>* num1 = new_node(1);
    Node<int>* num2 = new_node(2);
    Node<int>* num3 = new_node(3);
    Node<int>* num4 = new_node(4);
    Node<int>* num5 = new_node(5);

    num1->next = num2;
    num2->next = num3;
    num3->next = num4;
    num4->next = num5;

    // Binary Search Linked List
    binarySearchLL(num1, 4);
    binarySearchLL(num1, 0);


    // Binary Search Array
    int test[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    binarySearchAR(8, 12, test);
    binarySearchAR(8, 1, test);

    return 0;
}
