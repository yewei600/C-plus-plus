#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>


/*
This is a Theater Seating program. The available features are summarized in the
menu once the program runs.
*/

using namespace std;

const int rows=15;
const int columns=30;


/*NOTE: passing a 2D array by reference, NO NEED FOR & operator
http://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
*/
void initSeats(char dArray [][30]){
    for(int i=0;i<15;i++){
        for(int j=0;j<30;j++){
            dArray[i][j]='*';
        }
    }
}


void printSeats(char dArray[][30]){
    cout<<"             seats\n";
    for(int i=0;i<(15+1);i++){     //added +1 for i and j to print the heading infos
        for(j=0;j<(30+1);j++){
            if(i=0){
                cout<<"
            }

        }
    }


}

void purchaseSeats(){

}

void displayMenu(){
    cout << "\n                MENU\n";
    cout << "-----------------------------------------\n";
    cout << "A) Display seat chart\n";
    cout << "B) Available seats summary\n";
    cout << "C) Choose seat\n";
    cout << "D) Total ticket sales\n";
    cout << "E) \n";
    cout << "F) \n";
    cout << "G) Exit the program\n\n";
    cout << "Enter your choice: ";

}

int main(){
    char seatsChart[rows][columns];

    initSeats(seatsChart);

     for(int i=0;i<15;i++){
        for(int j=0;j<30;j++){
            cout<<seatsChart[i][j];
        }
        cout<<endl;
    }

    return 0;

}
