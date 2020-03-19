#ifndef D_LINK_SEQ_HH_
#define D_LINK_SEQ_HH_

#include "seq.hh"
#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>
#include <iostream>

template <typename E> class DLinkSeq;
template <typename E> class DLinkSeqConstIter;

template <typename E>
class DLink {
private:
  E element;   //value for this node
  DLink *next; //pointer to next node in list
  DLink *prev;
  friend class DLinkSeqConstIter<E>;
  friend class DLinkSeq<E>;
public:
  //constructors
  DLink(const E& elemval, DLink *prevp, DLink* nextp) :
    element(elemval), next(nextp), prev(prevp)
  { }
  DLink(DLink *prevp = nullptr, DLink* nextp = nullptr) :
    next(nextp), prev(prevp)
  { }
};


template <typename E> class DLinkSeq : public Seq<E>{
private:
	DLink<E>* head;
	DLink<E>* tail;
	int cnt;


	friend class DLinkSeqConstIter<E>;

	enum class Private {TAG, DEFAULT_SIZE = 8};

public:	
	
	DLinkSeq(Private TAG) : head(NULL), tail(NULL), cnt(0){}

	static SeqPtr<E> make(){
		return std::make_unique<DLinkSeq<E>>(Private::TAG);
	}
	
	void clear(){
		if(cnt == 0){
			std::cout<<"seq-test: dlinkseq ... Assertion ... \"clear() on empty dlist\"' failed. Aborted (core dumped)"<<std::endl;
			exit(1);
		}
		E ret_elem = tail->element;

		for(cnt; cnt>1; cnt--){
			DLink<E>* tail_temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			tail_temp->prev = NULL;
			tail_temp->next = NULL;
			delete (tail_temp);
		}
		cnt = 1;
		if(cnt == 1){
			head = NULL;
			delete head;
			delete tail;
		}
				cnt = 0;
	}

	void push(const E& item){
		DLink<E>* temp = new DLink<E>();
		temp->element = item;
		if(cnt == 0){
			head = temp;
			tail = head;
			cnt++;
			//delete temp; //leak
			return; 	
		}	
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		cnt++;
		//delete temp;//leak
	}
	
	E shift(){
		if(cnt == 0){
			std::cout<<"seq-test: dlinkseq ... Assertion ... \"shift() on empty dlist\"' failed. Aborted (core dumped)"<<std::endl;
			exit(1);
		}
		E head_el = head->element;
		if(cnt == 0){
			std::cout<<"no such element"<<std::endl;
			exit(1);
		}
		if(cnt>1){
			DLink<E>* head_temp = head;
			head = head->next;
			head->prev = NULL;
			head_temp->next = NULL;
			head_temp->prev = NULL;
			delete head_temp;
		}
		if(cnt == 1){
			head = NULL;
			delete head;
		}
		cnt--;
		return head_el;
	}
	
	void unshift(const E& item){
		DLink<E>* temp = new DLink<E>();
		temp->element = item;
		if(cnt == 0){
			head = temp;
			tail = head;
			++cnt;
			//delete temp;//leak
			return;
		}
		head->prev = temp;
		temp->next = head;
		head = temp;
		++cnt;
		//delete temp;//leak
		
	}
	
	E pop(){
		E ret_elem = tail->element;
		if(cnt>1){
			DLink<E>* tail_temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			tail_temp->prev = NULL;
			tail_temp-> next = NULL;
			delete (tail_temp);
		}
		if(cnt == 1){
			head = NULL;
			delete head;
			delete tail;
		}
		if(cnt == 0){
			std::cout<<"seq-test: dlinkseq.hh:75: E DLinkSeq<E>::pop() [with E = int]: Assertion 'index > 0 && \"pop on empty array seq\" failed. Aborted"<<std::endl;
			exit(1);
		}
		cnt--;
		return ret_elem;
	}
	
	int size() const{
		return cnt;
	}

	ConstIterPtr<E> cbegin() const{
		 const DLinkSeq* constThis = static_cast<const DLinkSeq*>(this);
   		 return std::make_unique<DLinkSeqConstIter<E>>(constThis);	
	}
	ConstIterPtr<E> cend() const{
		const DLinkSeq* constThis = static_cast<const DLinkSeq*>(this);
   		return std::make_unique<DLinkSeqConstIter<E>>(constThis, false);
	}

};

template <typename E> class DLinkSeqConstIter : public ConstIter<E> {
	public:
		DLinkSeqConstIter(const DLinkSeq<E>* const seq, bool isHead=true)
    		: seq(seq),
      		position(isHead ? seq->head : seq->tail)
 		{ }

	DLinkSeqConstIter& operator++(){
		position = position->next;
		return *this;
	}
	DLinkSeqConstIter& operator--(){
		position = position->prev;
		return *this;
	}
	virtual operator bool(){
		return (position !=NULL);
	}
	const E& operator*(){
		return position->element;
	}
	const E* operator->(){
		return &position->element;
	}
	private:
	const DLinkSeq<E>* const seq;
	DLink<E>* position;


};

#endif
