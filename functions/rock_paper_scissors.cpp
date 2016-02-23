#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>


using namespace std;



int main(){

    int userChoice,computerChoice;
    int winner;
    string playChoice[]={"rock","paper","scissors"};


    while(true){
        srand(time(NULL));

        cout<<"Please choose a play:\n";
        cout<<"1.rock 2.paper 3.scissors\n";
        cout<<"enter 0 to quit game"<<endl;
        cin>>userChoice;

        if(userChoice==0){
            return 0;
        }

        computerChoice =1+rand()%3;

        cout<<"User: "<<playChoice[userChoice-1]<<endl;
        cout<<"Computer: "<<playChoice[computerChoice-1]<<endl;

        if(userChoice>computerChoice){
            if(userChoice==3 && computerChoice==1){
                cout<<"computer wins!";
            }
            else
                cout<<"user wins!";
        }

        else if(userChoice<computerChoice){
            if(userChoice==1 && computerChoice==3){
                cout<<"user wins!";
            }
            else
                cout<<"computer wins!";
        }

        else{
            cout<<"it's a tie.";
        }
        cout<<endl<<endl;
    }

    return 0;

}
