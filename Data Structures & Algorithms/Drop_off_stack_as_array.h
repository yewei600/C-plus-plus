#ifndef DROP_OFF_STACK_AS_ARRAY_H
#define DROP_OFF_STACK_AS_ARRAY_H

/*****************************************
* UW User ID:  y52wei				
* Submitted for ECE 250
* Semester of Submission:  Fall 2013
*
* By submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*****************************************/

#include "Exception.h"

template <typename Type>
class Drop_off_stack_as_array {
private:
	int itop;
	int ibottom;
	int entry_count;   
	int array_capacity;
	Type *array;

public:
	Drop_off_stack_as_array( int = 10 );
	Drop_off_stack_as_array( Drop_off_stack_as_array const & );
	~Drop_off_stack_as_array();

	int size() const;
	bool empty() const;
	Type top() const;

	void swap( Drop_off_stack_as_array & );
	Drop_off_stack_as_array &operator = ( Drop_off_stack_as_array );
	void push( Type const & );
	Type pop();
	void clear();

	// Friends

	template <typename T>
	friend std::ostream &operator << ( std::ostream &, Drop_off_stack_as_array<T> const & );
};

template <typename Type>
Drop_off_stack_as_array<Type>::Drop_off_stack_as_array( int n ):    
	// initialize the member variables 
	itop(std::max(n,1)-1),                      
	ibottom(0),                               
	entry_count(0),
	array_capacity(std::max(n,1)),
	array(new Type[array_capacity])                        
{
	//empty constructor 
}


//Copy Constructor
template <typename Type>
Drop_off_stack_as_array<Type>::Drop_off_stack_as_array( Drop_off_stack_as_array<Type> const &stack ):    
	itop( stack.itop ),
	ibottom( stack.ibottom ),
	entry_count( stack.entry_count ),
	array_capacity( array_capacity ),
	array( new Type[array_capacity] ) {
		// The above initializations copy the values of the appropriate
		// member variables and allocate memory for the data structure; 
		// however, you must still copy the stored objects.

		// Enter your implementation here.

		for (int i =0; i<stack.array_capacity;i++)
		{
			array[i] = stack.array[i];
		}
}

//destructor
template <typename Type>
Drop_off_stack_as_array<Type>::~Drop_off_stack_as_array() {      
	// Enter your implementation here.
	delete [] array;
}

//Accessors

//returns the number of entries currently in stack
template <typename Type>
int Drop_off_stack_as_array<Type>::size() const {
	// Enter your implementation here.
	return entry_count;
}

//returns true if the stack is empty
template <typename Type>
bool Drop_off_stack_as_array<Type>::empty() const {
	// Enter your implementation here.
	return size() == 0;
}

//returns the top of the stack
template <typename  Type>
Type Drop_off_stack_as_array<Type>::top() const {
	// Enter your implementation here.
	if (empty())
		throw underflow();

	return array[itop];
}

//Mutators

template <typename Type>
void Drop_off_stack_as_array<Type>::swap( Drop_off_stack_as_array<Type> &stack ) {
	std::swap( itop, stack.itop );
	std::swap( ibottom, stack.ibottom );
	std::swap( entry_count, stack.entry_count );
	std::swap( array_capacity, stack.array_capacity );
	std::swap( array, stack.array );
}

template <typename Type>
Drop_off_stack_as_array<Type> &Drop_off_stack_as_array<Type>::operator = ( Drop_off_stack_as_array<Type> rhs ) {
	swap( rhs );

	return *this;
} 

//pushes the element (obj) on to the stack
template <typename Type>
void Drop_off_stack_as_array<Type>::push( Type const &obj ) {
	// Enter your implementation here.

	if (empty())
	{
		itop=0;
		array[itop] = obj;
		entry_count++; 
	}
	else if (size()<array_capacity)
	{
		itop++;
		array[itop] = obj;
		entry_count++;
	}

	else if (size() == array_capacity)
	{
		ibottom = (ibottom+1) % array_capacity;
		itop = (itop+1) % array_capacity;
		array[itop] = obj;

	}

}

//pops the element from the top of stack
template <typename Type>
Type Drop_off_stack_as_array<Type>::pop() {
	// Enter your implementation here.
	if (empty())
		throw underflow();
	Type oldhead = array[itop];
	if (itop == 0)
	{	
		itop= array_capacity-1;
		entry_count--;
	}
	else
	{
		itop--;
		entry_count--;
	}
	return oldhead;
}

//resets the member variables
template <typename Type>
void Drop_off_stack_as_array<Type>::clear() {
	// Enter your implementation here.
	itop= array_capacity-1;
	ibottom= 0;
	entry_count = 0;
}

// You can modify this function however you want:  it will not be tested

template <typename T>
std::ostream &operator << ( std::ostream &out, Drop_off_stack_as_array<T> const &stack ) {
	// I don't know how you are implementing your stack so I cannot print it.
	// If you want, you can print whatever you want here and then call cout
	// in the driver.

	// Remember to redirect to out, e.g.,
	//      out << "Hello!";

	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif