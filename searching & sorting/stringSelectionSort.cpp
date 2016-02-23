#include <iostream>
#include <string>
using namespace std;

/*
selection sort on an array of strings
*/

int main()
{
    const int NUM_NAMES = 20, SIZE=10;
    char names[NUM_NAMES][SIZE] = {"Colin","Bill","Smith","Bart","Allen",
                                    "Jim","Griffin","Jim","Stamey","Marty",
                                    "Rose","Geri","Allison","Jeff","Looney",
                                    "Joe","Wolfe","Bill","James","Greg"};


	char minName[10];
    int minIndex;
    int i,j;

    for(i=0;i<NUM_NAMES;i++){
        minName=names[i][];
        minIndex = i;

        for(j=i+1;j<NUM_NAMES;j++){
            if(minName>names[j][]){
                minName=names[j][];
                minIndex=j;
            }
        }
        names[minIndex][]=names[i][];
        names[i][]=minName;
        cout<<names[i]<<" ";
    }



    return 0;
}
