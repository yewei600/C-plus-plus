#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>


using namespace std;

/*
Implement conversions between integer and string.
*/

string intToString(int x)
{
    bool is_negative;
    if (x<0)
    {
        x=-1*x;
        is_negative=true;
    }
    else
    {
        is_negative=false;
    }

    string s;
    while(x)
    {
        s.push_back('0'+x%10);
        x/=10;
    }
    if(s.empty())
    {
        return {"0"};
    }
    if(is_negative)
    {
        s.push_back('-');
    }

    reverse(s.begin(),s.end());
    return s;

}

int stringToInt(const string s)
{
    bool is_negative = s[0]=='-';
    int x = 0;

    for(int i=is_negative; i<s.length(); i++)
    {
        if(isdigit(s[i]))
        {
            x=x*10+s[i]-'0';
        }
        else
        {
            throw invalid_argument("input not a number");
        }
    }

    return is_negative ? -x:x;

}


int main()
{
    cout<<intToString(-416)<<endl;
    cout<<stringToInt("647")<<endl;

    cout<<stringToInt("-416")<<endl;
    cout<<stringToInt("647")<<endl;

}
