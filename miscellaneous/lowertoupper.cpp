#include <iostream>
using namespace std;

//convert lower case letters to upper case

int main()
{
    char str[100];
    int i=0;
    cout<<"enter a string: ";
    cin>>str;

    while(str[i]!='\0'){
        if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-'a'+'A';
        }
        cout<<str[i++];
    }
    return 0;
}
