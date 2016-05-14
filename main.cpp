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
    Perceptron p;
    p.setWeights(0);
    cout<<p.train(matrix,p.weights);
    return 0;
}


