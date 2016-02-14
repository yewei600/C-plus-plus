#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;

//compare binary search against linear search

int binarySearch(int a[],int val){
    
    


}

int linearSearch(int a[]){


}

int main()
{
    int numArray[20];
    int i;
    srand(time(NULL));
    for(i=0;i<20;i++){
        numArray[i]= rand()%100+1;
    }

    std::sort(numArray,numArray+20);

    for(i=0;i<20;i++){
        cout<<numArray[i]<<" ";
    }
    
    return 0;
}
