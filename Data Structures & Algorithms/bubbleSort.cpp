#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
const int SIZE=10;


void displayArray(int a[],int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
}

int* bubbleSort(int* p,int s){
    cout<<"sorting..."<<endl;
    int tmp,cnt=0;
    for(int i=0;i<s-1;i++){
        for(int j=s-1;j>=i+1;j--){
            if(p[j]<p[j-1]){
                tmp=p[j];
                p[j]=p[j-1];
                p[j-1]=tmp;

                cout<<setw(2)<<cnt<<"): ";
                displayArray(p,s);
                cnt++;
                cout<<endl;
            }
        }
    }
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
