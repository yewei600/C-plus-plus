#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


using namespace std;



// find the average number of words per sentence.
int numWords(string str){
    int i=0,cnt=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            cnt++;
        }
        i++;
    }
    return ++cnt;
}


int main()
{
    int lineCnt=0;
    int wordCnt=0;
    string line;
    ifstream read("text.txt");
    if(!read){
        cout<<"couldn't open file.";
        return 0;
    }

    cout<<"reading file..."<<endl;

    while(!read.eof()){
        getline(read,line);
        wordCnt+=numWords(line);
        lineCnt++;

        cout<<"line "<<lineCnt<<" had "<<numWords(line)<<" words"<<endl;
    }

    cout<<"on average, each setence had "<<wordCnt/lineCnt<<" words.";


    return 0;

}
