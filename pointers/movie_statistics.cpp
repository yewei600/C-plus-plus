#include <iostream>
#include <stdlib.h>
#include <algorithm>


using namespace std;

//mode: the value most often occur
int getMode(const int*pArray,int s){



}

//median: the middle value
int getMedian(const int*pArray,int s){
    std::sort(pArray,pArray+s);

}


int main()
{
    int numSurveys;
    cout<<"How many students were surveyed?";
    cin>>numSurveys;

    int *data = new int[numSurveys];
    int total=0;
    for(int i=0;i<numSurveys;i++){
        cout<<"enter the number of movies student "<<i<<" saw:";
        cin>>*(data+i);
        total+=*(data+i);
    }
    return 0;

}
