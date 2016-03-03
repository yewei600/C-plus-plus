#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>

using namespace std;
const int SIZE=10;

/*
Merge Sort:   index starting at 0!
*/

void displayArray(int a[],int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
}

int* Merge(int* pA,int p,int q,int r){
    int sentinel=99999;
    int nL=q-p+1, nR=r-q;
    int L[nL+1];   //A[p..q]    +1 for the sentinel
    int R[nR+1];   //A[q+1..r]

    //cout<<"left array: ";
    for(int i=0;i<nL;i++){
        L[i]=pA[p+i];
        //cout<<L[i]<<" ";
    }
   // cout<<"\nright array: ";
    for(int j=0;j<nR;j++){
        R[j]=pA[q+j+1];
       // cout<<R[j]<<" ";
    }
    //cout<<endl;

    L[nL]=sentinel, R[nR]=sentinel;
    int i=0, j=0;

    for(int k=p;k<r;k++){
        if(L[i]<=R[j]){
            pA[k]=L[i];
            i++;
        }
        else{
            pA[k]=R[j];
            j++;
        }
    }
}



void mergeSort(int* pA,int p,int r){
    if(p<r){
        int q=floor((p+r)/2);
        mergeSort(pA,p,q);
        mergeSort(pA,q+1,r);
        Merge(pA,p,q,r);
    }
}



int main(){
   srand(time(NULL));
    int numArray[]={1,5,3,6,4};

    mergeSort(numArray,0,4);

    displayArray(numArray,5);

}
