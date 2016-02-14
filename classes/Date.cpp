#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Date{
private:
    int month;
    int day;
    int year;
    string strMonth[12]={"January", "February", "March", "April", "May",
  "June", "July", "August", "September", "October", "November", "December"};

public:
    Date(int m=0,int d=0,int y=0){
        month=m;
        day=d;
        year=y;
    }

    void printDate()const{
        cout<<month<<'/'<<day<<'/'<<year<<endl;
        cout<<strMonth[month-1]<<' '<<day<<','<<year<<endl;
        cout<<day<<' '<<strMonth[month-1]<<' '<<year<<endl;
    }
};

int main() {
    Date date(10,8,2005);

    date.printDate();
    return 0;
}
