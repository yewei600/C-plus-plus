#ifndef DYNAMIC_QUEUE_AS_ARRAY_H
#define DYNAMIC_QUEUE_AS_ARRAY_H

/*****************************************
* UW User ID:  y52wei
* Submitted for ECE 250
* Semester of Submission:  Fall 2013
*
* By submitting this file, I affirm that
* I am the author of all modifications to
* the provided  code.
*****************************************/

#include "ece250.h"
#include "Exception.h"

template <typename Type>
class Dynamic_queue_as_array {
private:
	int initial_capacity; //of array
	int array_capacity;  //current capacity of array
	int ihead; //head index
	int itail; //tail index
	int entry_count; //number of entries in queue
	Type *array; //pointer to an instance of Type, to be used as an array (point to address of 1st entry)
	// other integer member variables, as necessary

public:
	Dynamic_queue_as_array( int = 10 );
	Dynamic_queue_as_array( Dynamic_queue_as_array const & );
	~Dynamic_queue_as_array();

	Type head() const; //retrun object at head of queue
	int size() const;  //return number of objects currently in queue
	bool empty() const;  //is the queue empty 
	int capacity() const;  //current capacity of queue

	void swap( Dynamic_queue_as_array & );
	Dynamic_queue_as_array &operator = ( Dynamic_queue_as_array );
	void enqueue( Type const & );
	Type dequeue();
	void clear();

	// Friends

	template <typename T>
	friend std::ostream &operator << ( std::ostream &, Dynamic_queue_as_array<T> const & );
};

//constructor
template <typename Type>
Dynamic_queue_as_array<Type>::Dynamic_queue_as_array( int n ):          
	initial_capacity( std::max( n, 1 ) ),
	array_capacity( initial_capacity ),
	array( new Type[initial_capacity] ),        
	ihead( initial_capacity - 1 ),
	itail( 0 ),
	entry_count( 0 ) {
		// Enter your implementation here.
}


//copy constructor
template <typename Type>
Dynamic_queue_as_array<Type>::Dynamic_queue_as_array( Dynamic_queue_as_array const &queue ):       
	initial_capacity( queue.initial_capacity ),
	array_capacity( queue.array_capacity ),
	array( new Type[array_capacity] ),
	ihead( queue.ihead ),
	itail( queue.itail ),
	entry_count( queue.entry_count ) {
		// The above initializations copy the values of the appropriate
		// member variables and allocate memory for the data structure;
		// however, you must still copy the stored objects.

		// Enter your implementation here.

		for (int i =0; i<array_capacity; i++)
		{
			array[i] = queue.array[i];
		}
}

//destructor
template <typename Type>
Dynamic_queue_as_array<Type>::~Dynamic_queue_as_array() {         
	// Enter your implementation here.

	delete[] array;
}

//Accessors

//returns the number of elements currently in the queue
template <typename Type>
int Dynamic_queue_as_array<Type>::size() const {       
	// Enter your implementation here.
	return entry_count;                       
}

//returns the current capacity of the queue
template <typename Type>
int Dynamic_queue_as_array<Type>::capacity() const {
	// Enter your implementation here.
	return array_capacity;
}

//returns true if the queue is empty
template <typename Type>
bool Dynamic_queue_as_array<Type>::empty() const {
	// Enter your implementation here.
	return (size() == 0);                     
}

//returns the element of the head of queue
template <typename Type>
Type Dynamic_queue_as_array<Type>::head() const {
	// Enter your implementation here.
	if (empty())
		throw underflow();
	return array[ihead] ;
}

//Mutators

template <typename Type>
void Dynamic_queue_as_array<Type>::swap( Dynamic_queue_as_array<Type> &queue ) {
	std::swap( initial_capacity, queue.initial_capacity );
	std::swap( array_capacity, queue.array_capacity );
	std::swap( array, queue.array );
	std::swap( ihead, queue.ihead );
	std::swap( itail, queue.itail );
	std::swap( entry_count, queue.entry_count );
}

template <typename Type>
Dynamic_queue_as_array<Type> &Dynamic_queue_as_array<Type>::operator = ( Dynamic_queue_as_array<Type> rhs ) {
	swap( rhs );

	return *this;
}

//adds a new element (obj) to the tail of the queue
template <typename Type>
void Dynamic_queue_as_array<Type>::enqueue( Type const &obj ) {

	//1) queue is empty
	if (empty())                  
	{
		array[itail]= obj;
		ihead = itail;
		entry_count++;
	}
	//2)itail hasn't yet reached the end of queue
	else if (itail < capacity()-1)          
	{
		itail++;     //++itail;
		array[itail] = obj;
		entry_count++;
	}
	//3)itail at the end of the queue
	else if (itail == capacity()-1)
	{
		if (size() < capacity())
		{
			itail = 0;
			array[itail] = obj;
			entry_count++;
		}	
		else	
		{
			Type *newarray  = new Type[capacity()*2];
			//copy the elements of old array over to newarray.
			for (int i= 0; i <capacity();i++)
			{
				newarray[i] = array[i];
			}	
			//delete old array.
			delete [] array;
			// point the 'array' pointer to newarray
			array = newarray;

			//update tail pointer, array_capacity, entry_count
			array[++itail] = obj;
			array_capacity = capacity()*2;
			entry_count++;

		}
	}
}

//deletes the element at the head of the queue
template <typename Type>
Type Dynamic_queue_as_array<Type>::dequeue() {
	// Enter your implementation here.

	//1)queue is empty
	if (empty())
		throw underflow();

	//2)ihead hasn't reached the end of the queue
	else if (ihead < capacity()-1)
	{
		Type tmp = head();
		ihead++;
		entry_count--;

		if(size()==(capacity()/4)&& capacity()>initial_capacity)
		{
			Type* newarray = new Type[capacity()/4];
			for (int i= 0; i<capacity(); i++)
			{
				newarray[i] = array[i];
			}

			delete [] array;	
			array = newarray;
			array_capacity = capacity()/4;
			ihead=0;
			itail = capacity()-1;

		}

		return tmp;
	}

	//ihead at the end of the queue
	else if (ihead == capacity()-1)
	{
		Type tmp = head();
		ihead = 0;
		return tmp;
	}

}

//reset the member variables
template <typename Type>
void Dynamic_queue_as_array<Type>::clear() {      
	// Enter your implementation here.

	entry_count=0;
	ihead=initial_capacity-1;
	itail=0;
	array_capacity= initial_capacity;
	delete []array;
	array = new Type[capacity()];

}

// You can modify this function however you want:  it will not be tested

template <typename Type>
std::ostream &operator << ( std::ostream &out, Dynamic_queue_as_array<Type> const &queue ) {
	// I don't know how you are implementing your queue so I cannot print it.
	// If you want, you can print whatever you want here and then call cout
	// in the driver.

	// Remember to redirect to out, e.g.,
	//      out << "Hello!";
	//out << queue.size();
	//for (int i =queue.ihead; i != (queue.itail+1 % queue.array_capacity);(i++ % queue.array_capacity)){
	//std::cout<<queue.array[i]<<"; ";
	std::cout<<queue.ihead<< " ihead "<<queue.itail<<" itail ";
	std::cout<<queue.array_capacity<<" capacity ";
	//}
	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif