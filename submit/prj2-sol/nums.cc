#include <iostream>
#include <fstream>
#include "arrayseq.hh"
#include "command.hh"
#include "dlinkseq.hh"
#include "seq.hh"
#include <cctype>
#include <cstdlib>
#include <memory>
#include <string>
#include <utility>
int counterr;
struct NameToSeq{
  const std::string name;
  const SeqPtr<TestType> seq;  //smart pointer to sequence
};


static const NameToSeq DLinknameSeqMap[] = {
	{"DLinkSeq", DLinkSeq<TestType>::make()}
};

static const NameToSeq nameSeqMap[] = {
  { "ArraySeq", ArraySeq<TestType>::make() }
};



static Seq<TestType>* get_raw_pointer(){
	
	if (counterr == 3){
	//	std::cout<<" array seq"<<std::endl;
	return nameSeqMap->seq.get();
	}
	else{
	//	std::cout<<"dLink seq"<<std::endl;
		return DLinknameSeqMap->seq.get();
	}
}


void read_integers_a(std::ifstream& in){
	int i;
	while(in>>i){
		get_raw_pointer()->push(i);
	}
}
/*
void read_integers(std::ifstream& in){
	int i;
	while(in>>i){
		
		InsertAtTail(i);
	}
	Real_Print();
	std::cout<<" "<<std::endl;
}
*/
void output_data(const Seq<TestType>& seq){
	
	ConstIterPtr<TestType> iterBegin = seq.cbegin();
	ConstIterPtr<TestType> iterEnd = seq.cend();

	ConstIter<TestType>&e = *iterEnd;
	for(ConstIter<TestType>&b = *iterBegin; b; ++b){
		std::cout<<*b<<std::endl;
		std::cout<<*e<<std::endl;
		--e;
	}
}

int main(int argc, char** argv){
	
	if(argc<2 || argc>3){
		std::cerr<<"usage: ./nums [-a] INTS_FILE_PATH"<<std::endl;
		std::exit(1);	
	}
	if (argc == 3){
		if(std::string(argv[1]) != "-a"){ 
			std::cerr<<"usage: ./nums [-a] INTS_FILE_PATH"<<std::endl; 
			std::exit(1);
		}
		std::ifstream infile(argv[2]);
		if(!(infile.good())){
			std::cerr<<"cannot read "<< argv[1]<<": No such file or directory"<<std::endl;
			std::exit(1);
		}
		counterr = 3;
		std::string file_name = argv[2];

		std::ifstream in;
	
		in.open(file_name);

		read_integers_a(in);
	
		output_data(*get_raw_pointer());	
		}
	if (argc == 2){
		std::ifstream infile(argv[1]);
		if(!(infile.good())){
			std::cerr<<"cannot read "<< argv[1]<<": No such file or directory"<<std::endl;
			std::exit(1);
		}
		counterr = 2;
		std::string file_name = argv[1];
		
		
		std::ifstream in;
		in.open(file_name);
			
		read_integers_a(in);

		output_data(*get_raw_pointer());

		}	


		
}
