#include "CreateNumber.h"

void **CreateNumber::setMatrix(int number){
    int **newMatrix=new int*[this->rows]();
    for(int i=0;i<this->rows;++i){
        newMatrix[i]=new int[this->columns]();
    }
    if(number==0)
        for(int i=0;i<this->rows;++i){
            if(i==0){
                for(int j=1;j<this->columns-1;++j){
                    newMatrix[i][j]=1;
                    newMatrix[i+5][j]=1;
                }
            }
            if(i>=1 && i<=4){
                newMatrix[i][0]=1;
                newMatrix[i][4]=1;
            }
        }
    if(number==1){
        for(int i=0;i<this->rows;++i){
            if(i==1)
                newMatrix[i][i]=1;
            newMatrix[i][5/2]=1;
            if(i==5)
                for(int j=0;j<this->columns;++j)
                    newMatrix[i][j]=1;
        }
    }

    this->matrix = newMatrix;
}

int **CreateNumber::getMatrix(){
    return this->matrix;
}

