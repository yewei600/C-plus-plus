#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

/*
implement function for reversing the words in a string.
*/

void reverse_words(string &input)
{
//reverse entire string
    reverse(input.begin(),input.end());

    int start=0, finish;
    while((finish=input.find(" ",start))!= string::npos)
    {
        reverse(input.begin()+start, input.begin()+finish);
        start=finish+1;
    }

    //reverse last word
    reverse(input.begin()+start, input.end());


}


int main()
{
    string str= "The right to bear arms shall not be infringed";

    reverse_words(str);

    cout<<str;


}
