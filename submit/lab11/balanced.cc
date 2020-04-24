#include <iostream>
#include <string>
#include <cstring>
struct DelimMap {
	std::string delim;
  	int encoding;
};

DelimMap delimEncodings[] = {
  { "(", 1 },
  { ")", -1 },
  { "[", 2 },
  { "]", -2 },
  { "{", 3 },
  { "}", -3},
  { "<", 4},
  { ">", -4}
};
class Stack{

	public:
		int push(int);
		int pop();
		int size();
		int stk[16];
		void displayItems();
	private:
		int top = -1;
};

int Stack::size(){
	int i;
	int counter = 0;
	for(i = (top); i>=0; i--) counter++;
	return counter;
}

int Stack::pop(){
	int temp;
	temp = stk[top];
	--top;
	return temp;
}
int Stack::push(int value){
	++top;
	stk[top] = value;
	return value;
}

void Stack::displayItems(){
    int i;
    std::cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        std::cout<<stk[i]<<" ";
    std::cout<<std::endl;
}

int main(int argc, char* argv[]){	
	for(int i = 1; i<argc; i++){
		int counter = 0;
		for(int j = 0; j<8; j++){
			if(argv[i] != delimEncodings[j].delim){
				counter++;
			}
		}
		if(counter != 7){
			std::cout<<"invalid delimeter "<<argv[i]<<std::endl;
			exit(0);
		}
	}
	
	Stack my_stack;
	for(int i = 1; i<argc; i++){
		if (strlen(argv[i])>1){
			std::cout<<"invalid character"<<std::endl;
			exit(0);
		}
		for(int j = 0; j<8; j++){
			if (argv[i] == delimEncodings[j].delim 	){
				if(delimEncodings[j].encoding >0){
				my_stack.push(delimEncodings[j].encoding);
				}
				else{
					if(my_stack.size() == 0) exit(1);
					else{
						//my_stack.displayItems();
						int temp = my_stack.pop();
						if(temp*-1 != delimEncodings[j].encoding){
						std::cout<<"unbalanced at argument "<<i<<std::endl;      
						exit(1);
						}
					}
				}
			}
		}
	}
	if(argc %2 == 0){
		std::cout<<"unbalanced at argument "<< argc-1<<std::endl;
		exit(1);
	}
	exit(0);	
	/*
	std::cout<<"succeed"<<std::endl;

	my_stack.displayItems();
	std::cout<<my_stack.size()<<std::endl;
*/
}
