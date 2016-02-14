#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

void printDate(string s){
    int i;
    string newString;
    string buf1,buf2;
    string months[]={
   "January",
   "February",
   "March",
   "April",
   "May",
   "June",
   "July",
   "August",
   "September",
   "October",
   "November",
   "December"};

    newString.append(months[atoi(s.substr(0,2).c_str())-1]);
    newString.append(" ");
    if(s.substr(3,1)=="0")
        newString.append(s.substr(4,1));
    else
        newString.append(s.substr(3,2));
    newString.append(", ");
    newString.append(s.substr(6,4));
    newString.append(".");
    cout<<newString;
}

int main()
{
    string date;
    cout<<"Please enter a date(mm/dd/yyyy): ";
    getline(cin,date);

    printDate(date);

    return 0;

}
