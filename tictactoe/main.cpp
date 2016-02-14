#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;



bool gameWon(char a[][3],int p){
    char c=(p==1)?'x':'o';
    //8 possibilities
    if(a[0][0]==a[0][1] and a[0][0]==a[0][2] and a[0][0]==c)
        return true;
    else if(a[1][0]==a[1][1] and a[1][0]==a[1][2] and a[1][0]==c)
        return true;
    else if(a[2][0]==a[2][1] and a[2][0]==a[2][2] and a[2][0]==c)
        return true;
    else if(a[0][0]==a[1][0] and a[0][0]==a[2][0] and a[0][0]==c)
        return true;
    else if(a[0][1]==a[1][1] and a[0][1]==a[2][1] and a[0][1]==c)
        return true;
    else if(a[0][2]==a[1][2] and a[0][2]==a[2][2] and a[0][2]==c)
        return true;
    else if(a[0][0]==a[1][1] and a[0][0]==a[2][2] and a[0][0]==c)
        return true;
    else if(a[0][2]==a[1][1] and a[0][2]==a[2][0] and a[0][2]==c)
        return true;

    return false;

}


bool displayBoard(char a[][3],int r,int c,int p,bool *gWon){

    int i,j;
    if(a[r][c]!='*'){
        cout<<"This spot already played. Please choose new spot"<<endl;
        return false;
    }

    else{
        if(p==1){
            a[r][c]='x';
            cout<<"changed element"<<a[r][c]<<endl;
        }
        else{
            a[r][c]='o';
            cout<<"changed element"<<a[r][c]<<endl;
        }


        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }

        if(gameWon(a,p)){
                    cout<<"game won by player "<<p;
                    *gWon=true;
                }

        return true;
    }
}

int main()
{
    char gboard[3][3];
    std::fill(&gboard[0][0],&gboard[0][0]+sizeof(gboard),'*');
    bool gameOver = false;
    int r,c;
    int player=0;
    string pMove;

    while(!gameOver){
        cout<<"player "<<player<<" choose row and column number:";
        cin>>pMove;
        r=pMove[0]-'0'-1;
        c=pMove[1]-'0'-1;

        if(r>=0 && r<3 && c>=0 && c<3){
            if(displayBoard(gboard,r,c,player+1,&gameOver)){
                player ^=1;
            }
        }
        else{
            cout<<"invalid row and column numbers. try again"<<endl;
        }

    }
    return 0;
}
