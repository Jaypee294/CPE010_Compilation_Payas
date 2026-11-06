#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* top = nullptr;

void push(char c) {

    Node* newNode = new Node;

    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {

    Node* temp = top;
    char value = temp->data;

    top = top->next;

    delete temp;

    return value;
}

bool isEmpty() {
    return top == nullptr;
}

bool match(char open, char close) {
    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');
}

int main() {

    string expr;

    cout << "Enter expression: ";
    getline(cin, expr);

    bool valid = true;

    for(char ch : expr) {

        if(ch=='(' || ch=='{' || ch=='[')
            push(ch);

        else if(ch==')' || ch=='}' || ch==']') {

            if(isEmpty()) {
                valid = false;
                break;
            }

            char open = pop();

            if(!match(open,ch)) {
                valid = false;
                break;
            }
        }
    }

    if(!isEmpty())
        valid = false;

    if(valid)
        cout << "Expression is Balanced." << endl;
    else
        cout << "Expression is NOT Balanced." << endl;

    return 0;
}