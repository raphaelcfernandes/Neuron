#include <cstdlib>
#include <iostream>
#include <vector>
#include "CreateNumber.h"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    CreateNumber matrix;
    matrix.setMatrix(1);
    int **newMatrix = matrix.getMatrix();
    for(int i=0;i<6;++i){
        for(int j=0;j<5;++j){
            if(newMatrix[i][j]==1)
                cout<<'x'<<" ";
            else
                cout<<newMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


