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
    CreateNumber matrix;
    matrix.setMatrix(1);
    int **newMatrix = matrix.getMatrix();
    Perceptron p;
    p.setWeights(0);
    cout<<endl;
    for(int i=0;i<31;i++)
        std::cout<<p.weights[i]<<" ";
    return 0;
}


