#include <iostream>
#include <math.h>
#include <string>
#include <vector>


using namespace std;

/*
Generate all primes between 1 and n
*/

vector<int> genPrimes1ToN(const int n){
    //number of primes 
    int s = floor(0.5* (n-3))+1;
    
    vector<int> primes;
    primes.push_back(2);
    vector<bool> is_prime(s,true);  //represents (2i+3) is prime or not
    
    for(int i=0;i<s;i++){
        
    }
}

int main()
{
    genPrimes1ToN(5);

}
