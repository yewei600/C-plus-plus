#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <iomanip>


/*
This is a Theater Seating program. The available features are summarized in the
menu once the program runs.
*/

using namespace std;

const int rows=15;
const int columns=30;
const int baseTicketPrice=10;


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
    cout<<"                        seats"<<endl;
    cout<<"           123456789012345678901234567890"<<endl;
    for(int i=0;i<15;i++){
        cout<<"Row "<<left<<setw(2)<<i+1<<"     ";     //row number LEFT JUSTIFIED so the seating matrix will line up
        for(int j=0;j<30;j++){
            cout<<dArray[i][j];
        }
        cout<<endl;
    }
    return;

}

void availableSeatsSummary(char dArray[][30]){
    cout<<"available seats:"<<endl;
    for(int i=0;i<15;i++){
        cout<<"Row "<<left<<setw(2)<<i+1<<":     ";
        for(int j=0;j<30;j++){
            if(dArray[i][j]=='*'){
                cout<<j+1<<"  ";
            }
        }
        cout<<endl<<endl<<endl;
    }


}


void purchaseSeats(char dArray[][30],int &totalSales){
    bool finished=false;
    int choice;
    int row,columns[2]; //column[2]: hold beginning and end of a range
    cout<<"Buying tickets..."<<endl;
    cout<<"*enter 0 to finish transcation at any time"<<endl;


    cout<<"enter 1 to buy a single ticket. 2 to buy multiple tickets: ";
    cin>>choice;

    cout<<"enter row number: ";
    cin>>row;

    //single ticket
    if(choice==1){
        cout<<"enter column number: ";
        cin>>columns[0];

        dArray[row-1][columns[0]-1]='#';
        totalSales+=row*baseTicketPrice;      //add to the total of ticket sales
    }
    //double ticket
    else if(choice==2){
        cout<<"enter beginning column number: ";
        cin>>columns[0];
        cout<<"enter ending column number: ";
        cin>>columns[1];

        for(int j=columns[0]-1;j<columns[1];j++){
            dArray[row-1][j]='#';
            totalSales+=row*baseTicketPrice;
        }
    }

    cout<<"total ticket sales thus far is "<<totalSales<<endl;

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
    int totalSales=0;

    char seatsChart[rows][columns];

    initSeats(seatsChart);

    while(true){
        printSeats(seatsChart);

        availableSeatsSummary(seatsChart);

        purchaseSeats(seatsChart,totalSales);

    }

    return 0;

}
