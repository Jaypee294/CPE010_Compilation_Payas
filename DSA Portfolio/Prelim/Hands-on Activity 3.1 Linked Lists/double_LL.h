#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};

template <typename T>
DoubleList<T>* createNode(T newData){

    DoubleList<T>* newNode = new DoubleList<T>;

    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T> *currentNode){
    if(currentNode == nullptr){
        std::cout<<"The list is empty"<< std::endl;
    }

    DoubleList<T> *tail;

    std::cout<<"Forward: "<<std::endl;
    while(currentNode != nullptr){
        std::cout<<currentNode->data<<" ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    std::cout<<std::endl;

    std::cout<<"Backward: "<<std::endl;
    while( tail != nullptr){
        std::cout<<tail->data<<" ";
        tail = tail->prev;
    }
    std::cout<<std::endl;
}

template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    DoubleList<T>* newNode = createNode(newData);
    newNode->next = *currentHead;

    (*currentHead)->prev = newNode;

    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T> *currentHead){
    DoubleList<T>* newNode = createNode(newData);
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    currentHead->next = newNode;

    newNode->prev = currentHead;
}

template<typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode){
    
    if(prevNode == nullptr){
        std::cout << "Previous node cannot be null" << std::endl;
        return;
    }
    
    DoubleList<T>* newNode = createNode(newData);
    
    newNode->data = newData;
    
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(newNode->next != nullptr){
        newNode->next->prev = newNode;
    }


    
    prevNode->next = newNode;
}


template<typename T>
void dllDeleteNode(T findData, DoubleList<T>** currentHead){
    if (currentHead == nullptr || *currentHead == nullptr) return;
    DoubleList<T>* currNode = *currentHead;
    DoubleList<T>* prevNode = nullptr;
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    if(currNode == nullptr){
        return;
    }

    if(prevNode == nullptr){
        *currentHead = currNode->next;
    }
    else{
        prevNode->next = currNode->next;
    }

    if(currNode->next != nullptr){
        currNode->next->prev = prevNode;
    }

    delete currNode;
}

template <typename T>
void dllDeleteList(DoubleList<T>** head){
    DoubleList<T>* current = *head;

    while(current != nullptr){
        DoubleList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

#endif