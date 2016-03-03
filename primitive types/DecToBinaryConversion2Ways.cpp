#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

/*
Convert a decimal number to its binary equivalent
*/

string intToBinary( unsigned long n )
{
    string result;
    do
    {
        result.push_back( '0' + (n & 1) );
    }
    while (n >>= 1);

    reverse( result.begin(), result.end() );
    return result;

}

int binaryToInt(const string &binNum)
{
    int result=0;

    for(int i=0; i<binNum.length(); i++)
    {
        result=(result<<1)+binNum[i]-'0';
    }

    return result;
}

int main()
{
    cout<<intToBinary(4)<<endl;

    cout<<binaryToInt("111");

}
