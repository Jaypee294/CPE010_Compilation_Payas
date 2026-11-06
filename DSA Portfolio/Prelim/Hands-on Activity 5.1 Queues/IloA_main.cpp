#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main() {

    std::queue<char> myQ;

    myQ.push('J');
    myQ.push('A');
    myQ.push('P');
    myQ.push('E');
    display(myQ);
    
    //empty
    std::cout << "Empty: " << myQ.empty() << std::endl;
    
    //size
    std::cout << "Size:  " << myQ.size() << std::endl;

    // front
    std::cout << "Front: " << myQ.front() << std::endl;

    // back
    std::cout << "Back:  " << myQ.back() << std::endl;

    // pop
    std::cout << "\nPopping front element " << std::endl;
    myQ.pop();
    

    // display after pop
    std::cout << "After pop: ";
    display(myQ);


    return 0;
}

void display(std::queue<char> copyQ) {
	
	std::queue<char> c = copyQ;
	
    while (!c.empty()) {
        std::cout << " " << c.front();
        c.pop();
    }
    std::cout<<"\n";
}




