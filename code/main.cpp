#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int SIZE=10;

int* bubbleSort(int* p,int SIZE){

    return p;

}


int main(){
    srand(time(NULL));
    int numArray[SIZE];

    for(int i=0;i<SIZE;i++){
        numArray[i]=1+rand()%100;   //a pseudo random number between 1-100;
        cout<<numArray[i]<<" ";
    }
    cout<<endl;


    bubbleSort(numArray,SIZE);



}
