#include <iostream>
#include <algorithm>
using namespace std;

//get rainfall data for 12 months, find total rainfall, average rainfall, and months with largest and smallest rainfall

int main()
{
    int i;
    double months[12];
    double total=0;
    int sm, lg;
    for(i=0;i<12;i++){
        cout<<"Enter rainfall for month "<<(i+1)<<": ";
        cin>>months[i];
        total+=months[i];
    }
    cout<<
    cout<<"\ntotal rainfall of the year is "<<total<<endl;
    cout<<"average monthly rainfall is "<<total/12<<endl;

    sm = 0; lg=0;

    for(i=0;i<12;i++){
        if(months[sm]>months[i]){
            sm=i;
        }
        if(months[lg]<months[i]){
            lg=i;
        }
    }

    cout<<"smallest rainfall happend in month "<<sm+1<<endl;
    cout<<"largest rainfall happend in month "<<lg+1;

    return 0;
}
