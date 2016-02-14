#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


using namespace std;

void encrypt(string &str){
    for(int i=0;i<str.length();i++){
        str[i]=str[i]+1;
    }

}

//taking each letter of original file and adding 1 to its ASCII value.

int main()
{
    ifstream rStream;
    ofstream wStream;
    string fileName,buffer;

    cout<<"enter name of file to encrypt: ";
    cin>>fileName;

    rStream.open(fileName.c_str());
    wStream.open("encryptedFile.txt");

    if(!rStream){
        cout<<"can't open file.";
        return 0;
    }

    while(!rStream.eof()){
        getline(rStream,buffer);
        encrypt(buffer);
        wStream<<buffer<<endl;
    }

    cout<<"encryption done!";

    return 0;

}
