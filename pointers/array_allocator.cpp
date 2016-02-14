#include <iostream>
#include <stdlib.h>

using namespace std;


int* createArray(int s){
    int *pArray = new int[s];

    cout<< "contents of the initialized array:\n";
    for(int i=0;i<s;i++){
        pArray[i]=i;
        cout<<pArray[i]<<" ";
    }
    cout<<endl;
    return pArray;
}


int main()
{
    int SIZE;
    cout<<"enter array size: ";
    cin>>SIZE;

    int *a=createArray(SIZE);

    cout<<"\nreturned pointer to main(). print array again:\n";
     for(int i=0;i<SIZE;i++){
        cout<<a[i]<<" ";
    }

    delete []a;
    //a=0;
    cout<<"\nafter deleting the array:\n";
     for(int i=0;i<SIZE;i++){
        cout<<a[i]<<" ";
    }

    return 0;

}
