#include <iostream>
#include <math.h>
#include <string>
#include <vector>


using namespace std;

/*
a class that reads and writes to an uninitialized array in O(1) time
*/

template <typename T,size_t N>
class Array{
private:
    T A[N];
    int P[N],S[N],t;

    const bool isValid(const size_t &i) {
        return (0<=P[i] && P[i]<t && S[P[i]]==i);
    }

public:
    int SIZE=N;
    Array(void): t(0){};
    const bool read(const size_t &i, T &v){
        if(isValid(i)){
            v=A[i];
            return true;
        }
        return false;
    }

    void write(const size_t &i, const T &v){
        if(!isValid(i)){
            S[t]=i;
            P[i]=t++;
        }
        A[i]=v;
    }
};

int main()
{
    Array<int,5> nArray;
    int val;

    for(int i=0;i<nArray.SIZE;i++){
        nArray.write(i,i+1);

        nArray.read(i,val);
        cout<<val<<" ";
    }

}
