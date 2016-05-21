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

void CreateNumber::distortMatrix(){
    int a;
    int sum=0,i,j,n=0;
    for (i = 0; i < this->rows; ++i) {
        #pragma omp parallel for reduction(+:sum) schedule(static)
            for (j = 0; j < this->columns; ++j) {
                if(this->matrix[i][j]==1)
                    sum +=1;
            }
        }
    n=rand()%sum+1;
    while(n>0){
        for(i=0;i<this->rows;++i){
            for(j=0;j<this->columns;++j){
                if(this->matrix[i][j]==1){
                    this->matrix[i][j]=0;
                    n--;
                    break;
                }
            }
            if(n==0)
                break;
            else if(i==this->rows)
                i=0;
        }
    }
}

void CreateNumber::createLetter(char letter){
    for(int i=0;i<this->rows;++i){
        #pragma omp parallel for
        for(int j=0;j<this->columns;++j)
            this->matrix[i][j]=0;
    }
    if(letter == 'T'){
        for(int j=0;j<this->columns;++j)
            this->matrix[0][j]=1;
        for(int i=0;i<this->rows;++i)
            this->matrix[i][this->columns/2]=1;
    }
    if(letter == 'C'){
        for(int i=1;i<this->columns;++i)
            this->matrix[0][i]=this->matrix[this->rows-1][i]=1;
        for(int i=1;i<this->rows-1;++i)
            this->matrix[i][0]=1;
    }
    if(letter == 'H'){
        for(int i=0;i<this->rows;++i){
            this->matrix[i][0]=this->matrix[i][this->columns-1]=1;
            if(i==this->rows/2){
                for(int j=0;j<this->columns;++j)
                    this->matrix[i][j]=1;
            }
        }
    }
    if(letter == 'E'){
        for(int i=0;i<this->rows;++i){
            if(i==(this->rows/2)-1||i==0||i==this->rows-1){
                for(int j=0;j<this->columns;++j)
                    this->matrix[i][j]=1;
            }
            this->matrix[i][0]=1;
        }
    }
    if(letter == 'A'){
        for(int i=0;i<this->rows;++i){
            if(i==1)
                this->matrix[i][1]=this->matrix[i][this->columns-2]=1;
            else if(i==0)
                this->matrix[i][this->columns/2]=1;
            else if(i==3){
                for(int j=0;j<this->columns;++j)
                    this->matrix[i][j]=1;
            }
            else
                this->matrix[i][0]=this->matrix[i][this->columns-1]=1;
        }
    }
    if(letter == 'N'){
        for(int i=this->rows/2;i<this->rows;++i)
            this->matrix[i][this->columns/2]=1;      
    }
}
