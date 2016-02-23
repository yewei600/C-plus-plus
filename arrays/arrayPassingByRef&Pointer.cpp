#include <iostream>
#include <stdlib.h>

using namespace std;

/*
example of HOW TO PASS AN ARRAY BY REFERENCE
1)using the reference variable
2)using pointer
*/

void reverseArray(int (&a)[10]){
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        a[i]=1;
    }

}

void reverseArray2(int *a,int SIZE){
    for(int i=0;i<SIZE;i++){
        *(a+i)=2;
    }

}


int main()
{
    int numArray1[]={1,2,3,4,5,6,7,8,9,10};
    int numArray2[]={1,2,3,4,5,6,7,8,9,10};

    reverseArray(numArray1);
    reverseArray2(numArray2,10);

    for(int i=0;i<sizeof(numArray1)/sizeof(int);i++){
        cout<<numArray1[i];
    }
    cout<<endl;

    for(int i=0;i<10;i++){
        cout<<numArray2[i];
    }

    return 0;

}
