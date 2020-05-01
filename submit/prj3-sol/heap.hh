//source code is from internet  https://www.sanfoundry.com/cpp-program-implements-priority-queue/

#ifndef HEAP_HH_
#define HEAP_HH_

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
 
/*
 * Node Declaration
 */
struct node
{
	int priority0;
	int priority1;
	std::string info;
	struct node *link;
};
/*
 * Class Priority Queue
 */
class Priority_Queue
{
    private:
        node *front;
	friend class multi_class;
    public:
        Priority_Queue()
        {
            front = NULL;
        }
        /*
         * Insert into Priority Queue
         */
        void insertq0(std::string item, int priority, int priority1)
        {
            node *tmp, *q;
            tmp = new node;
            tmp->info = item;
            tmp->priority0 = priority;
	    tmp->priority1 = priority1;
            if (front == NULL || priority > front->priority0)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {

                q = front;
	//	std::cout<<"----------------------------------"<<q->info<<std::endl;
                while (q->link != NULL/* && q->link->priority0 <= priority*/){
                    q=q->link;}
	//	std::cout<<".....sfter while........."<<q->info<<std::endl;
                tmp->link = q->link;
                q->link = tmp;
           }
        }

	void insertq1(std::string item, int priority, int priority0)
        {
		std::cout<<"move "<<item<<" "<<priority0<<" "<<priority<<" "<<std::endl;
            node *tmp, *q;
            tmp = new node;
            tmp->info = item;
            tmp->priority1 = priority;
            tmp->priority0 = priority0;
	    if (front == NULL || priority < front->priority1)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                q = front;
                while (q->link != NULL && q->link->priority1 <= priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }
        /*
         * Delete from Priority Queue
         */
        void del()
        {
            node *tmp;
            if(front == NULL)
                //cout<<"Queue Underflow\n";
		int t = 1;
            else
            {
                tmp = front;
                //cout<<"Deleted item is: "<<tmp->info<<endl;
                front = front->link;
                free(tmp);
            }
        }
        /*
         * Print Priority Queue
         */
        void display()
        {
            node *ptr;
            ptr = front;
            if (front == NULL)
                cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";
                cout<<"Priority       Item\n";
                while(ptr != NULL)
                {
                    cout<<ptr->priority1<<"                 "<<ptr->info<<endl;
                    ptr = ptr->link;
                }
            }
        }
};

#endif
