#include <iostream>
#include <math.h>

using namespace std;

/*
computes the parity of a single 64-bit nonnegative integer
*/

short parity(unsigned long x){
    short result =0;
    while(x){
       result ^=(x&1);
        x>>=1;
    }
    return result;
}

short parity1()


int main(){
    unsigned long num = pow(2,2);
    cout<<parity(num);


}
