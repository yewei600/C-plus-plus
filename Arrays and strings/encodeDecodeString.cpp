#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

/*
run-length encoding and decoding functions. Assume the string
to be encoded consists of letters of the alphabet,
*/

string decoding(string s){
    int cnt=0;
    string ret;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            cnt=s[i]-'0';
        }
        else{
            ret.append(cnt,s[i]);
            cnt=0;
        }
    }
    return ret;
}

string encoding(string s){
    int cnt=1;
    stringstream ss;

    for(int i=1; i<s.size(); ++i){
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            ss<<cnt<<s[i-1];
            cnt=1;
        }
    }
    ss<<cnt<<s[s.size()-1];
    return ss.str();

}


int main()
{
    string encodeStr="aabbccc";
    cout<< encoding(encodeStr)<<endl;

    string decodeStr="3a2b";
    cout<<decoding(decodeStr);


}
