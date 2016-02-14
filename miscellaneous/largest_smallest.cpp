#include <iostream>
#include <algorithm>
using namespace std;

//take 10 values in, and print largest and smallest values

int main()
{
    int i;
    int values[10];
    for(i=0;i<10;i++){
        cout<<"Enter value "<<(i+1)<<": ";
        cin>>values[i];
    }

    sort(values,values+10);

    cout<<"largest value is "<<values[9]<<endl;
    cout<<"smallest value is "<<values[0];

    return 0;
}
