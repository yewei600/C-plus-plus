#include <iostream>
#include <cstring>


using namespace std;


int wordCount(char *pStr){
    int i=0,cnt=0;
    while(*(pStr+i)!='\0'){
        if(*(pStr+i)==' '){
            cnt++;
        }
        i++;
    }
    return ++cnt;
}

int main()
{
    char str[100];
    cout<<"enter a string: ";
    cin.getline(str,100);

    cout<<"There are "<<wordCount(str)<<" words in the string you typed";
    return 0;

}
