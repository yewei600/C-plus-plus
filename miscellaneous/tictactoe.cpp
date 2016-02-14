#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

//


bool displayBoard(char **a,int r,int c,int p){
     cout<<"here!"<<endl;
     int i,j;
     char x='x'; char o='o';
     if(p==1)
        *(*(a+r)+c)='x';
     else
        *(*(a+r)+c)='o';

     for(i=0;i<3;i++){
         for(j=0;j<3;j++){
            cout<<*(*(a+i)+j);
         }
         cout<<endl;
     }
}

int main()
{
    char **gboard;
   // std::fill(&gboard[0][0],&gboard[0][0]+sizeof(gboard),'*');
    bool gameOver = false;
    int i,j;
    int player=0;
    string pMove;

    while(!gameOver){
        cout<<"player "<<player<<" choose row and column number:";
        cin>>pMove;
        displayBoard(gboard,(int)pMove[0]-1,(int)pMove[1]-1,player+1);

        player ^=1;
    }




    return 0;
}
