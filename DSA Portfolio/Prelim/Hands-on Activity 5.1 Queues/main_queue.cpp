#include <iostream>
#include "QueueArr.h"

int main()
{
    // Create an object
    QueueArr<char> q1(6);

    // ENQUEUE

    q1.Enqueue('1');
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.Enqueue('2');
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.Enqueue('3');
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.Enqueue('4');
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.Enqueue('5');
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.Enqueue('6');
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;


    // Display queue
    q1.displayAll();

    // DEQUEUE

    q1.Dequeue();
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.displayAll();
    q1.Dequeue();
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.displayAll();
    q1.Dequeue();
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.displayAll();
    q1.Dequeue();
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.displayAll();
    q1.clear();
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.displayAll();
    q1.clear();
    std::cout << " q_front: " << q1.front() << " q_back: " << q1.back() << " q_size: " << q1.Size() << std::endl;
    q1.displayAll();
    q1.Dequeue();

    std::cout << " q_size: " << q1.Size() << std::endl;

    q1.displayAll();


    return 0;
}