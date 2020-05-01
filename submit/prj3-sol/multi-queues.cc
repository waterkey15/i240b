#include <memory>
#include <string>
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>    
#include <cstdlib>

#include "command.hh"
#include "command-stream.hh"
#include "heap.hh"
#include "multi_class.hh"
/** Test program for command stream */

using namespace std;
int main (int argc, char* argv[]) {

	if (argc != 2) {
    std::cerr << "usage: " << argv[0] << " FILE_PATH" << std::endl;
    std::exit(1);
  }

  CommandStream commandIn(argv[1]); //create command stream
	multi_class my_multi_class;
  	
		 for (std::unique_ptr<Command> commandP = commandIn.next();
       commandP != nullptr;
       commandP = commandIn.next()) {
    //std::cout << *commandP << std::endl;

  	if(commandP->cmd == Command::Cmd::ENTER){
		EnterCommand* enterP = dynamic_cast<EnterCommand*>(commandP.get());
		const Job my_job(enterP->job);
		//std::cout<<".......................... "<<my_job.id<<std::endl;//reaches the ekements of command enter;
		my_multi_class.enter(my_job.id, my_job.priority0, my_job.priority1);
	}
	else if(commandP->cmd == Command::Cmd::MOVE){
		my_multi_class.move();
	}
	else if(commandP->cmd == Command::Cmd::LEAVE){
		my_multi_class.leave();
	}
	//my_multi_class.q0->display();	
//	my_multi_class.q1->display();	
}
	my_multi_class.unleak_memory();
  return 0;
}
