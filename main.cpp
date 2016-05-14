#include <cstdlib>
#include <iostream>
#include <vector>
#include "CreateNumber.h"
#include "Perceptron.h"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    int errors,time=0;
    CreateNumber matrix0,matrix1;
    Perceptron p;p.setWeights(0);
    matrix0.setMatrix(0);
    matrix1.setMatrix(3);
//    do{
//        errors=0;
//        time++;
//        errors+=p.train(matrix0);
//        errors+=p.train(matrix1);
//    }while(errors>0);
    for(int i=0;i<matrix1.rows;i++){
        for(int j=0;j<matrix1.columns;j++){
            cout<<matrix1.getMatrix()[i][j]<<" ";
        }
        cout<<endl;
    }
//    p.recognizeNumber(matrix1);
//    p.recognizeNumber(matrix0);
//    matrix0.setMatrix(5);
//    p.recognizeNumber(matrix0);
    return 0;
}


