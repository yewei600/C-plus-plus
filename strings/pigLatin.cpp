#include <iostream>
#include <cstring>


using namespace std;



string pigLatin(string str){
    int len=str.length();
    string c(str,0,1);
    str.erase(0,1);
    str.append(c);
    str.append("AY");


    return str;
}

int main()
{
    string sentence,newS;
    string substring;
    int startIndex=0;
    cout<<"enter a sentence:";
    getline(cin,sentence);

    for(int i=0;i<sentence.length();i++){
        if(sentence[i]==' '||i==sentence.length()-1){
            if(sentence[i]==' ')
                substring=sentence.substr(startIndex,i-startIndex);
            else
                substring=sentence.substr(startIndex,i-startIndex+1);

            newS.append(pigLatin(substring));
            newS.append(" ");
            startIndex=i+1;
        }
    }

    cout<<newS;


    return 0;

}
