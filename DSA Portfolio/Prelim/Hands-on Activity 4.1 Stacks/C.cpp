#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool match(char open, char close){

    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');

}

int main(){

    stack<char> s;

    string expr;

    cout<<"Enter expression: ";
    getline(cin,expr);

    bool valid=true;

    for(char ch:expr){

        if(ch=='('||ch=='{'||ch=='[')
            s.push(ch);

        else if(ch==')'||ch=='}'||ch==']'){

            if(s.empty()){
                valid=false;
                break;
            }

            char open=s.top();
            s.pop();

            if(!match(open,ch)){
                valid=false;
                break;
            }
        }
    }

    if(!s.empty())
        valid=false;

    if(valid)
        cout<<"Expression is Balanced."<<endl;
    else
        cout<<"Expression is NOT Balanced."<<endl;

    return 0;
}