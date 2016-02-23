#include <iostream>

using namespace std;

int main()
{
    char choice;
    int numHours;
    double costA,costB,costC;
    cout << "Package A: $9.95/month for 10 hours, additional hours $2/hour\n",
    cout <<"Package B: $14.95/month for 20 hours, additional hours $1/hour\n",
    cout <<"Package C: $19.95/month for unlimited hours\n" << endl;

    cout<<"which package did you choose? ";
    cin>>choice;
    cout<<"for how many hours used? ";
    cin>>numHours;

    cout<<"Your monthly bill is ";

    switch(choice){
    case 'a':
    case 'A':
        //cost A
        if(numHours>10)
            costA=9.95*10+2*(numHours-10);
        else
            costA=9.95*10;
        cout<<costA;
        break;
    case 'b':
    case 'B':
        if(numHours>20)
            costA=14.95*20+1*(numHours-20);
        else
            costA=14.95*20;
        cout<<costB;
        break;

    case 'c':
    case 'C':
        costC=19.95;
        cout<<costC;
        break;
    }
    return 0;
}
