
#include <iostream>
#include <string>

using namespace std;

class DayOfYear{
private:
    int dateNum;
    static string months[];
    static int daysInMonths[];


public:
    DayOfYear(int n){
        dateNum=n;
    }
    void print();
    DayOfYear operator++(int);
    DayOfYear operator--(int);

};

string DayOfYear::months[]={"Janurary","Feburary","March","April","May","June","July","August","September","October","November","December"};
int DayOfYear::daysInMonths[]={31,28,31,30,31,30,31,31,30,31,30,31};

void DayOfYear::print(){
    int mCounter=0;
    int tmp=dateNum;
    while(tmp>daysInMonths[mCounter]){
        tmp-=daysInMonths[mCounter];
        mCounter++;
    }

    cout<<months[mCounter]<<" "<<tmp<<endl;
}

DayOfYear DayOfYear::operator++(int){
    dateNum++;
    return dateNum;
}

DayOfYear DayOfYear::operator--(int){
    dateNum--;
    return dateNum;
}

int main()
{
    int number,choice;
    while(true){
    cout<<"please enter a number: ";
    cin>>number;

    DayOfYear date(number);
    date.print();

    cout<<"enter 1 to increment date, 2 to decrement date ";
    cin>>choice;
    if(choice==1 || choice==2){
        if(choice==1)
            date++;
        else
            date--;
        cout<<"date after modification:"<<endl;
        date.print();

    }


    }
	return 0;
}
