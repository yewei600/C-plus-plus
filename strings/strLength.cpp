#include <iostream>
#include <cstring>


using namespace std;


int strlength(char *pStr){
    int i=0;
    while(*(pStr+i)!='\0'){
        i++;
    }
    return i+1;
}

int main()
{
    char str[80];
    cout<<"enter a string: ";
    cin>>str;

    cout<<"There are "<<strlen(str)<<" letters in the string";

    return 0;

}
