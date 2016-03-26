#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

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
#include "ece250.h"

// state of a cell in the array
enum state { EMPTY, OCCUPIED, DELETED };

template<typename Type>
class Double_hash_table {
private:

	int count;
	//what's the use?
	int power;         
	int array_size;
	//what is the use of this variable? 
	int mask;           
	Type *array;
	state *occupied;

	int h1( Type const & ) const;
	int h2( Type const & ) const;

public:
	Double_hash_table( int = 5 );
	~Double_hash_table();
	int size() const;
	int capacity() const;
	double load_factor() const;
	bool empty() const;
	bool member( Type const & ) const;
	Type bin( int ) const;

	void print() const;

	void insert( Type const & );
	bool remove( Type const & );
	void clear();

	// Friends

	template <typename T>
	friend std::ostream &operator << ( std::ostream &, Double_hash_table<T> const & );
};

//h1(): 1st hash function: gives the bin
template<typename Type>
int Double_hash_table<Type>::h1(Type const &obj) const{

	int entry = static_cast<int>(obj);

	return (entry % array_size > 0)? (entry % array_size)  : 
		(entry % array_size + array_size);


}

//h2(): 2nd hash function: gives the jump size
template<typename Type>
int Double_hash_table<Type>::h2(Type const &obj) const{

	int entry = static_cast<int>(obj);

	return ((entry/array_size) % array_size > 0)? ((entry/array_size) % array_size)|1 : 
		((entry/array_size) % array_size + array_size)| 1 ;

	//make sure h2 always gives  ODD value. 

}




//Constructor
template<typename Type>
Double_hash_table<Type>::Double_hash_table( int m ):
	count( 0 ), power( m ),
	array_size( 1 << power ),
	mask( array_size - 1 ),
	//'new' operator allocates dynamic memory
	array( new Type[array_size] ),
	occupied( new state[array_size] ) {

		for ( int i = 0; i < array_size; ++i ) {
			occupied[i] = EMPTY;
		}
}

//Destructor
template<typename Type>
Double_hash_table<Type>::~Double_hash_table() {
	//delete the dynamically allocated memory
	delete [] array;
	delete [] occupied;
}


//Accessors

//size(): returns number of elements currently stored in hash table
template<typename Type>
int Double_hash_table<Type>::size() const {
	return count;
}

//capacity(): returns number of bins in hash table
template<typename Type>
int Double_hash_table<Type>::capacity() const {
	return array_size;
}

//load_factor(): returns the ratio of # of items in HT/# of cells in HT 
template<typename Type>
double Double_hash_table<Type>::load_factor() const {
	return static_cast<double>(count)/array_size;
}

//empty(): returns true if there's nothing in HT
template<typename Type>
bool Double_hash_table<Type>::empty() const {
	return count == 0;
}

//member(): returns true if 'obj' is in the HT, and false if not
template<typename Type>
bool Double_hash_table<Type>::member(Type const &obj) const {
	int initial = h1(obj);
	int jump = h2(obj);

	for (int i = 0; i<array_size; i++){
		int spot = (initial+i*jump) % array_size;

		//if found the obj, don't have to go forward anymore.
		if (array[spot]==obj){
			return (occupied[spot]==OCCUPIED)? true:false;
		}
	}
	return false;
}

/*bin():returns the entry in bin 'n'. Behaviour of this function is 
undefined if bin 'int' is not filled.*/
template<typename Type>
Type Double_hash_table<Type>::bin(int n) const {
	if (occupied[n]==EMPTY || occupied[n]==DELETED)
		return nullptr;

	return array[n];


}

//print()
template<typename Type>
void Double_hash_table<Type>::print() const {

}


//Mutators

/*insert(): insert new object 'obj' into hash table in the appropriate bin as
determined by the 2 hash functions 'h1 and h2' and the rules of double hashing.
if table is full, throw an overflow() exception. */
template<typename Type>
void Double_hash_table<Type>::insert(Type const &obj) {

	int initial = h1(obj);
	int jump = h2(obj);

	if (count == array_size)
		throw overflow();

	//a for loop
	for (int i = 0; i<array_size;i++){
		int spot = (initial+i*jump) % array_size;

		if (array[spot] == obj){
			if (occupied[spot]==DELETED)
				occupied[spot]=OCCUPIED;
			return;
		}

		//if a cell is in the EMPTY or DELETED state, and 'obj' is not in the HT, insert 
		//into the cell
		if ((occupied[spot]== EMPTY || occupied[spot]== DELETED)  && !member(obj) ){
			array[spot] = obj;
			occupied[spot] = OCCUPIED;	
			count++;
			return;
		}

	}



}

/*remove(): remove the object 'obj' from hash table if it is in hash table(return
false otherwise) by setting the corresponding flag of the bin to be deleted.*/
template<typename Type>
bool Double_hash_table<Type>::remove(Type const &obj) {
	int initial = h1(obj);
	int jump = h2(obj);

	for (int i = 0; i<array_size; i++){
		int spot = (initial+i*jump) % array_size;

		if (array[spot]==obj){
			if (occupied[spot] == DELETED)
				return false;         
			else{
				occupied[spot] = DELETED;
				count--;
				return true;
			}
		}
	}
	return false;
}

//clear(): removes all elements in the HT
template<typename Type>
void Double_hash_table<Type>::clear() {

	for(int i=0; i<array_size; i++){
		occupied[i]=EMPTY;
	}
	count = 0;

}

template <typename T>
std::ostream &operator << ( std::ostream &out, Double_hash_table<T> const &hash ) {
	for ( int i = 0; i < hash.capacity(); ++i ) {
		if ( hash.occupied[i] == EMPTY ) {
			out << "- ";
		} else if ( hash.occupied[i] == DELETED ) {
			out << "x ";
		} else {
			out << hash.array[i] << ' ';
		}
	}

	return out;
}

#endif
