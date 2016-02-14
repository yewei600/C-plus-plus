#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;


int* createArray(int s, int **pArray){
    int a[s];
    int i;
    *pArray = a;

    cout<< "contents of the initialized array:\n";
    for(i=0;i<s;i++){
        a[i]=i;
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return *pArray;
}


int main()
{
    int SIZE, *pScores;
    int i;
    cout<<"enter the number of scores: ";
    cin>>SIZE;

    createArray(SIZE,&pScores);

     for(i=0;i<SIZE;i++){
        cout<<*(pScores+i)<<" ";
    }

    return 0;

}
