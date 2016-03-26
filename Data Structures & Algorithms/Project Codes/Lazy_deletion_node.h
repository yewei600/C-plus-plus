#ifndef LAZY_DELETION_NODE_H
#define LAZY_DELETION_NODE_H

/*****************************************
* UW User ID:  y52wei
* Submitted for ECE 250
* Semester of Submission:  Fall 2013
*
* By  submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*****************************************/

#include "ece250.h"
#include "Exception.h"
#include <utility>

#define nullptr 0

template <typename Type>
class Lazy_deletion_tree;

template <typename Type>
class Lazy_deletion_node {
private:
	Type element;
	Lazy_deletion_node<Type> *left_tree;
	Lazy_deletion_node<Type> *right_tree;
	bool erased;

public:
	Lazy_deletion_node( Type const & = Type() );

	Lazy_deletion_node<Type> *left() const;
	Lazy_deletion_node<Type> *right() const;
	Type retrieve() const;
	int height() const;
	std::pair<Type, bool> front() const;
	std::pair<Type, bool> back() const;
	bool member( Type const & ) const;

	bool insert( Type const & );
	bool erase( Type const & );
	void clear();
	void clean( Lazy_deletion_node *& );

	friend class Lazy_deletion_tree<Type>;
};

//Constructor
template <typename Type>
Lazy_deletion_node<Type>::Lazy_deletion_node( Type const &obj ):
	element( obj ),
	left_tree( nullptr ),
	right_tree( nullptr ),
	erased( false ) {
		// does nothing
}

//Accessors

//left(): returns the left subtree of 'this' node
template <typename Type>
Lazy_deletion_node<Type> *Lazy_deletion_node<Type>::left() const {

	if (this == nullptr)
		throw underflow();                   
	return left_tree;

}

//right() : return the right subtree of 'this'node
template <typename Type>
Lazy_deletion_node<Type> *Lazy_deletion_node<Type>::right() const {

	if (this == nullptr)
		throw underflow();                        
	return right_tree;

}

//retrieve(): returns the value of 'this' onde
template <typename Type>
Type Lazy_deletion_node<Type>::retrieve() const {

	return element;
}

//height(): returns the height of tree
//empty tree has height -1
template <typename Type>
int Lazy_deletion_node<Type>::height() const {               
	if(this==nullptr)
		return -1;
	int leftHeight = 0;
	int rightHeight = 0;

	leftHeight = left()->height();
	rightHeight = right()->height();
	return 1+std::max(leftHeight,rightHeight);
}

//member(): checks if a node in the tree stores element 'obj'
template <typename Type>
bool Lazy_deletion_node<Type>::member(Type const &obj) const {
	if (this == nullptr)
		return false;
	else if (retrieve()==obj)
		return true;

	else
	{
		if (obj < retrieve())
			return left()->member(obj);
		else
			return right()-> member(obj);
	}

	return false;       
}

//front(): returns the minimum object that's not erased in 'this' subtree
template <typename Type>
std::pair<Type, bool> Lazy_deletion_node<Type>::front() const {
	if ( this == nullptr ) {
		return std::pair<Type, bool>( Type(), false );
	}

	std::pair<Type, bool> result = left()->front();

	if ( result.second ) {
		return result;
	}

	if ( !erased ) {
		return std::pair<Type, bool>( retrieve(), true );
	}

	result = right()->front();

	if ( result.second ) {
		return result;
	}

	return std::pair<Type, bool>( Type(), false );
}

//back(): returns the maximum object that's not erased in 'this' subtree
template <typename Type>
std::pair<Type, bool> Lazy_deletion_node<Type>::back() const {

	if ( this == nullptr ) {
		return std::pair<Type, bool>( Type(), false );
	}

	std::pair<Type, bool> result = right()->back();

	if ( result.second ) {
		return result;
	}

	if ( !erased ) {
		return std::pair<Type, bool>( retrieve(), true );
	}

	result = left()->back();

	if ( result.second ) {
		return result;
	}

	return std::pair<Type, bool>( Type(), false );
}

// Your implementation here
//Mutators

//insert(): inserts a node with the value 'obj' into subtree
//if such a node already exists, returns false
template <typename Type>
bool Lazy_deletion_node<Type>::insert(Type const &obj)  {

	if (retrieve() == obj)
	{
		if (erased)
		{
			erased = false;
			return true;
		}
		return false;	
	}

	if ( obj < retrieve() ) {
		if ( left()==nullptr ) {
			left_tree = new Lazy_deletion_node<Type>( obj );
		} else {
			left()->insert( obj );
		}
	} else if ( obj > retrieve() ) {
		if ( right()==nullptr ) {
			right_tree = new Lazy_deletion_node<Type>( obj );
		} else {
			right()->insert( obj );
		}
	}    

}

//erase(): erases a node 
template <typename Type>
bool Lazy_deletion_node<Type>::erase(Type const &obj)  {
	if (retrieve()==obj)
	{
		if (erased)
			return false;
		else
		{
			erased = true;
			return true;
		}
	}

	else
	{
		if (obj < retrieve())                         
			left()->erase(obj);
		else
			right()->erase(obj);
	}

}


//clear(): deletes both subtrees of 'this' node
template <typename Type>
void Lazy_deletion_node<Type>::clear() {
	if(this==nullptr)
		return;
	left()->clear();
	right()->clear();
	delete this;

}

//clean(): deletes all nodes that are marked as 'erased'
template <typename Type>
void Lazy_deletion_node<Type>::clean(Lazy_deletion_node *&ptr_to_this) {
	if (this == nullptr)
		return;
	if (erased)
	{
		std::pair<Type,bool>result_right = right()->front();
		if (result_right.second)
		{
			element = result_right.first;
			erased = false;
			right()->erase(result_right.first);
		}
		else
		{
			std::pair<Type,bool>result_left = left()->back();
			if (result_left.second)
			{
				element = result_left.first;
				erased = false;
				left()->erase(result_left.first);
			}
		}			
	}
	this->right_tree->clean(right_tree);
	this->left_tree->clean(left_tree);

	if(erased)
	{
		ptr_to_this = nullptr;
		delete this;
	}


}







#endif
