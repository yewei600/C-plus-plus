#include <iostream>
#include <string>

/*
modify input string like the following example:

"StopAndSmellTheRoses ---> Stop and smell the roses"
*/

using namespace std;

void wordSeparator(string s){
    string newStr;
    for(int i=0;i<s.length();i++){
        if(i==0){
            s.at(i)=toupper(s.at(i));
            newStr.append(s,i,1);
        }
        else{
            if(isupper(s[i])){
                newStr.append(" ");
                s[i]=tolower(s[i]);
                newStr.append(s,i,1);
            }
            else{
                newStr.append(s,i,1);
            }


        }


    }

    cout<<newStr;
}

int main()
{
    string wordStr;
    cout<<"Enter a string\n(no spaces between words,capitalize each word): ";
    getline(cin,wordStr);

   wordSeparator(wordStr);

    return 0;

}
