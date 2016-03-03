#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
const int SIZE=10;

/*
like how you sort a hand of cards.
having a ever growing sorted subset of cards, until that subset==whole set
*/

void displayArray(int a[],int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
}

int* insertionSort(int* p,int s){
    int j,key,cnt=0;
    cout<<"insertion sorting..."<<endl;
    for(int i=1;i<s;i++){
        key=p[i];
        j=i-1;
        while(j>=0 && p[j]>key){
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=key;
        //////////////////////////////
        cout<<setw(2)<<cnt<<"): ";
        displayArray(p,s);
        cnt++;
        cout<<endl;
        //////////////////////////////
    }
}



int main(){
    srand(time(NULL));
    int numArray[SIZE];
    
    for(int i=0;i<SIZE;i++){
        numArray[i]=1+rand()%100;   //a pseudo random number between 1-100;
        cout<<numArray[i]<<" ";
    }
    cout<<endl;
    
    insertionSort(numArray,SIZE);
}
