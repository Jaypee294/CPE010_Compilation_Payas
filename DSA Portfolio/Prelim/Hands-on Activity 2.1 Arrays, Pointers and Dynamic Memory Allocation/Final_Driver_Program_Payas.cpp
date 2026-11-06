#include <iostream>
#include <string>

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName = newName;
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
    }

    ~Student() {
        std::cout << "Destructor Called." << std::endl;
    }

    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called." << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    Student& operator=(const Student &copyStudent) {
        if (this != &copyStudent) {
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }
        return *this;
    }

    void printDetails() {
        std::cout << studentName << " " << studentAge << std::endl;
    }
};

int main() {
    
    const int j = 5;

    Student studentList[j];

    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15,16,18,19,16};
    
    for (int i = 0; i < j; i++) {
    Student *ptr = new Student(namesList[i], ageList[i]);
    studentList[i] = *ptr;
    delete ptr;
    }
    
    for (int i = 0; i < j; i++) {
    studentList[i].printDetails();
    }

    
 return 0;
 
}

