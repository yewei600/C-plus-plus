#include <iostream>
#include <string>
using namespace std;

/*
selection sort on an array of strings
*/


void selectionSort(string array[], int NUM_NAMES)
{
int startScan, minIndex;
string minValue;

for(startScan = 0; startScan < NUM_NAMES ; startScan++)
{
    minIndex = startScan;
    minValue = array[startScan];
    for(int index = startScan +1; index < NUM_NAMES; index++)
    {
        if (array[index] < minValue)
        {
            minValue = array[index];
            minIndex = index;
        }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
}
}

int main()
{
    const int NUM_NAMES = 20, SIZE=10;
    string names[NUM_NAMES] = {"Colin","Bill","Smith","Bart","Allen",
                                    "Jim","Griffin","Jim","Stamey","Marty",
                                    "Rose","Geri","Allison","Jeff","Looney",
                                    "Joe","Wolfe","Bill","James","Greg"};


    selectionSort(names,NUM_NAMES);

    for(int i=0;i<NUM_NAMES;i++){
        cout<<names[i]<<" ";
        if((i+1)%5==0)
            cout<<endl;
    }



    return 0;
}
