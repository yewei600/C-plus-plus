#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

/*
input a string s, specify a char to remove,
a char to be replaced by another char(both provided).
*/

string replace_and_remove(string s,char rmv, char rpl, char rplChar){
    int write_idx=0, rmv_cnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=rmv ){
            s[write_idx++]=s[i];
        }
        if(s[i]==rpl){
            rmv_cnt++;
        }
    }

    s.resize(write_idx+rmv_cnt);
    cout<<"s size is now "<<s.length()<<endl;
    int cur_idx=write_idx-1;

    while(cur_idx>=0){
        if(s[cur_idx]==rpl){
            s[write_idx--]=rplChar;
        }
        else{
            s[write_idx--]=s[cur_idx];
        }
        cur_idx--;
    }
    return s;
}




int main()
{

    string str="aaabbbccc";
    cout<<"original string is "<<str<<endl;

    //remove 'a', replace 'c' with 'w'
    string modStr=replace_and_remove(str,'a','c','w');

    cout<<"modified string is "<<modStr;

}
