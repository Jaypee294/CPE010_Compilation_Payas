#include <iostream>
#include "queueLL.h"

int main (){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('A', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    enqueue('C', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    enqueue('E', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    
    displayAll(front);

    dequeue(&front, &back);
    std::cout << front->data << " " << back->data <<std::endl;
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data <<std::endl;
    dequeue(&front, &back);

    displayAll(front);

    enqueue('A', &front, &back);
    getfront(front);
    enqueue('E', &front, &back);
    getback(back);
    std::cout<<front->data<<" "<<back-> data <<std::endl;
    
    displayAll(front);

    return 0;
}