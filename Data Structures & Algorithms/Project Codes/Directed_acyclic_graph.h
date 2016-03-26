#ifndef DIRECTED_ACYCLIC_GRAPH_H
#define DIRECTED_ACYCLIC_GRAPH_H

/*****************************************
* UW User ID:  y52wei
* Submitted for ECE 250
* Department of Electrical and Computer Engineering
* University of Waterloo
* Calender Term of Submission:  Fall 2013
*
* By submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*****************************************/

#include "ece250.h"
#include "Exception.h"
#include <queue>
#include <limits>
#include <iostream>
#include <cmath>

class Directed_acyclic_graph {
private:
	//number of vertices in the graph
	int vertices_count;
	//number of edges in the graph
	int edges_count;
	//adjacency matrix to store edges
	bool **matrix;
	//pointer to an array to store vertices' priorities
	double *vertices_priority;
	// arrays to store the in/out degrees
	int *in_deg;
	int *out_deg;
	static const double INF;


public:
	Directed_acyclic_graph( int = 10 );
	Directed_acyclic_graph( Directed_acyclic_graph const & );
	~Directed_acyclic_graph();

	void swap( Directed_acyclic_graph & );
	Directed_acyclic_graph &operator = ( Directed_acyclic_graph );

	int in_degree( int ) const;
	int out_degree( int ) const;
	int edge_count() const;
	bool adjacent( int, int ) const;
	bool connected( int, int ) const;
	void topological_sort() const;

	bool set_priority( int, double );
	bool insert_edge( int, int );
	void clear_edges();
	void reset_priorities();
	void print_matrix();

	friend std::ostream &operator << ( std::ostream &, Directed_acyclic_graph const & );

};

const double Directed_acyclic_graph::INF =
	std::numeric_limits<double>::infinity();

//constructor
Directed_acyclic_graph::Directed_acyclic_graph(int n):
	vertices_count(n),
	edges_count(0),
	matrix(new bool *[vertices_count]),
	vertices_priority(new double[n]),
	in_deg(new int [vertices_count]),
	out_deg(new int [vertices_count]){

		//this loop builds the adjacency matrix storing the edges
		for ( int i = 0; i < vertices_count; ++i ) {
			//create each row in the adjacency matrix
			matrix[i] = new bool[vertices_count];

			for (int j=0; j<vertices_count; ++j){
				matrix[i][j]=false;
			}
		}

		//initialize the in/out_deg arraries,the priority array
		for (int i=0;i<vertices_count;++i){
			vertices_priority[i]=static_cast<double>(i);
			in_deg[i]=0;
			out_deg[i]=0;	
		}
}

//destructor
Directed_acyclic_graph::~Directed_acyclic_graph(){
	for ( int i = 0; i < vertices_count; ++i ) {
		delete [] matrix[i];	
	}
	delete []matrix;
	delete []vertices_priority;
	delete []in_deg;
	delete []out_deg;

}

//copy constructor
Directed_acyclic_graph::Directed_acyclic_graph(Directed_acyclic_graph const &obj ):
	vertices_count(obj.vertices_count),
	edges_count(obj.edges_count),
	matrix(new bool *[vertices_count]),
	vertices_priority(new double[vertices_count]),
	in_deg(new int [vertices_count]),
	out_deg(new int [vertices_count]){

		for ( int i = 0; i<vertices_count; ++i ) {
			//create each row in the adjacency matrix
			matrix[i] = new bool[vertices_count];

			for (int j=0; j<vertices_count; ++j){
				matrix[i][j]=obj.matrix[i][j];
			}
		}

		for (int i=0;i<vertices_count;++i){
			vertices_priority[i]=obj.vertices_priority[i];
			in_deg[i]=obj.in_deg[i];
			out_deg[i]=obj.out_deg[i];	

		}
}

//accessors 

//in_degree(): returns the in degree of the given vertex i
int Directed_acyclic_graph:: in_degree(int i) const{

	if ((i<0 || i>vertices_count))
		throw illegal_argument();

	return in_deg[i];
}

//out_degree(): returns the out degree of the given vertex i
int Directed_acyclic_graph:: out_degree(int i) const {

	if ((i<0 || i>vertices_count))
		throw illegal_argument();

	return out_deg[i];
}

//edge_count(): returns the number of edges in the graph
int Directed_acyclic_graph:: edge_count() const {
	return edges_count;
}

//adjacent():returns true if an edge exists from vertex i to vertex j
bool Directed_acyclic_graph:: adjacent(int i,int j) const {

	//write a if statement to  check the values of i and j?
	if ((i<0 || i>vertices_count) || (j<0 || j>vertices_count))
		throw illegal_argument();

	if (matrix[i][j]==true)
		return true;
	else
		return false;
}

//connected(): returns true if there exists a directed path from vertex i to j. Use a queue.
bool Directed_acyclic_graph:: connected(int i, int j) const {

	if (i==j)
		return true;
	std::queue<int> queue;

	//push the starting vertex onto the queue
	queue.push(i);

	while(!queue.empty()){
		//pop and store the front of the queue
		int cur_vertex = queue.front();
		queue.pop();

		//if the poped vertex is j, we are done
		if (cur_vertex==j)
			return true;

		//find the vertices that are connected to the pop front 
		for (int k=0;k<vertices_count;++k){
			if (matrix[cur_vertex][k]==true)
				queue.push(k);
		}
	}
	return false;
}

/*topological_sort():  print a topological sort of the vertices in the DAG by printing
the vertices separated by a dash -. Restriction: if there are multiple possible
vertices which could be included next in the ordering, the one with the highest priority
value must be chosen. Topological sort must print all vertices. The output shouldn't have 
an end-of-line character at the end*/
void Directed_acyclic_graph:: topological_sort() const  {
	std::queue<int> queue;
	int *result = new int [vertices_count];
	int *in_deg_copy = new int[vertices_count];
	int *holder = new int [vertices_count];
	int counter = 0;
	int tmp_vertex = 0;
	bool done_sorting=false;

	for(int i = 0; i <vertices_count; ++i ){
		in_deg_copy[i]=in_deg[i];
		result[i]=0;
	}

	while(!done_sorting){
		//initialize a blank array for tmp_vertex processing
		for( int i=0; i<vertices_count; ++i)		
			holder[i] = 0;

		//push onto a queue the list of vertices with in degree 0
		for(int i=0; i<vertices_count; ++i){
			if(in_deg_copy[i] == 0)
				queue.push(i);
		}

		int size = queue.size();
		//populate the blank array with the list
		for(int i = 0; i<size; ++i ){
			holder[i] = queue.front();
			queue.pop();
		}

		//the first element of the array assigned to tmp_vertex
		tmp_vertex = holder[0];

		// this loop puts the vertex with highest priority and in degree 0 into tmp_vertex
		for(int i = 0; i<size; ++i ){		
			if(vertices_priority[holder[i]] < vertices_priority[tmp_vertex])
				tmp_vertex = holder[i];	
		}

		//decrement in degrees for all adjacent vertices
		for(int i=0; i<vertices_count; ++i){
			if(adjacent(tmp_vertex,i))
				in_deg_copy[i]--;	
		}
		//put the chosen vertex into result array
		result[counter] = tmp_vertex;

		//set the processed vertex's in_deg to infinity, so it won't be processed again
		in_deg_copy[tmp_vertex] = INF;

		//increment counter
		counter++;

		//decide if the sorting loop is done
		if (counter==vertices_count)
			done_sorting = true;

	}
	//printing the list by going through result array
	std::cout << "X";
	for (int i=0; i<vertices_count; ++i){
		if(i!=vertices_count-1){
			std::cout << result[i];
			std::cout << "-";
		}
		else
			std::cout << result[i];
	}
	std::cout << "X";

	//delete all allocated memories
	delete [] result;
	delete [] in_deg_copy;
	delete [] holder;

}


//mutators 

/*set_priority(): if another vertex already exists with the argument 'priority', 
return false and do nothing; otherwise, set the priority of vertex 'i' to 'priority'
and return true.*/
bool Directed_acyclic_graph::set_priority(int i,double priority){

	for (int j=0; j<vertices_count; ++j){
		if (vertices_priority[j]==priority)
			return false;
	}
	vertices_priority[i] = priority;
	return true;
}

/*insert_edge(): insert a new edge from vertex "i to j" so long as the new vertex doesn't cause
a cycle to form. Return true if the insertion is successful, and false otherwise. if i equals
j, return false and if an edge from i to j already exists, return false. If i or j are outside
the range 0...n-1, throw an illegal argument exception*/
bool Directed_acyclic_graph::insert_edge(int i, int j){

	if ((i<0 || i>vertices_count) || (j<0 || j>vertices_count))
		throw illegal_argument();

	if (i==j)
		return false;
	if (matrix[i][j]==true)
		return false;

	//inserting an edge, make sure no cycle forms
	if (!connected(j,i)){
		matrix[i][j] = true;
		edges_count++;
		//update the in/out degrees
		in_deg[j]++;
		out_deg[i]++;
		return true;
	}

	return false;

}

//clear_edges():removes all the edges from the graph
void Directed_acyclic_graph::clear_edges() {

	for ( int i = 0; i < vertices_count; ++i ) 
	{

		for (int j=0; j<vertices_count; ++j){
			matrix[i][j]=false;
		}
	}

	for (int i=0; i<vertices_count; ++i){
		in_deg[i]=0;
		out_deg[i]=0;
	}

	edges_count=0;
}

//reset_priorities(): sets the priority of all vertices to their deafault value
void Directed_acyclic_graph::reset_priorities() {

	for (int j = 0; j<vertices_count; ++j)
		vertices_priority[j]=static_cast<double>(j);

}

/*print_matrix(): print the adjacency matrix       FOR TESTING PURPOSE
void Directed_acyclic_graph::print_matrix()
{
	std::cout<<"  ";
	for(int p = 0 ;p<vertices_count;++p)
	{
		std::cout<<p<<" ";
	}
	std::cout<<std::endl;
	for(int i =0 ; i<vertices_count;++i)
	{
		std::cout<<i<<" ";
		for(int j = 0 ; j <vertices_count;++j)
		{
			std::cout<<matrix[i][j] << " ";
		}
		std::cout<<std::endl;
	}
}*/


//swap()
void Directed_acyclic_graph::swap( Directed_acyclic_graph &dag ) {
	// Swap all your member variables

	std::swap(vertices_count,dag.vertices_count);
	std::swap(edges_count,dag.edges_count);
	std::swap(matrix,dag.matrix);
	std::swap(vertices_priority,dag.vertices_priority);
	std::swap(in_deg,dag.in_deg);
	std::swap(out_deg,dag.out_deg);

}

Directed_acyclic_graph &Directed_acyclic_graph::operator = ( Directed_acyclic_graph rhs ) {
	swap( rhs );

	return *this;
}

// whatever you want...

// You can modify this function however you want:  it will not be tested

std::ostream &operator << ( std::ostream &out, Directed_acyclic_graph const &list ) {
	out << "#";

	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif