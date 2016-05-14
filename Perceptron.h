#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include "CreateNumber.h"
#include <stdlib.h>
#include <time.h> 

class Perceptron{
private:
    int resultado; 
    int bias=1;    
public:
    double *weights;
    void setWeights(int choice);
    int getBias(){return this->bias;}
    void train(int **matrix, int *weights);
};

#endif
