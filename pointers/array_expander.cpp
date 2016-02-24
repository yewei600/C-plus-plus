#include <iostream>
#include <stdlib.h>

using namespace std;

/*
create an array twice the size of the argument array. copy the argument
array into new array, then initialize the other half to 0s
*/


int* arrayExpander(int *a,int SIZE){
    int* expandArray;
    expandArray= new int[SIZE*2];
    int j=0;
    for(int i=0;i<SIZE*2;i++){
        if(i>=SIZE){
            expandArray[i]=0;
        }
        else{
            expandArray[i]=*(a+i);
        }
    }

    return expandArray;

}


int main()
{
    const int SIZE = 10;
    int numArray[]={0,1,2,3,4,5,6,7,8,9};
    int *expandArray;

    cout<<"orginal array: ";
    for(int i=0;i<sizeof(numArray)/sizeof(int);i++){
        cout<<numArray[i];
    }
    cout<<endl;

    expandArray=arrayExpander(numArray,SIZE);

    cout<<"reversed array: ";
    for(int i=0;i<SIZE*2;i++){
        cout<<expandArray[i];
    }

    return 0;

}
