#include <iostream>
#include <stdlib.h>

/*
A program that takes a 2-D array as input and does some
arithmetic on it.
*/



using namespace std;
const int ROW=30;
const int COLUMN=30;

void initArray(int da[][COLUMN],int& tot){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            da[i][j]=j+1;
            tot+=da[i][j];
            cout<<da[i][j];
        }
        cout<<endl;
    }
    
}

int getAverage(int tot, int row,int column){
    cout<<"average is "<< tot/(row*column)<<endl;
    
}

int getTotal(int tot){
    cout<<"total is "<<tot<<endl;
}

int getRowTotal(int da[][COLUMN],int row){
    int rowTot=0;
    for(int i=0;i<COLUMN;i++){
        rowTot+=da[row][i];
    }
    
    cout<<"row "<<row<<" has a total of "<<rowTot<<endl;
}


int getColumnTotal(int da[][COLUMN],int column){
    int colTot=0;
    for(int i=0;i<ROW;i++){
        colTot+=da[i][column];
    }
    
    cout<<"column "<<column<<" has a total of "<<colTot<<endl;
}

int getHighestInRow(int da[][COLUMN],int row){
    int highest=da[row][0];
    for(int i=1;i<COLUMN;i++){
        if(highest<da[row][i]){
            highest=da[row][i];
        }
    }
    cout<<"highest in row "<<row<<" is "<<highest<<endl;
}

int getLowestInRow(int da[][COLUMN],int row){
    int lowest=da[row][0];
    for(int i=1;i<COLUMN;i++){
        if(lowest>da[row][i]){
            lowest=da[row][i];
        }
    }
    cout<<"lowest in row "<<row<<" is "<<lowest<<endl;
}



int main(){
    int dArray[ROW][COLUMN];
    int total=0;
    
    initArray(dArray,total);
    
    getTotal(total);
    
    getAverage(total,ROW,COLUMN);
    
    getRowTotal(dArray,0);
    
    getColumnTotal(dArray,0);
    
    getHighestInRow(dArray,0);
    
    getLowestInRow(dArray,0);
    
}
