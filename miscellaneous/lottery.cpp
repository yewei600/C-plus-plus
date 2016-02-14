#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

//

int main()
{
    int lottery[5];
    int userGuess[5];
    int i, match=0;

    //initialize random seed
    srand(time(NULL));

    for(i=0;i<5;i++){
        cout<<"enter number "<<i+1<<": ";
        lottery[i]=rand()%10+1;
        cin>>userGuess[i];
    }
    sort(lottery,lottery+5);
    sort(userGuess,userGuess+5);

    cout<<"the winning numbers are: ";

    for(i=0;i<5;i++){
        if(lottery[i]==userGuess[i]){
            match++;
        }
        cout<<lottery[i]<<' ';
    }

    cout<<"\nyou had "<<match<<" matching numbers";

    return 0;
}
