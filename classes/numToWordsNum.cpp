#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;


class Numbers{
private:
    int number;
    static string oneToNine[]={"one","two","three","four","five","six","seven","eight","nine"};
    static string tenToNineteen[]={"ten","eleven","tweleve","thirteen","fourteen","sixteen","seventeen","eighteen","nineteen",""}

public:
    Numbers(int num){
        number=num;
    }
    //prints the English description of the object
    void print();


};

void Numbers::print(){
//find how many digits the number has
    char numCharArray[5];
    itoa(number,numCharArray,10);

    for(int i=0;i<5;i++){
        if(numCharArray[i]=='\0'){
            cout<<"There are "<<i<<" digits in the number"<<endl;
            break;
        }
    }

    //0th-10th : ten - ninety nine
    //
}

int main()
{
    int dollarAmt;
    cout<<"Please enter a dollar amount: ";
    cin>>dollarAmt;

    while(dollarAmt<0 ||dollarAmt>9999){
        cout<<"You've entered an invalid amount. try again\n";
        cout<<"Please enter a dollar amount: ";
        cin>>dollarAmt;
    }

    Numbers num(dollarAmt);
    num.print();



	return 0;
}
