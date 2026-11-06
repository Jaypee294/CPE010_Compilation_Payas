#include <iostream>
#include "simply_LL.h"

int main(){

    SimplyList<char>* head = new SimplyList<char>;
    SimplyList<char>* second = new SimplyList<char>;
    SimplyList<char>* third = new SimplyList<char>;
    SimplyList<char>* fourth = new SimplyList<char>;
    SimplyList<char>* fifth = nullptr;

    head->data = 'J';
    head->next = second;
    second->data = 'A';
    second->next = third;
    third->data = 'P';
    third->next = fourth;
    fourth->data = 'E'; 
    fourth->next = fifth;


    listTraversal(head);

    std::cout<<"\ninserting a new node at the head: \n";
    sllinsertHead('Q', &head);
    listTraversal(head);

    std::cout<<"\ninserting a new node at the third:"<< std::endl;
    sllGeneralInsert('X', head->next->next);
    listTraversal(head);

    std::cout<<"\nInserting a new node at the end:"<< std::endl;
    sllinsertEnd('Y', &head);
    listTraversal(head);
    
    std::cout<<"\nDeleting a node:"<< std::endl;
    sllDeleteNode('X', &head);
    listTraversal(head);

    std::cout<<"\nDeleting a node:"<< std::endl;
    sllDeleteNode('Q', &head);
    listTraversal(head);

    std::cout<<"\nDeleting all the nodes:"<< std::endl;
    sllDeleteList(&head);
    listTraversal(head);
    return 0;
}   