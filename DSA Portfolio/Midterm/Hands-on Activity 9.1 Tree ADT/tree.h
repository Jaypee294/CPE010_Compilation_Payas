#ifndef TREE_H
#define TREE_H

#include <iostream>

template<typename T>
class Tree{
    private:
    T key;
    Tree<T>* child;
    Tree<T>* sibling;

    public:
    Tree(T value);
    void insertChild(Tree<T>* node);
    void preOrder();
    void postOrder();
    void inOrder();
    void findData(int choice, T value);
};

template<typename T>
Tree<T>::Tree(T value){
    key = value;
    child = nullptr;
    sibling = nullptr;
}

template<typename T>
void Tree<T>::insertChild(Tree<T>* node){

    if(child == nullptr){
        child = node;
    }
    else{
        Tree<T>* temp = child;

        while(temp->sibling != nullptr){
            temp = temp->sibling;
        }

        temp->sibling = node;
    }
}

template<typename T>
void Tree<T>::preOrder(){

    std::cout << key << " ";

    if(child != nullptr){
        child->preOrder();
    }

    if(sibling != nullptr){
        sibling->preOrder();
    }
}

template<typename T>
void Tree<T>::postOrder(){

    if(child != nullptr){
        child->postOrder();
    }

    std::cout << key << " ";

    if(sibling != nullptr){
        sibling->postOrder();
    }
}

template<typename T>
void Tree<T>::inOrder(){

    if(child != nullptr){
        child->inOrder();
    }

    std::cout << key << " ";

    if(sibling != nullptr){
        sibling->inOrder();
    }
}

template<typename T>
void Tree<T>::findData(int choice, T value){

    if(choice == 1){

        if(key == value){
            std::cout << value << " was found!";
        }

        if(child != nullptr){
            child->findData(choice, value);
        }

        if(sibling != nullptr){
            sibling->findData(choice, value);
        }
    }

    else if(choice == 2){

        if(child != nullptr){
            child->findData(choice, value);
        }

        if(key == value){
            std::cout << value << " was found!";
        }

        if(sibling != nullptr){
            sibling->findData(choice, value);
        }
    }

    else if(choice == 3){

        if(child != nullptr){
            child->findData(choice, value);
        }

        if(sibling != nullptr){
            sibling->findData(choice, value);
        }

        if(key == value){
            std::cout << value << " was found!";
        }
    }
}

#endif