#ifndef LAZY_TREE_H
#define LAZY_TREE_H

#include <queue>
#include "Lazy_deletion_node.h"

/*****************************************
* UW User ID:  y52wei
* Submitted for ECE 250
* Semester of Submission:  Fall 2013
*
* By  submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*****************************************/

#define nullptr 0

template <typename Type>
class Lazy_deletion_tree {
private:
	Lazy_deletion_node<Type> *root_node;
	int count;

public:
	Lazy_deletion_tree();
	~Lazy_deletion_tree();

	bool empty() const;
	int size() const;
	int height() const;
	Type front() const;
	Type back() const;
	bool member( Type const & ) const;
	void breadth_first_traversal() const;

	bool insert( Type const & );
	bool erase( Type const & );
	void clean();
	void clear();
};

//Constructor
template <typename Type>
Lazy_deletion_tree<Type>::Lazy_deletion_tree():
	root_node( nullptr ),
	count( 0 ) {
		// Only initializes member variables
}

//Destructor 
template <typename Type>
Lazy_deletion_tree<Type>::~Lazy_deletion_tree()
{
	root_node->clear();
}

//empty(): check if there's 0 node in tree
template <typename Type>
bool Lazy_deletion_tree<Type>::empty() const {
	return size()==0;
}


//size(): returns the number of nodes in tree
template <typename Type>
int Lazy_deletion_tree<Type>::size() const {
	return count;
}

//height()
template <typename Type>
int Lazy_deletion_tree<Type>::height() const {
	return root_node->height();
}

//member()
template <typename Type>
bool Lazy_deletion_tree<Type>::member(Type const &obj) const {
	if (root_node->member(obj))
	{
		return true;
	}

	return false;
}

//front()
template <typename Type>
Type Lazy_deletion_tree<Type>::front() const {

	std::pair<Type, bool> result = root_node->front();

	if (result.second)
		return result.first;
	if (!result.second)
		throw underflow();


}

//back()
template <typename Type>
Type Lazy_deletion_tree<Type>::back() const {

	std::pair<Type, bool> result = root_node->back();

	if (result.second)
		return result.first;
	if (!result.second)
		throw underflow();

}

//breadth_first_traversal(): goes through the tree using BFT, prints each node out
//specifies if a node is erased or not
template <typename Type>
void Lazy_deletion_tree<Type>::breadth_first_traversal() const {
	if ( root_node == nullptr ) {
		return;
	}

	// Read up on the STL queue at http://www.cplusplus.com/reference/queue/queue/
	std::queue< Lazy_deletion_node<Type> *> queue;

	queue.push( root_node );
	if (root_node->erased)
		std::cout<< root_node->retrieve()<<"x ";
	else
		std::cout<< root_node->retrieve()<<" ";


	while ( !queue.empty() ) {
		Lazy_deletion_node<Type> *ptr = queue.front();
		queue.pop();

		if (ptr->left() != nullptr)
		{
			queue.push(ptr->left());
			if (ptr->left()->erased)
				std::cout<< ptr->left()->retrieve()<<"x ";
			else
				std::cout<< ptr->left()->retrieve()<<" ";

		}

		if (ptr->right() != nullptr)
		{
			queue.push(ptr->right());
			if (ptr->right()->erased)
				std::cout<< ptr->right()->retrieve()<<"x ";
			else
				std::cout<< ptr->right()->retrieve()<<" ";

		}
	}

}

// Mutators

//insert()
template <typename Type>
bool Lazy_deletion_tree<Type>::insert(Type const &obj) {

	if (empty())
	{
		root_node = new Lazy_deletion_node<Type>(obj);
		count++;
		return true;
	}

	else
	{
		if (root_node->insert(obj))
		{
			count++;
			return true;
		}
		return false;
	}
}

//erase()
template <typename Type>
bool Lazy_deletion_tree<Type>::erase(Type const &obj) {
	if (empty())
		return false;

	if (root_node->erase(obj))
	{
		count--;
		return true;
	}
	else
		return false;
}

//clear()
template <typename Type>
void Lazy_deletion_tree<Type>::clear() {
	root_node->clear();
	count = 0;
}

//clean()
template <typename Type>
void Lazy_deletion_tree<Type>::clean() {

	//go through the tree, using left and right subtree logic to check if a member is match
	return root_node->clean(root_node);
}


#endif