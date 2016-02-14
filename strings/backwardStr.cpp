#include <iostream>
#include <cstring>


using namespace std;


void printReverse(char *pStr,int s){
    while((pStr+s)!=pStr){
        cout<<pStr[s];
        s--;
    }
    cout<<pStr[0];
}

int main()
{
    char str[80];
    cout<<"enter a string: ";
    cin.getline(str,80);

    printReverse(str,strlen(str)-1);
    return 0;

}
