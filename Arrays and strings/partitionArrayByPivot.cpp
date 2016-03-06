#include <iostream>
#include <math.h>
#include <string>
#include <vector>


using namespace std;

/*
a function that takes array A and index i, and rearranges elements such that
all elements <A[i] =A[i] >A[i]
*/

template <typename T>
void partition_array(vector<T> &A, const int &p_ind){
    T pivot = A[p_ind];

    int smaller=0, equalPivot=0, larger=A.size()-1;
    while(equalPivot<=larger){
        if(A[equalPivot]<pivot){
            swap(A[smaller++],A[equalPivot++]);
        }
        else if(A[equalPivot]==pivot){
            ++equalPivot;
        }
        else{
            swap(A[equalPivot],A[larger--]);  //A[equalPivot]>pivot
        }
    }

}

int main()
{
    char cArray[] = {'a','c','b','f','e','c','d','c'};
    vector<char> cVector(cArray, cArray+sizeof(cArray)/sizeof(char));

    int nArray[] = {1,5,8,10,24,23,0,72,7};
    vector<int> nVector(nArray,nArray+sizeof(nArray)/sizeof(int));

    partition_array(cVector,1);   //the index of the pivot
    partition_array(nVector,3);

    for(int i=0;i<cVector.size();i++){
        cout<<cVector.at(i)<<' ';
    }

    cout<<endl;

   for(int i=0;i<nVector.size();i++){
        cout<<nVector.at(i)<<' ';
    }

}
