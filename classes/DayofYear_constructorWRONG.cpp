
#include <iostream>
#include <string>

using namespace std;

class DayOfYear{
private:
    int dateNum;
    static string months[];
    static int daysInMonths[];


public:
    DayOfYear(string month,int days);
    void print();
    DayOfYear operator++(int);
    DayOfYear operator--(int);

};
//initialize the static variables
string DayOfYear::months[]={"Janurary","Feburary","March","April","May","June","July","August","September","October","November","December"};
int DayOfYear::daysInMonths[]={31,28,31,30,31,30,31,31,30,31,30,31};

//constructor
DayOfYear::DayOfYear(string monthStr,int days){
    dateNum=0;
    //dateNum+=months[0];

    for(int i=1;i<12;i++){
        if(monthStr!=months[i]){
            dateNum+=daysInMonths[i-1];
        }
        else{
            break;
        }
    }
    dateNum+=days;

}

void DayOfYear::print(){
    cout<<"day "<<dateNum<<endl;
}


int main()
{
    string monthInput;
    int daysInput;
    while(true){
    cout<<"please enter a month: ";
    cin>>monthInput;
    cout<<"please enter a day: ";
    cin>>daysInput;


    DayOfYear date(monthInput,daysInput);
    date.print();

    }
	return 0;
}
