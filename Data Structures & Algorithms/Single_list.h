#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

/*****************************************
* UW User ID:  y52wei
* Submitted for ECE 250
* Department of Electrical and Computer Engineering
* University of Waterloo
* Calender Term of Submission:  Fall 2013
*
* By submitting this file,  I affirm that
* I am the author of all modifications to
* the provided code.
*****************************************/

#include "ece250.h"
#include "Single_node.h"
#include "Exception.h"
#include <iostream>

#define NULLVARIATE_CONSTRUCTOR

template <typename Type>
class Single_list {
private:
	Single_node<Type> *list_head;
	Single_node<Type> *list_tail;
	int node_count;

public:
	Single_list();
	Single_list( Single_list const & );
	~Single_list();

	// Accessors

	int size() const;
	bool empty() const;

	Type front() const;
	Type back() const;

	Single_node<Type> *head() const;
	Single_node<Type> *tail() const;

	int count( Type const & ) const;

	// Mutators

	void swap( Single_list & );
	Single_list &operator = ( Single_list const & );

	void push_front( Type const & );
	void push_back( Type const & );

	Type pop_front();

	int erase( Type const & );

	// Friends

	template <typename T>
	friend std::ostream &operator << ( std::ostream &, Single_list<T> const & );
};

template <typename Type>
Single_list<Type>::Single_list():
	list_head( 0 ),           //list_head is pointing address 0.   address 0 reserved for nullpointers.
	list_tail( 0 ),
	node_count( 0 ) {
		// empty constructor
}

template <typename Type>
Single_list<Type>::Single_list( Single_list<Type> const &list ):        //copy constructor
	list_head( 0 ),
	list_tail( 0 ),
	node_count( 0 ) {
		// enter your implementation here
		
		if (list.empty())        //return if list empty
			return;
		
		push_front(list.front());       //copy the first node

		for (Single_node<Type>*original= list.head()->next(),*copy= head();        //iterate through the list
				original!= nullptr;
				original = original->next(), copy= copy->next())
			{
				copy->next_node = new Single_node<Type>(original->retrieve(),0);    //copy each node of list to new list
				node_count++;             //increment node count
			}
}

template <typename Type>   
Single_list<Type>::~Single_list() {
	// enter your implementation here
	while(!empty())
	{
	pop_front();        //recursively pop the front
	} 
}

template <typename Type>
int Single_list<Type>::size() const {                    
	// enter your implementation here
	return node_count;            //return number of items in the list
}

template <typename Type>
bool Single_list<Type>::empty() const {          
	// enter your implementation here
	return list_head == 0;      //check if list head and list head points to nothing, therefore empty
}

template <typename Type>
Type Single_list<Type>::front() const {            
	// enter your implementation here
	if (empty())
		throw underflow();         //return if list is empty
	else
		return list_head->retrieve();           //retrieve the object in the first node
}

template <typename Type>
Type Single_list<Type>::back() const {                
	// enter your implementation here
	if (empty())
		throw underflow();         //return if list is empty
	else
		return list_tail->retrieve();       //retrieve the object in the last node
}

template <typename Type>
Single_node<Type> *Single_list<Type>::head() const {            
	// enter your implementation here
	return list_head;             //return the head pointer
}

template <typename Type>
Single_node<Type> *Single_list<Type>::tail() const {             
	// enter your implementation here
	return list_tail;         //return the tail pointer 
}

template <typename Type>
int Single_list<Type>::count( Type const &obj ) const {             
	// enter your implementation here
	int counter = 0;

	for (Single_node<Type>*ptr=list_head; ptr!=0; ptr=ptr->next())
	{
		if(ptr->retrieve() == obj)           //count the number of nodes in list storing a value equal to the argument
			counter++;
	}
	return counter;
}

template <typename Type>
void Single_list<Type>::swap( Single_list<Type> &list ) {
	std::swap( list_head, list.list_head );
	std::swap( list_tail, list.list_tail );
	std::swap( node_count, list.node_count );
}

template <typename Type>
Single_list<Type> &Single_list<Type>::operator = ( Single_list<Type> const &rhs ) {
	Single_list<Type> copy( rhs );

	swap( copy );

	return *this;
} 

template <typename Type>
void Single_list<Type>::push_front( Type const &obj ) {
	// enter your implementation here

	if(empty())
	{
		list_head = new Single_node<Type>(obj,nullptr);     
		list_tail = head();           //when list is empty, create a new node and assign it to the head pointer
		node_count++;       
	}
	else
	{
		list_head = new Single_node<Type>(obj,list_head);
		node_count++;          //list is not empty, add a new node to the front of the list.
	}

}

template <typename Type>
void Single_list<Type>::push_back( Type const &obj ) {
	// enter your implementation here

	if(empty())
	{
		list_head = new Single_node<Type>(obj,nullptr);
		list_tail = head();
		node_count++;     //when list is empty, create a new node and assign it to the tail pointer
	}		 
	else
	{
		list_tail->next_node = new Single_node<Type>(obj,nullptr);
		list_tail = list_tail->next();  
		node_count++;       //list is not empty, add a new node to the back of the list.
		
	}
}

template <typename Type>
Type Single_list<Type>::pop_front() {            
	// enter your implementation here
	if (empty())
		throw underflow();
	else
	{
		Type oldhead = front();      //store a copy of the current list_head value
		Single_node<Type> *ptr = head();    //create a copy of head pointer
		list_head = head()->next();      //update the head pointer 	 
		delete ptr;                  //delete the old head node
		node_count--;              //decrease node count
		return oldhead;            //return old head node value
	}
}

template <typename Type>
int Single_list<Type>::erase( Type const &obj ) {
	// enter your implementation here
	
	int counter = 0;
	if (empty())
		return 0;
	else
	{
		for (Single_node<Type>*ptr=list_head; ptr!=0; ptr=ptr->next())
		{
			// think about implementing 2 pointers.
			if (ptr->next()->retrieve()== obj)                 
			{	
				Single_node<Type> *del = ptr->next();
				ptr->next_node = del->next();
				delete del;
				counter++;
				node_count--;             
			}
		}
	}
	
	/*Single_node<Type>*prev = head();
	Single_node<Type>*curr= head()->next();

	while(prev->retrieve()==obj)
	{
		pop_front();
		prev=prev->next();
		curr=curr->next();
	}

	while(curr!=0)             // FIX FIX!!!!
	{
		Single_node<type>
		if (ptr->retrieve()==obj)
		{


		}
		ptr=ptr->next();
		nxtptr=nxtptr->next();

	}
	*/
	return 0;

}

// You can modify this function however you want:  it will not be tested

template <typename T>
std::ostream &operator << ( std::ostream &out, Single_list<T> const &list ) {
	for ( Single_node<T> *ptr = list.head(); ptr != 0; ptr = ptr->next() ) {
		out << "->" << ptr->retrieve();
	}

	out << "->0";

	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif
