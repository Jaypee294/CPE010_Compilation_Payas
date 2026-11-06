#ifndef QUEUELL_H
#define QUEUELL_H


template <typename T>
class qNode{
	public:
		T data;
		qNode<T>* next;
};

template <typename T>
qNode<T>* new_node(T newData){
	qNode<T>* newNode = new qNode<T>;
	newNode->data = newData;
	newNode->next = nullptr;
	return newNode;
}

template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    qNode<T>* newNode = new_node(newData);
 
	if((*frontPtr)==nullptr && (*backPtr)==nullptr){
	   (*frontPtr) = newNode;
	   (*backPtr) = newNode;
	}

	(*backPtr)->next = newNode;
	(*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
	qNode<T>* deleteNode = nullptr;
	deleteNode = (*frontPtr);

	if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
	   (*frontPtr) = nullptr;
	   (*backPtr) = nullptr;
	   delete deleteNode;
	   return;
	}

	(*frontPtr) = (*frontPtr)->next;
	deleteNode->next = nullptr;
	delete deleteNode;

}

//check the front
template <typename T>
void getfront(qNode<T>* frontPtr){
    if(frontPtr == nullptr){
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << "Front: " << frontPtr->data << std::endl;
}

//check in the back
template <typename T>
void getback(qNode<T>* backPtr){
    if(backPtr == nullptr){
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << "Back: " << backPtr->data << std::endl;
}

//Display all
template <typename T>
void displayAll(qNode<T>* frontPtr){
    if(frontPtr == nullptr){
        std::cout<<"The queue is empty!"<<std::endl;
        return;
     }
     std::cout<<"The current Queue: ";
     while(frontPtr != nullptr){
        std::cout<<frontPtr->data<<" ";
        frontPtr = frontPtr->next;
     }
     std::cout<<"\n";

}
#endif