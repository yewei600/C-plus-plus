#include <iostream>
#include <string>
#include <fstream>


using namespace std;


int main()
{
    const int SIZE=300000;
    int cnt=0;
    fstream stream;
    string fileName;
    char buffer[SIZE];
    cout<<"enter the name of file: ";
    cin>> fileName;

    stream.open(fileName.c_str(),ios::in|ios::out);

    if(!stream){
        cout<<"error opening "<<fileName;
    }
    else{
        stream.getline(buffer,SIZE);
        while(!stream.eof()){
            cout<<buffer<<endl;
            stream.getline(buffer,SIZE);
          //  cnt++;
        }
    }

    stream.close();

    return 0;

}