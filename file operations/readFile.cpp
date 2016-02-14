#include <iostream>
#include <string>
#include <fstream>


using namespace std;


int main()
{
    const int SIZE = 800;
    int cnt=0;
    string fileName;
    char input[SIZE];
    cout<<"enter the name of file: ";
    cin>>fileName;

    fstream fStream(fileName.c_str(),ios::in);
    if(!fStream){
        cout<<"error opening "<<fileName;
    }
    else{
        fStream.getline(input,SIZE);
        while(!fStream.eof()&&cnt<10){
            cout<<input<<endl;
            fStream.getline(input,SIZE);
            cnt++;
        }

        fStream.close();

    }

    return 0;

}
