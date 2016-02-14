#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


using namespace std;


struct salesData{
    char divName[8];
    int quarter;
    double qrtSales;
};

//


int main()
{
    salesData sData={"",0,0.0};
    //string divNames[]={"East","West","North","South"};
    fstream stream("salesData.txt",ios::out|ios::binary);
    double buf;
    string divName;

    for(int i=0;i<4;i++){
        cout<<"quarter "<<i+1<<" data"<<endl;
        for(int j=0;j<4;j++){
            switch(j){
            case 0:
                divName="Eastfff";
                break;
            case 1:
                divName="Westfff";
                break;
            case 2:
                divName="Northff";
                break;
            case 3:
                divName="Southff";
                break;
            }
            cout<<"please enter the quarterly sales for division "<<divName<<" :";
            cin>>buf;

            strcpy(sData.divName,divName.c_str());
            sData.quarter=5;
            sData.qrtSales=6.0;


            stream.write(reinterpret_cast<char *>(&sData),sizeof(sData));
            //stream<<'\n';
        }
    }
    stream.close();

    return 0;

}
