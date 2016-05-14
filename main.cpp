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
    matrix1.setMatrix(1);
    do{
        errors=0;
        time++;
        errors+=p.train(matrix0);
        errors+=p.train(matrix1);
    }while(errors>0);
    cout<<time<<"\n";
    for(int i=0;i<matrix0.columns*matrix0.rows+1;++i)
        cout<<p.weights[i]<<" ";
    cout<<endl;
    p.recognizeNumber(matrix0);
    for(int i=0;i<matrix0.columns*matrix0.rows+1;++i)
        cout<<p.weights[i]<<" ";
    cout<<endl;
    p.recognizeNumber(matrix1);
    for(int i=0;i<matrix0.columns*matrix0.rows+1;++i)
        cout<<p.weights[i]<<" ";
    cout<<endl;
    return 0;
}


