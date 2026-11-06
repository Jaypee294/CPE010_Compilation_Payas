#include <iostream>
#include <string>

const int MAX = 100;

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

bool isEmpty() {
    return top == -1;
}

bool match(char open, char close) {
    return (open == '(' && close == ')') ||(open == '{' && close == '}') ||(open == '[' && close == ']');
}

int main() {

    std::string expr;

    std::cout << "Enter expression: ";
    std::getline(std::cin, expr);

    bool valid = true;

    for (char ch : expr) {

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {

            if (isEmpty()) {
                valid = false;
                break;
            }

            char open = pop();

            if (!match(open, ch)) {
                valid = false;
                break;
            }
        }
    }

    if (!isEmpty())
        valid = false;

    if (valid)
        std::cout << "Expression is Balanced." << std::endl;
    else
        std::cout << "Expression is NOT Balanced." << std::endl;

    return 0;
}