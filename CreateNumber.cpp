#include "CreateNumber.h"

void CreateNumber::setMatrix(int number) {
    int **newMatrix = new int*[this->rows]();
    this->number = number;
    for (int i = 0; i<this->rows; ++i) {
        newMatrix[i] = new int[this->columns]();
    }
    if (number == 0) {
        for (int i = 0; i<this->rows; ++i) {
            if (i == 0) {
                for (int j = 1; j<this->columns - 1; ++j) {
                    newMatrix[i][j] = 1;
                    newMatrix[i + this->rows - 1][j] = 1;
                }
            }
            if (i >= 1 && i < this->rows-1) {
                newMatrix[i][0] = 1;
                newMatrix[i][this->columns - 1] = 1;
            }
        }
    }
    if (number == 1) {
        for (int i = 0; i<this->rows; ++i) {
            if (i == 1)
                newMatrix[i][i] = 1;
            newMatrix[i][this->columns / 2] = 1;
            if (i == this->rows - 1)
                for (int j = 0; j<this->columns; ++j)
                    newMatrix[i][j] = 1;
        }
    }
    if (number == 2){
        for (int i = 0; i<this->rows; ++i) {
            if(i==0)
                for(int j=1;j<this->columns-1;++j)
                    newMatrix[i][j]=1;
            if(i==1){
                newMatrix[i][i]=1;
                newMatrix[i][this->columns-2]=1;
                newMatrix[i+1][this->columns-2]=1;
            }
            if(i==3){
                newMatrix[i][this->columns/2]=1;
            }
            if(i==4){
                newMatrix[i][1]=1;
            }
            if (i == this->rows - 1)
                for (int j = 0; j<this->columns; ++j)
                    newMatrix[i][j] = 1;
        }
    }
    if (number == 3){
        for(int i=1;i<this->columns;++i){
            newMatrix[this->rows-1][i] = newMatrix[0][i] = newMatrix[(this->rows/2)-1][i] = 1;
        }
        for(int i=0;i<this->rows;++i)
            newMatrix[i][this->columns-1]=1;
    }
    if (number == 4){
        for (int i = 0; i<this->rows-2; ++i) {
            newMatrix[i][0] = newMatrix[i][this->columns-2]= 1;
        }
        for(int i=0;i<this->columns-1;++i)
            newMatrix[this->rows/2][i] = 1;
        for(int i=this->rows-2;i<this->rows;++i)
            newMatrix[i][this->columns-2]=1;
    }
    if (number == 5){
        for (int i = 0; i<this->rows; ++i) {
            if(i==1)
                newMatrix[i][1]=1;
                
            if(i==(this->rows/2)-1)
                for (int j = 1; j<this->columns; ++j)
                    newMatrix[i][j] = 1;
            if (i == this->rows - 1)
                for (int j = 1; j<this->columns; ++j)
                    newMatrix[i][j] = newMatrix[0][j] = 1;
        }
        for(int i=this->rows/2;i<this->rows;++i)
            newMatrix[i][this->columns-1]=1;
    }

    this->matrix = newMatrix;
}

int **CreateNumber::getMatrix() {
    return this->matrix;
}

