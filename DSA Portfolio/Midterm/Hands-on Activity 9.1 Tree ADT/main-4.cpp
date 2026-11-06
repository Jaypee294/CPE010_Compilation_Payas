#include <iostream>
#include "tree.h"

int main(){

    Tree<char>* A = new Tree<char>('A');
    Tree<char>* B = new Tree<char>('B');
    Tree<char>* C = new Tree<char>('C');
    Tree<char>* D = new Tree<char>('D');
    Tree<char>* E = new Tree<char>('E');
    Tree<char>* F = new Tree<char>('F');
    Tree<char>* G = new Tree<char>('G');

    Tree<char>* H = new Tree<char>('H');
    Tree<char>* I = new Tree<char>('I');
    Tree<char>* J = new Tree<char>('J');
    Tree<char>* K = new Tree<char>('K');
    Tree<char>* L = new Tree<char>('L');
    Tree<char>* M = new Tree<char>('M');
    Tree<char>* N = new Tree<char>('N');

    Tree<char>* P = new Tree<char>('P');
    Tree<char>* Q = new Tree<char>('Q');

    Tree<char>* O = new Tree<char>('O');

    A->insertChild(B);
    A->insertChild(C);
    A->insertChild(D);
    A->insertChild(E);
    A->insertChild(F);
    A->insertChild(G);

    D->insertChild(H);

    E->insertChild(I);
    E->insertChild(J);

    J->insertChild(P);
    J->insertChild(Q);

    F->insertChild(K);
    F->insertChild(L);
    F->insertChild(M);

    G->insertChild(N);
    G->insertChild(O);

    std::cout << "Find J using Pre-order: ";
    A->findData(1, 'J');
    std::cout << std::endl;

    std::cout << "Find J using In-order: ";
    A->findData(2, 'J');
    std::cout << std::endl;

    std::cout << "Find J using Post-order: ";
    A->findData(3, 'J');
    std::cout << std::endl;

    std::cout << "Find O using Pre-order: ";
    A->findData(1, 'O');
    std::cout << std::endl;

    std::cout << "Find O using In-order: ";
    A->findData(2, 'O');
    std::cout << std::endl;

    std::cout << "Find O using Post-order: ";
    A->findData(3, 'O');
    std::cout << std::endl;

    return 0;
}