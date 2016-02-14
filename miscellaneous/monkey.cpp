#include <iostream>
#include <algorithm>
using namespace std;

//

int main()
{
    int monkey[3][7];
    int i,j;
    bool pos=false;
    int familyTot=0,least,greatest;

    for(i=0;i<3;i++){
        for(j=0;j<7;j++){
            while(!pos){
                cout<<"enter day "<<j+1<<" food amount for monkey "<<i+1<<" : ";
                cin>>monkey[i][j];
                if(monkey[i][j]<0){
                    cout<<"entered an invalid food amount. try again"<<endl;
                }
                else{
                    familyTot+=monkey[i][j];
                    break;
                }
            }


            if(i==0 and j==0){
                least=monkey[i][j];
                greatest = monkey[i][j];
            }
            else{
                if(monkey[i][j]<least){
                    least = monkey[i][j];
                }
                if(monkey[i][j]>greatest){
                    greatest = monkey[i][j];
                }
            }

        }
    }

    cout<<"\nREPORT"<<endl;
    cout<<"average amount of food eaten by the whole family is "<<familyTot/7<<endl;
    cout<<"least amount of food eaten by any one monkey is "<<least<<endl;
    cout<<"greatest amount of food eaten by any one monkey is "<<greatest;


    return 0;
}
