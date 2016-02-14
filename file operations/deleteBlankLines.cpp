#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


using namespace std;


int main()
{
    int cnt=1;
    ifstream readFile;
    ofstream writeFile;
    string fileName;
    string buffer;
    cout<<"enter name of file: ";
    cin>>fileName;

    readFile.open(fileName.c_str(),ios::in);
    writeFile.open("spaceDeleted.txt",ios::out);

    if(readFile.fail()){
        cout<<"couldn't open file.";
        return 0;
    }

    while(!readFile.eof()){
        getline(readFile,buffer);
        if(buffer.length()!=0){
            writeFile<<buffer<<endl;
        }
    }

    readFile.close();
    writeFile.close();
    cout<<"operation done";

    return 0;

}