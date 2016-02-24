#include <iostream>
#include <stdlib.h>

using namespace std;

/*
create a copy of the array, and the element values should be reversed
in the copy.  Return a pointer to the new array.
*/


int* reverseArray(int *a,int SIZE){
    int* revArray;
    revArray= new int[SIZE];
    int j=0;
    for(int i=SIZE-1;i>=0;i--){
        revArray[j]=*(a+i);
        j++;
    }

    return revArray;

}


int main()
{
    const int SIZE = 10;
    int numArray[]={1,2,3,4,5,6,7,8,9,10};
    int *revArray;
    cout<<"orginal array: ";

    for(int i=0;i<sizeof(numArray)/sizeof(int);i++){
        cout<<numArray[i];
    }
    cout<<endl;

    revArray=reverseArray(numArray,SIZE);

    cout<<"reversed array: ";
    for(int i=0;i<SIZE;i++){
        cout<<revArray[i];
    }

    return 0;

}
