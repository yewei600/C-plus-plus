#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


using namespace std;


int main()
{
    int cnt=1;
    fstream stream;
    string fileName;
    string buffer;
    cout<<"enter name of file: ";
    cin>>fileName;
    stream.open(fileName.c_str(),ios::in|ios::out);

    if(stream.fail()){
        cout<<"couldn't open file.";
        return 0;
    }

    while(!stream.eof()){
        getline(stream,buffer);
        if(buffer.length()==0){
            cout<<"line "<<cnt<<" is a blank line"<<endl;
        }
        cnt++;
    }

    stream.close();
    cout<<"operation done";

    return 0;

}
