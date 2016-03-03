#include <iostream>
#include <math.h>

using namespace std;

/*
given a 64 bit integer,the function swaps the bits at indices i & j.177
*/

int swapBits(int &num,int i,int j){
    if((num&(1<<i))!=(num&(1<<j))){
        num ^= (1<<i)|(1<<j);
    }

    return num;
}



int main(){
    unsigned long num = pow(2,5);
    cout<<swapBits(num,1,2);


}
