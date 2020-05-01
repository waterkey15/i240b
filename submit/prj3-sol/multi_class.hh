#ifndef MULTI_CLASS_HH_
#define MULTI_CLASS_HH_

#include <memory>
#include <string>
#include <iostream>

#include "heap.hh"
#include "job.hh"
#include "command.hh"

class multi_class{
	public:
		Priority_Queue* q0 = new Priority_Queue;
		Priority_Queue* q1 = new Priority_Queue;

		int c, b;
		
		void  enter(std::string id, int priority0, int priority1){
			q0->insertq0(id, priority0, priority1);//compare priorities inside of the insertq0 function
			std::cout<<"enter "<<id<<" "<<priority0<<" "<<priority1<<std::endl;
			
			}
		void move(){
			if(q0->front != NULL){
			q1->insertq1(q0->front->info, q0->front->priority1, q0->front->priority0);//prints the command id and priorities inside of insertq1 funtion
			q0->del();
			}
			else c =1;
		}
		void leave(){
			if(q1->front != NULL){
			std::cout<<"leave "<< q1->front->info<<" "<<q1->front->priority0<<" "<<q1->front->priority1<<std::endl;
			q1->del();
			}
			else b = 1;
		}
		void unleak_memory(){// to avoid the memory leaking
			delete q0;
			delete q1;
		}
};



#endif
