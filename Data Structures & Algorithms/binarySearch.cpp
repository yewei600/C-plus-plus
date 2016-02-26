#include <iostream>
#include <algorithm>   
#include <vector>

using namespace std;

const int SIZE =11;


void binarySearch(int a[], int target,int SIZE){
    int low=0, high=SIZE-1,mid;

    while(low<=high){
        mid=(low+high)/2;
        if(target<a[mid]){   //must be in lower half of array
            high=mid-1;
        }
        else if(target>a[mid]){ //must be in higher half of array
            low=mid+1;
        }
        else{
            cout<<"number found at index "<<mid-1<<endl;
            return;
        }
    }

    cout<<"did not find number!";

}



int main(){
    int numArray[]={2,6,0,7,1,3,5,4,8,9,23};


    cout<<"array before sorting: "<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<numArray[i]<<" ";
    }
    cout<<endl;

    sort(numArray,numArray+SIZE);

    cout<<"array after sorting: "<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<numArray[i]<<" ";
    }
    cout<<endl;

    binarySearch(numArray,23,SIZE);

}







