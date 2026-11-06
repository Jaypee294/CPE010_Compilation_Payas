#ifndef LISTSTACK_H
#define LISTSTACK_H
#include <iostream>

template <typename T>
class Node{
	public:
		T data;
		Node<T>* next = nullptr;
};

template <typename T>
Node<T>* head = nullptr;


template <typename T>
void push(T newData){
	Node<T>* newNode = new Node<T>;
	newNode->data = newData;
	newNode->next = head<T>;
	head<T> = newNode;
}

template <typename T>
bool isEmpty(){
	return head<T> == nullptr;
}

template <typename T>
T pop(){
	if(isEmpty<T>()){
		std::cout<<"Stack underflow"<<std::endl;
	}
	
	Node<T>* temp = head<T>;	
	T tempVal = temp->data;
	head<T> = head<T>-> next;
	delete temp;
	return tempVal;
}

template <typename T>
void Top(){

	if(isEmpty<T>()) return;
	std::cout<<"the top is: " << head<T>->data<<std::endl;
}

template <typename T>
void displayAll(){

	Node<T>* temp = head<T>;

	if(isEmpty<T>()){
		std::cout << "List is empty" << std::endl;
		return;
	}

	while(head<T> != nullptr){
		std::cout<< head<T> ->data;
		if(head<T> ->next != nullptr){
			std::cout<<"->";
		}
		head<T>  = head<T>->next;
	}
	head<T> = temp;
}

#endif
