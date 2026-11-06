#include <iostream>
#include "simply_LL.h"
#include "double_LL.h"


int main() {

    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    dllTraverse(head);

    std::cout<<"Insert Head: "<< std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    std::cout<<"Insert End: "<< std::endl;
    dllInsertEnd('1', head);
    dllTraverse(head);

    std::cout<<"General Insert: "<< std::endl;
    dllGeneralInsert('B', third);
    dllTraverse(head);

    std::cout<<"Delete Node: "<< std::endl;
    dllDeleteNode('B', &head);
    dllTraverse(head);

    std::cout<<"Delete List" << std::endl;
    dllDeleteList(&head);
    dllTraverse(head);

}