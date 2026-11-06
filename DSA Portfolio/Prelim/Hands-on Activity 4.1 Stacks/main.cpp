#include <iostream>
#include <string>
#include "listStack.h"

int main (){
	
	std::cout<<"\n---------Pushing 'I' 'E' 'E' 'E'--------- " << std::endl;

	push('I');
	push('E');
	push('E');
	push('E');
	

	Top<char>();

	std::cout<<"Display All: "<<std::endl;
	displayAll<char>();
	
	std::cout << "\n-------- popping 'E' 'E' 'E' 'I' --------" << std::endl;
	while(!isEmpty<char>()){
		std::cout<<"popping: " <<pop<char>()<<std::endl;
	}

	std::cout<<"Display All: "<<std::endl;
	displayAll<char>();
	pop<char>();
	return 0;
}
