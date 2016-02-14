#include <iostream>
#include <stdlib.h>


using namespace std;

int *elementShifter(int *a,int s){
    int *newArray = new int[s+1];
    *newArray = 0;

    for(int i=1;i<=s;i++){
        *(newArray+i)=*(a+i-1);
    }
    return newArray;
}


int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int a_size=sizeof(a)/sizeof(a[0]);

    cout<<"the old array:\n";
    for(int i=0;i<a_size;i++){
        cout<<*(a+i)<<" ";
    }

    int *newArray = elementShifter(a,a_size);

    cout<<"\nthe new array:\n";
    for(int i=0;i<=a_size;i++){
        cout<<*(newArray+i)<<" ";
    }

    return 0;

}
